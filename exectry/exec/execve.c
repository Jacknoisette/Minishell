/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:33:07 by tgoudman          #+#    #+#             */
/*   Updated: 2025/03/06 13:48:38 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//DEBUG printf("file is %s with actual_cmd %d cmd 
//== %s\n", infile, actual_cmd, shell->line.cmd[actual_cmd].name);
// free_list_fd(shell->line.lst_fd);
void	launch_cmd(t_bash *shell, t_cmd cmd, int actual_cmd)
{
	char	**env;
	char	*path;
	// char	*outfile;
	// char	*infile;

	(void)actual_cmd;
	// ft_printf(1, "This is actual_cmd %i\n", actual_cmd);
	// infile = search_file_two(shell, actual_cmd);
	// if (infile != NULL)
	// 	redirect_fd_infile(shell, infile + 1);
	// outfile = search_file(shell, actual_cmd);
	// if (outfile != NULL)
	// 	redirect_fd(shell, outfile + 1);
	// close_fd_heredocs(shell);
	path = get_path(shell, cmd.name);
	env = lst_to_tab(shell->lst_env);
	shell->prev_return = 0;
	ft_printf(2, "hello World\n");
	dprintf(2, "cmd %s : Input %i, Output %i, Path %s\n", cmd.name, cmd.input, cmd.output, path);
	if (execve(path, cmd.args, env) == -1)
	{
		ft_printf(2, "minishell: Command '%s' not found\n", cmd.name);
		free_list_env(shell->lst_env);
		free_tab(env);
		free_tab(shell->line.group);
		free(path);
		shell->prev_return = 127;
		exit (127);
	}
}

// printf("signal PID = %d\n", WIFSIGNALED(status));
//if signal == 0 -> SUCCESS_fork
int	do_pipe(t_bash *shell, int actual_cmd, int old_fd, int *pipe_fd)
{
	shell->line.cmd[actual_cmd].input = old_fd;
	shell->line.cmd[actual_cmd].output = pipe_fd[1];
	ft_printf(1, "test1\n");
	if (search_redirection(shell, actual_cmd) == ERROR)
		return (ft_printf(1, "test2\n"), ERROR);
	ft_printf(1, "HELLO PARENT1\n");
	shell->line.child[actual_cmd] = fork();
	if (shell->line.child[actual_cmd] == 0)
	{
		if (redirect_fd(shell, actual_cmd) == ERROR)
			exit(-1);
		ft_printf(2, "LAGGY\n");
		close(pipe_fd[1]);
			close(pipe_fd[0]);
		if (check_builtins(shell->line.cmd[actual_cmd]) == 1)
			launch_builtins(shell, actual_cmd);
		else
			launch_cmd(shell, shell->line.cmd[actual_cmd], actual_cmd);
	}
	ft_printf(1, "HELLO PARENT2\n");
	close(pipe_fd[1]);
	if (old_fd)
		close(old_fd);
	return (pipe_fd[0]);
}

int	search_pipe(t_bash *shell, int nbr)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (shell->line.group[i] != NULL)
	{
		if (ft_atoi(shell->line.group[i]) == nbr)
		{
			while (shell->line.group[i] != NULL &&
				shell->line.group[i][0] != '|')
				i++;
			if (shell->line.group[i] == NULL)
				return (FALSE);
			if (shell->line.group[i][0] == '|')
				return (TRUE);
		}
		i++;
	}
	return (FALSE);
}


int	ft_execve(t_bash *shell)
{
	int		pipe_fd[2];
	int		status;
	int		i;
	int		old_fd;
	int		j;

	old_fd = 0;
	i = -1;
	shell->line.child = malloc((shell->line.cmd_nbr) * sizeof(pid_t));
	ft_printf(1, "EXEC\n");
	while (search_pipe(shell, ++i) == TRUE)
	{
		ft_printf(1, "%i\n", search_pipe(shell, i));
		pipe(pipe_fd);
		old_fd = do_pipe(shell, i, old_fd, pipe_fd);
		if (old_fd == -1)
			return (ERROR);
	}
	if (shell->line.child[i] == 0)
		do_pipe(shell, i, old_fd, pipe_fd);
	j = 0;
	while (j < i)
	{
		waitpid(shell->line.child[j], &status, 0);
		j++;
	}
	close(old_fd);
	return (0);
}

int	ft_command_one(t_bash *shell, int actual_cmd)
{
	pid_t	pid;

	if (search_redirection(shell, actual_cmd) == ERROR)
		return (ERROR);
	pid = fork();
	if (pid == 0)
	{
		if (redirect_fd(shell, actual_cmd) == ERROR)
			return (ERROR);
		if (check_builtins(shell->line.cmd[actual_cmd]) == 1)
			launch_builtins(shell, 0);
		else
			launch_cmd(shell, shell->line.cmd[actual_cmd], 0);
	}
	waitpid(pid, NULL, 0);
	return (0);
}

int	init_execve(t_bash *shell)
{
	if (open_fds(shell) == -1)
		return (1);
	if (search_pipe(shell, 0) == FALSE)
		if (check_cmds(shell) == 1)
		{
			close_fd(shell);
			return (0);
		}
	ft_printf(1, "EXEC %i \n", search_pipe(shell, 0));
	ft_printf(1, "EXEC %i \n", search_pipe(shell, 0));
	if (shell->line.cmd_nbr == 1 && search_pipe(shell, 0) == TRUE)
		ft_command_one(shell, 0);
	else
		ft_execve(shell);
	close_fd(shell);
	return (0);
}
