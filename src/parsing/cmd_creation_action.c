/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_creation_action.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:12:14 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/14 15:14:49 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_bash_op(char chr, char mod)
{
	if (mod == '|' && (chr == '|'))
		return (TRUE);
	else if (mod == '!' && (chr == '<' || chr == '>'))
		return (TRUE);
	else if (mod == '*' && (chr == '|' || chr == '<' || chr == '>'))
		return (TRUE);
	return (FALSE);
}

void	exec_create(t_lst_var *main_lst, t_lst_cmd	**cmd_list, t_cmd_pos *pos)
{
	t_char_arg	*arg;
	t_lst_cmd	*cmd;

	pos->end_of_arg = pos->i;
	pos->end_of_char = pos->j;
	arg = get_lst_arg(main_lst, pos);
	if (arg == NULL)
		return ;
	cmd = create_new_node_cmd(arg);
	list_add_back_cmd(cmd_list, cmd);
	pos->last_type = CMD;
}

int	search_bash_op(t_lst_var *main_lst, t_lst_cmd **cmd_list,
		t_lst_var **tmp, t_cmd_pos *pos)
{
	if ((*tmp)->is_squote != FALSE)
	{
		pos->j = ft_strlen((*tmp)->string);
		*tmp = (*tmp)->next;
		if (*tmp == NULL)
		{
			// ft_printf(1, "__\033[35m\033[5mFINAL\033[0m__\n");
			exec_create(main_lst, cmd_list, pos);
			pos->start_of_arg = pos->i;
			pos->start_of_char = pos->j;
			pos->last_type = CMD;
			return (BREAK);
		}
		// ft_printf(1, "__\033[35m\033[5m\\0:sap\033[0m__\n");
		pos->i++;
		pos->j = 0;
		return (CONTINUE);
	}
	while ((*tmp)->string[pos->j] != '\0'
		&& is_bash_op((*tmp)->string[pos->j], '*') == 0)
		pos->j++;
	return (GO_ON);
}

int	act_as_end_of_line(t_lst_var *main_lst, t_lst_cmd **cmd_list,
		t_lst_var **tmp, t_cmd_pos *pos)
{
	*tmp = (*tmp)->next;
	if (*tmp == NULL)
	{
		if (!(pos->start_of_arg == pos->i && pos->start_of_char == pos->j))
		{
			// ft_printf(1, "__\033[35m\033[5mEND\033[0m__\n");
			exec_create(main_lst, cmd_list, pos);
			pos->i++;
			pos->j = 0;
			return (TRUE);
		}
	}
	// ft_printf(1, "__\033[35m\033[5m\\0:eol\033[0m__\n");
	pos->i++;
	pos->j = 0;
	return (FALSE);
}

int	act_is_bash_op(t_lst_var *main_lst, t_lst_cmd **cmd_list,
		t_lst_var **tmp, t_cmd_pos *pos)
{
	exec_create(main_lst, cmd_list, pos);
	pos->j++;
	if ((*tmp)->string[pos->j] == '\0')
	{
		*tmp = (*tmp)->next;
		if (*tmp == NULL)
			return (BREAK);
		pos->i++;
		pos->j = 0;
	}
	pos->start_of_arg = pos->i;
	pos->start_of_char = pos->j;
	return (GO_ON);
}
