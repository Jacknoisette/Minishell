/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:34:59 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/24 15:21:19 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	break_case(t_info *info)
{
	t_lst_line	*line;

	line = create_new_node_line(ft_itoa(cmd_list_count(&info->cmd_list)));
	list_add_back_line(info->line_list, line);
	return (TRUE);
}

int	end_case(t_info *info)
{
	t_lst_line	*line;

	if (act_as_end_of_line(info->main_lst, &info->cmd_list,
			&info->tmp, info->pos) == TRUE)
	{
		line = create_new_node_line(ft_itoa(cmd_list_count(&info->cmd_list)));
		list_add_back_line(info->line_list, line);
	}
	return (TRUE);
}

int	pipe_case(t_info *info)
{
	t_lst_line	*line;

	if (act_is_bash_op(info->main_lst, &info->cmd_list,
			&info->tmp, info->pos) == BREAK)
		return (BREAK);
	line = create_new_node_line(ft_itoa(cmd_list_count(&info->cmd_list)));
	list_add_back_line(info->line_list, line);
	line = create_new_node_line(ft_strdup("|"));
	list_add_back_line(info->line_list, line);
	return (TRUE);
}

int	get_lst_cmd_core(t_info *info)
{
	int			res;

	info->res = search_bash_op(info->main_lst, &info->cmd_list,
			&info->tmp, info->pos);
	if (info->res == CONTINUE)
		return (CONTINUE);
	if (info->res == BREAK)
		return (break_case(info), BREAK);
	if (info->tmp->string[info->pos->j] == '\0')
		return (end_case(info), CONTINUE);
	else if (is_bash_op(info->tmp->string[info->pos->j], '|'))
	{
		if (pipe_case(info) == BREAK)
			return (BREAK);
	}
	else if (is_bash_op(info->tmp->string[info->pos->j], '!'))
	{
		res = fd_case(info);
		if (res == BREAK)
			return (BREAK);
		if (res == ERROR)
			return (ERROR);
	}
	return (TRUE);
}
