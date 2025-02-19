/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:33:07 by tgoudman          #+#    #+#             */
/*   Updated: 2025/02/13 11:11:50 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	launch_cmd(t_bash *shell, t_cmd cmd, int index)
{
	char	**env;
	char	*path;
	char	*file;

	path = get_path(cmd.name);
	env = lst_to_tab(shell->lst_env);
	file = search_file(&shell->line, index);
	if (file != NULL)
		redirect_fd(shell, file + 1);
	if (execve(path, cmd.args, env) == -1)
	{
		ft_putendl_fd("command not found: ", 2);
		ft_putendl_fd(cmd.name, 2);
		free_cmd(cmd.args);
		free_cmd(env);
		return (1);
	}
	free_cmd(env);
	free_cmd(cmd.args);
	return (0);
}

// printf("signal PID = %d\n", WIFSIGNALED(status));
//if signal == 0 -> SUCCESS_fork
void	do_pipe(t_bash *shell, t_cmd cmd, int index)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
	{
		ft_putendl_fd("pipe failed\n", 2);
		exit (1);
	}
	pid = fork();
	if (!pid)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		launch_cmd(shell, cmd, index);
	}
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], 0);
		waitpid(pid, NULL, 0);
	}
}

int	init_execve(t_bash *shell)
{
	pid_t	pid;

	printf("no segmentation fault detected\n");
	open_fds(shell);
	pid = fork();
	if (pid == -1)
	{
		printf("fork failed\n");
		return (1);
	}
	if (!pid)
		ft_execve(shell);
	else
		waitpid(pid, NULL, 0);
	close_fd(shell);
	return (0);
}

int	ft_execve(t_bash *shell)
{
	t_cmd	*cmd;
	int		i;

	i = 0;
	cmd = shell->line.cmd;
	if (shell->line.cmd->input != 0)
		dup2(shell->line.cmd->input, STDIN_FILENO);
	while (shell->line.cmd_nbr > 1)
	{
		do_pipe(shell, cmd[i], i);
		shell->line.cmd_nbr--;
		++i;
	}
	if (shell->line.cmd->output != 1)
		dup2(shell->line.cmd->output, STDOUT_FILENO);
	launch_cmd(shell, cmd[i], i);
	return (0);
}
