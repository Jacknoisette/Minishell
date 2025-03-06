/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:49:13 by tgoudman          #+#    #+#             */
/*   Updated: 2025/03/04 17:07:59 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_heredocs(t_bash *shell)
{
	int		fd;
	char	*name;

	name = handle_multiple_heredocs(shell);
	if (name == NULL)
		return ;
	fd = open(name, O_RDONLY);
	dup2(fd, STDIN_FILENO);
	close(fd);
	ft_execve_heredocs(shell, name);
	close_fd(shell);
}

int	ft_heredoc(char *del, char *str)
{
	char	*input;
	int		fd;

	fd = open(str, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd == -1)
		return (perror("Erreur lors de l'ouverture du fichier"), -1);
	while (1)
	{
		input = readline("heredoc> ");
		if (!input)
		{
			printf("here-document delimited by end-of-file (wanted `%s')\n",
				del);
			break ;
		}
		if (strcmp(input, del) == 0)
		{
			free(input);
			break ;
		}
		ft_printf(fd, "%s\n", input);
		free(input);
	}
	close(fd);
	return (fd);
}

char	*handle_multiple_heredocs(t_bash *shell)
{
	t_lst_fd	*lst;
	char		*name;
	int			fd;

	fd = -1;
	lst = shell->line.lst_fd;
	name = NULL;
	while (lst)
	{
		if (lst->type == 'h')
		{
			fd = ft_heredoc(lst->limit, lst->name);
			name = lst->name;
		}
		lst = lst->next;
	}
	if (fd != -1)
		close(fd);
	return (name);
}

int	get_cmd(t_bash	*shell, char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (shell->line.group[i] != NULL)
	{
		if (shell->line.group[i][0] == '|')
			++count;
		if (ft_strcmp(shell->line.group[i] + 1, str) == 0)
			return (count);
		i++;
	}
	return (count);
}

// printf("execute cmd = %s nb cmd = %d fd = %d file = %s\n", 
// shell->line.cmd[i].name, shell->line.cmd_nbr, fd, str);
void	ft_execve_heredocs(t_bash *shell, char *str)
{
	int		i;
	int		pipe_fd[2];

	i = get_cmd(shell, str) - 1;
	if (pipe(pipe_fd) == -1)
		return (ft_putendl_fd("pipe failed\n", 2));
	while (++i < shell->line.cmd_nbr -1)
	{
		if (fork() == 0)
		{
			close_fd_heredocs(shell);
			close(pipe_fd[0]);
			dup2(pipe_fd[1], STDOUT_FILENO);
			close(pipe_fd[1]);
		}
		else
		{
			wait(NULL);
			close(pipe_fd[1]);
			dup2(pipe_fd[0], 0);
			close(pipe_fd[0]);
		}
	}
}
