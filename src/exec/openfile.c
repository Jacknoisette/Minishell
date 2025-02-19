/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:59:26 by tgoudman          #+#    #+#             */
/*   Updated: 2025/02/13 11:26:32 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	redirect_fd(t_bash *shell, char *str)
{
	t_lst_fd	*tmp;

	tmp = shell->line.lst_fd;
	if (!tmp)
		return ;
	while (tmp)
	{
		if (ft_strcmp(str, tmp->name) == 0)
		{
			ft_printf(1, "%s\n", tmp->name);
			if (tmp->type == 'i' || tmp->type == 'h')
				dup2(tmp->fd, STDIN_FILENO);
			else
				dup2(tmp->fd, STDOUT_FILENO);
		}
		tmp = tmp->next;
	}
}

void	open_fds(t_bash *shell)
{
	t_lst_fd	*tmp;
	int			fd;

	tmp = shell->line.lst_fd;
	if (!tmp)
		return ;
	while (tmp)
	{
		fd = 0;
		if (tmp->type == 'h')
			ft_heredoc(tmp->name, tmp->limit);
		if (tmp->type == 'a')
		{
			fd = ft_append(tmp->name);
			tmp->fd = fd;
		}
		if (tmp->type == 'o')
			fd = ft_open_file(tmp->name, 1);
		if (tmp->type == 'i')
			fd = ft_open_file(tmp->name, 0);
		tmp->fd = fd;
		ft_printf(1, "%i\n", tmp->fd);
		tmp = tmp->next;
	}
}

int	ft_append(char *str)
{
	int	fd;

	fd = open(str, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd == -1)
	{
		printf("canno't open/creat %s\n", str);
		return (1);
	}
	return (fd);
}

int	ft_open_file(char *str, int file)
{
	int	fd;

	if (file == 1)
	{
		fd = open(str, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd == -1)
		{
			printf("canno't open/creat %s\n", str);
			return (1);
		}
		return (fd);
	}
	if (file == 0)
	{
		fd = open(str, O_RDONLY);
		if (fd == -1)
		{
			printf("%s : No such file or directory\n", str);
			return (1);
		}
		return (fd);
	}
	return (0);
}

void	close_fd(t_bash *shell)
{
	t_lst_fd	*lst;

	lst = shell->line.lst_fd;
	while (lst)
	{
		close(lst->fd);
		if (shell->line.lst_fd->type == 'h')
		{
			if (unlink(shell->line.lst_fd->name) == -1)
				ft_printf(2, "Erreur: canno't remove %s\n", lst->name);
		}
		lst = lst->next;
	}
}
