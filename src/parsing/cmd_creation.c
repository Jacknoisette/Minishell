/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:40:17 by jdhalv.l          #+#    #+#             */
/*   Updated: 2025/02/19 15:36:52 by jdhallen         ###   ########.fr       */
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

int	cmd_parsing(t_bash *shell, t_lst_var *main_lst)
{
	t_cmd_pos		pos;
	t_lst_cmd		*cmd_list;
	t_lst_line		*line_list;
	t_lst_fd		*fd_list;

	(void)shell;
	line_list = NULL;
	fd_list = NULL;
	pos.start_of_arg = 0;
	pos.start_of_char = 0;
	pos.end_of_arg = 0;
	pos.end_of_char = 0;
	pos.last_type = FALSE;
	pos.i = 0;
	pos.j = 0;
	cmd_list = get_lst_cmd(main_lst, &line_list, &fd_list, &pos);
	free_list_var(&main_lst);
	if (cmd_list == NULL)
		return (free_list_line(&line_list), ERROR);
	create_heredoc_name(&fd_list);
	// ft_printf_list_cmd(&cmd_list, 1);
	// ft_printf_list_line(&line_list, 1);
	// ft_printf_list_fd(&fd_list, 1);
	remake_line(&line_list, &cmd_list);
	// ft_printf_list_cmd(&cmd_list, 1);
	// ft_printf_list_line(&line_list, 1);
	// ft_printf_list_fd(&fd_list, 1);
	if (convert_lst_to_line(shell, &line_list, &cmd_list, &fd_list) == ERROR)
		return (free_list_line(&line_list), free_list_cmd(&cmd_list),
			free_list_fd(&fd_list), ERROR);
	return (free_list_cmd(&cmd_list), free_list_line(&line_list), 1);
}

// if (info.pos->i > 0 && is_bash_op(find_char(&info.main_lst, info.pos), '*') == 0)
			// {
			// 	if (exec_fd(info.main_lst, &info.cmd_list, &info.tmp, info.pos) == BREAK)
			// 		break ;
			// 	line = create_new_node_line(ft_itoa(cmd_list_count(&info.cmd_list)));
			// 	list_add_back_line(info.line_list, line);
			// }
			// info.res = act_is_fd(info.main_lst, info.fd_list, &info.tmp, info.pos);
			// if (info.res == ERROR)
			// 	return (NULL);
			// fd_temp = *info.fd_list;
			// if (fd_temp != NULL)
			// {
			// 	while (fd_temp->next != NULL)
			// 		fd_temp = fd_temp->next;
			// }
			// if (fd_update(&info, fd_temp) == BREAK)
			// 	break ;
			// line = create_new_node_line(ft_strdup(fd_temp->name));
			// list_add_back_line(info.line_list, line);
			// info.pos->last_type = FILE;
			// if (info.res == BREAK)
			// 	break ;
			// if (info.res == TRUE)
			// {
			// 	ft_printf(1, "hello good\n");
			// 	line = create_new_node_line(ft_strdup("|"));
			// 	list_add_back_line(info.line_list, line);
			// 	info.pos->last_type = PIPE;
			// 	if (info.tmp->string[info.pos->j] == '\0')
			// 	{
			// 		info.tmp = info.tmp->next;
			// 		info.pos->i++;
			// 		info.pos->j = 0;
			// 		info.pos->start_of_arg = info.pos->i;
			// 		info.pos->start_of_char = info.pos->j;
			// 	}
			// }
			// info.pos->end_of_arg = info.pos->i;
			// info.pos->end_of_char = info.pos->j;