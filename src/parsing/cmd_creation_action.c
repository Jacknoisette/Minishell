/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_creation_action.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:12:14 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/07 12:07:15 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exec_create(t_lst_var *main_lst, t_lst_cmd	**cmd_list, t_cmd_pos *pos)
{
	t_lst_cmd	*cmd;
	t_char_arg 	*arg;

	pos->end_of_arg = pos->i;
	pos->end_of_char = pos->j;
	arg = get_lst_arg(main_lst, pos);
	if (arg == NULL)
		return ;
	for (int i = 0; arg[i].str != NULL; i++)
		ft_printf(1, "%s ", arg[i].str);
	ft_printf(1, "\n");
	cmd = create_new_node_cmd(arg);
	ft_printf(1, "hello\n");
	list_add_back_cmd(cmd_list, cmd);
}

int	search_bash_op(t_lst_var *main_lst, t_lst_cmd **cmd_list,
		t_lst_var **tmp, t_cmd_pos *pos)
{
	ft_printf(1, "string in [%i] : \033[34m \033[4m%s\n\033[0m", pos->i, (*tmp)->string);
	if ((*tmp)->is_squote != FALSE)
	{
		pos->j = ft_strlen((*tmp)->string);
		*tmp = (*tmp)->next;
		if (*tmp == NULL)
		{
			exec_create(main_lst, cmd_list, pos);
			pos->last_type = CMD;
		}
		pos->i++;
		pos->j = 0;
		return (CONTINUE);
	}
	while ((*tmp)->string[pos->j] != '\0' && is_bash_op((*tmp)->string[pos->j], '*') == 0)
		pos->j++;
	return (GO_ON);
}

int	act_as_end_of_line(t_lst_var *main_lst, t_lst_cmd **cmd_list,
		t_lst_var **tmp, t_cmd_pos *pos)
{
	*tmp = (*tmp)->next;
	if (*tmp == NULL)
	{
		ft_printf(1, "__\033[35m\033[5mEND\033[0m__\n");
		exec_create(main_lst, cmd_list, pos);
		pos->last_type = CMD;
		pos->i++;
		pos->j = 0;
		return (TRUE);
	}
	pos->i++;
	pos->j = 0;
	return (FALSE);
}

int	act_is_bash_op(t_lst_var *main_lst, t_lst_cmd **cmd_list,
		t_lst_var **tmp, t_cmd_pos *pos)
{
	exec_create(main_lst, cmd_list, pos);
	pos->last_type = CMD;
	pos->j++;
	if ((*tmp)->string[pos->j] == '\0')
	{
		*tmp = (*tmp)->next;
		if (*tmp == NULL)
			return (BREAK) ;
		pos->i++;
		pos->j = 0;
	}
	pos->start_of_arg = pos->i;
	pos->start_of_char = pos->j;
	ft_printf(1, "aibo : %c\n", (*tmp)->string[pos->j]);
	return (GO_ON);
}

