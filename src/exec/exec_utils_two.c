/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:49:09 by tgoudman          #+#    #+#             */
/*   Updated: 2025/03/05 16:28:57 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	search_infile_remake(t_bash *shell)
{
	int			check;
	int			index;
	int			i;

	i = -1;
	check = 0;
	index = 0;
	while (shell->line.group[++i] != NULL)
	{
		if (get_input(shell, &shell->line.group[i][1]) == 'i'
			|| get_input(shell, &shell->line.group[i][1]) == 'h')
			check = index;
		if (shell->line.group[i][0] == '|')
			index++;
	}
	if (check)
		return (check);
	else
		return (0);
}

char	get_input(t_bash *shell, char *str)
{
	char		file;
	t_lst_fd	*fd;

	file = 'n';
	fd = shell->line.lst_fd;
	if (!fd)
		return (file);
	while (fd)
	{
		if (ft_strcmp(fd->name, str) == 0)
			file = fd->type;
		fd = fd->next;
	}
	return (file);
}

int	get_fd_infile(t_bash *shell, char *str)
{
	t_lst_fd	*tmp;

	tmp = shell->line.lst_fd;
	if (!tmp)
		return (-1);
	while (tmp)
	{
		if (ft_strcmp(str, tmp->name) == 0)
		{
			if (tmp->type == 'i' || tmp->type == 'h')
				return (tmp->fd);
		}
		tmp = tmp->next;
	}
	return (-1);
}

char	*search_file_two(t_bash *shell, int index_cmd)
{
	char	*file;
	int		count;
	t_line	line;
	int		i;

	i = 0;
	count = 0;
	file = NULL;
	line = shell->line;
	while (line.group[i] != NULL && index_cmd > count)
	{
		if (line.group[i][0] == '|')
			count++;
		i++;
	}
	while (line.group[i] != NULL && line.group[i][0] != '|')
	{
		if (line.group[i][0] == '!')
			if (get_fd_infile(shell, &line.group[i][1]) >= 0)
				file = line.group[i];
		i++;
	}
	return (file);
}

int	search_pipe(t_bash *shell, int nbr)
{
	int	i;
	int	count;
(void)nbr;
	i = 0;
	count = 0;
	while (shell->line.group[i] != NULL)
	{
		if (shell->line.group[i][0] == '|')
			count++;
		i++;
	}
	return (count);
}
