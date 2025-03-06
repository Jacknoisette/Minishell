/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:49:09 by tgoudman          #+#    #+#             */
/*   Updated: 2025/03/03 12:52:47 by tgoudman         ###   ########.fr       */
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
