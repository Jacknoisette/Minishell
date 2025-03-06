/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:33:07 by tgoudman          #+#    #+#             */
/*   Updated: 2025/03/06 11:03:15 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
int	no_command(t_bash *shell, int index);

//DEBUG printf("file is %s with index %d cmd 
//== %s\n", infile, index, shell->line.cmd[index].name);
// free_list_fd(shell->line.lst_fd);
void	launch_cmd(t_bash *shell, t_cmd cmd, int index)
{
	char	**env;
	char	*path;
	char	*outfile;
	int		cmd1 = no_command(shell, index);

	outfile = search_file(shell, index);
	if (outfile != NULL)
		redirect_fd(shell, outfile + 1);
	close_fd_heredocs(shell);
	if (cmd1 == -1)
	{
		dprintf(2,"pas de command\n");
		exit(0);
	}
	dprintf(2,"command is %s\n", shell->line.cmd[cmd1].name);
	path = get_path(shell, shell->line.cmd[cmd1].name);
	env = lst_to_tab(shell->lst_env);
	shell->prev_return = 0;
	if (execve(path, shell->line.cmd[cmd1].args, env) == -1)
	{
		ft_printf(2, "minishell: Command '%s' not found\n", cmd.name);
		call_free(shell);
		free_list_env(shell->lst_env);
		free_cmd_exec(env);
		shell->prev_return = 127;
		exit (127);
	}
}
int	no_command(t_bash *shell, int index)
{
	char **line;
	int	i;

	i = 0;
	line = shell->line.group;
	dprintf(2, "index is ============= %d\n", index);
	if (ft_atoi(line[i]) == index)
	{
		return ft_atoi(line[i]);
	}
	while (index && line[i] != NULL)
	{
		if (line[i][0] == '|' && line[i] != NULL)
			index--;
		++i;
	}
	dprintf(2, "line == %s\n", line[i]);
	while (line[i] != NULL && line[i][0] != '|')
	{
		if (line[i][0] != '|' && line[i][0] != '!')
		{
		dprintf(2, "line return == %s\n", line[i]);
			return (ft_atoi(line[i]));
		}
		++i;
	}
	return (-1);
}
int	do_pipe(t_bash *shell, int index, int old_fd, int *pipe_fd)
{
	pid_t	pid;
	char	*infile;

	infile = search_file_two(shell, index);
	pid = fork();
	if (pid == 0)
	{
		if (infile != NULL)
			redirect_fd_infile(shell, infile + 1);
		else if (old_fd)
		{
			dup2(old_fd, STDIN_FILENO);
			close(old_fd);
		}
		if (check_function(shell->line.cmd[index]) == 1)
			launch_builtins(shell, index, pipe_fd, old_fd);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		close(pipe_fd[0]);
		launch_cmd(shell, shell->line.cmd[index], index);
	}
	close(pipe_fd[1]);
	if (old_fd)
		close(old_fd);
	return (pipe_fd[0]);
}

int	init_execve(t_bash *shell)
{
	if (open_fds(shell) == -1)
		return (1);
	if (search_pipe(shell, 0) == FALSE)
	{
		if (check_cmds(shell) == 1)
		{
			close_fd(shell);
			return (0);
		}
	}
	if (shell->line.cmd_nbr == 1 && search_pipe(shell, 0) == FALSE)
		ft_command_one(shell, 0);
	else
		ft_execve(shell);
	close_fd(shell);
	return (0);
}

int	ft_execve(t_bash *shell)
{
	int		pipe_fd[2];
	pid_t	pid;
	int		i;
	int		old_fd;
	int nb_pipe = search_pipe(shell, 0);

	old_fd = 0;
	i = 0;
	while (i < nb_pipe)
	{
		dprintf(2, "nb pipe == %d i== %d\n", nb_pipe, i);
		pipe(pipe_fd);
		old_fd = do_pipe(shell, i, old_fd, pipe_fd);
		++i;
	}
	pid = fork();
	if (pid == 0)
	{
		dup2(pipe_fd[0], 0);
		close(pipe_fd[0]);
		launch_cmd(shell, shell->line.cmd[i], i);
	}
	ft_exit_signale(shell, pid);
	close(old_fd);
	return (0);
}

int	ft_command_one(t_bash *shell, int index)
{
	pid_t	pid;
	int		pipe[2];
	char	*infile;

	infile = search_infile(shell);
	pid = fork();
	if (pid == 0)
	{
		if (infile != NULL)
			redirect_fd_infile(shell, infile);
		if (check_function(shell->line.cmd[index]) == 1)
			launch_builtins(shell, 0, pipe, -1);
		launch_cmd(shell, shell->line.cmd[index], 0);
	}
	ft_exit_signale(shell, pid);
	waitpid(pid, NULL, 0);
	return (0);
}

// void print_open_fds(const char *where)
// {
// 	int	fd;

// 	fd = 0;
// 	while (fd < 10)
// 	{
// 		if (fcntl(fd, F_GETFD) != -1) 
// 			dprintf(2, "%s - FD %d is open (PID: %d)\n", where, fd, getpid());
// 		fd++;
// 	}
// }