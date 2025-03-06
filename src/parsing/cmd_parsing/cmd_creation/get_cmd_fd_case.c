/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_fd_case.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:16:40 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/06 13:59:40 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	fd_update(t_info *info, t_lst_fd *fd_temp)
{
	t_lst_line	*line;

	line = create_new_node_line(ft_strjoin("!", fd_temp->name));
	list_add_back_line(info->line_list, line);
	info->pos->last_type = FILE;
	if (info->res == BREAK)
		return (BREAK);
	if (info->res == TRUE)
	{
		line = create_new_node_line(ft_strdup("|"));
		list_add_back_line(info->line_list, line);
		info->pos->last_type = PIPE;
		if (info->tmp->string[info->pos->j] == '\0')
		{
			info->tmp = info->tmp->next;
			info->pos->i++;
			info->pos->j = 0;
			info->pos->start_of_arg = info->pos->i;
			info->pos->start_of_char = info->pos->j;
		}
		else
			info->pos->start_of_char = info->pos->j;
	}
	return (info->pos->end_of_arg = info->pos->i,
		info->pos->end_of_char = info->pos->j, TRUE);
}

int	fd_case(t_info *info)
{
	t_lst_line	*line;
	t_lst_fd	*fd_temp;

	if (info->pos->i > 0 && is_bash_op(
			find_char(&info->main_lst, info->pos), '*') == 0)
	{
		if (exec_fd(info->main_lst, &info->cmd_list,
				&info->tmp, info->pos) == BREAK)
			return (BREAK);
		line = create_new_node_line(ft_itoa(cmd_list_count(&info->cmd_list)));
		list_add_back_line(info->line_list, line);
	}
	info->res = act_is_fd(info->main_lst, info->fd_list,
			&info->tmp, info->pos);
	if (info->res == ERROR)
		return (ERROR);
	fd_temp = *info->fd_list;
	if (fd_temp != NULL)
	{
		while (fd_temp->next != NULL)
			fd_temp = fd_temp->next;
	}
	if (fd_update(info, fd_temp) == BREAK)
		return (BREAK);
	return (TRUE);
}
