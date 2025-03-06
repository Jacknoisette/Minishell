/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:40:17 by jdhalv.l          #+#    #+#             */
/*   Updated: 2025/02/27 13:37:57 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_lst_arg_core(t_lst_arg **arg_stack, t_lst_var *tmp, t_var *v)
{
	t_lst_arg	*arg_str;

	arg_str = create_new_node_arg(
			ft_substr(tmp->string, v->j, v->i - v->j));
	if (arg_str->str == NULL)
		return (ERROR);
	arg_str->is_space = tmp->is_space;
	list_add_back_arg(arg_stack, arg_str);
	return (TRUE);
}

t_char_arg	*get_lst_arg(t_lst_var *main_lst, t_cmd_pos *pos)
{
	t_lst_var	*tmp;
	t_lst_arg	*arg_stack;
	t_char_arg	*args;
	t_var		v;

	arg_stack = NULL;
	tmp = init_cmdarg(main_lst, pos, &v);
	while (tmp != NULL && tmp->id <= pos->end_of_arg)
	{
		move_pos_v(tmp, &v, pos);
		if (v.j == v.i && ft_strcmp(tmp->string, "") == 0)
			if (get_lst_arg_core(&arg_stack, tmp, &v) == ERROR)
				return (free_list_arg(&arg_stack), NULL);
		if (v.j < v.i)
			if (get_lst_arg_core(&arg_stack, tmp, &v) == ERROR)
				return (free_list_arg(&arg_stack), NULL);
		tmp = tmp->next;
		if (tmp == NULL)
			break ;
	}
	args = make_arg(arg_stack);
	return (free_list_arg(&arg_stack), args);
}

void	init_info(t_info *info, t_lst_var **main_lst,
			t_lst_line **line_list, t_lst_fd **fd_list)
{
	info->cmd_list = NULL;
	info->tmp = *main_lst;
	info->res = FALSE;
	info->line_list = line_list;
	info->main_lst = *main_lst;
	info->fd_list = fd_list;
}

t_lst_cmd	*get_lst_cmd(t_lst_var *main_lst, t_lst_line **line_list,
				t_lst_fd **fd_list, t_cmd_pos *pos)
{
	t_info		info;
	int			res;

	init_info(&info, &main_lst, line_list, fd_list);
	info.pos = pos;
	if (check_cmd(&info.main_lst) == ERROR)
		return (NULL);
	while (info.tmp != NULL)
	{
		res = get_lst_cmd_core(&info);
		if (res == CONTINUE)
			continue ;
		if (res == BREAK)
			break ;
		if (res == ERROR)
			return (NULL);
	}
	if (info.cmd_list == NULL)
		null_lst_cmd(&info.cmd_list);
	return (info.cmd_list);
}

