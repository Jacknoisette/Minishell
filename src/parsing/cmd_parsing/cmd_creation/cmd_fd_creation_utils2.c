/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_fd_creation_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:36:14 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/24 14:39:46 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_lst_break_case(t_lst_var **tmp, char **name, t_cmd_pos *pos)
{
	if ((*tmp)->next != NULL)
	{
		if ((*tmp)->is_space == 1)
		{
			(*tmp) = (*tmp)->next;
			return (pos->i++, pos->j = 0, BREAK);
		}
		if ((*tmp)->next->is_squote != FALSE)
		{
			pos->j = 0;
			pos->i++;
			(*tmp) = (*tmp)->next;
			*name = join_temp_to_name(name, (*tmp)->string, pos, 1);
			if ((*tmp)->is_space == 1)
				return (pos->i++, pos->j = 0, BREAK);
		}
	}
	return (TRUE);
}

int	get_lst_fd_core(t_lst_var **tmp, char **name, t_cmd_pos *pos)
{
	if ((*tmp)->is_squote != FALSE && ft_strcmp("", (*tmp)->string) == 0)
		return ((*tmp) = (*tmp)->next, *name = ft_strdup(""),
			pos->i++, pos->j = 0, BREAK);
	if ((*tmp)->is_squote != FALSE)
	{
		*name = join_temp_to_name(name, (*tmp)->string, pos, 1);
		(*tmp) = (*tmp)->next;
		return (pos->i++, pos->j = 0, CONTINUE);
	}
	if (pos->j > 0 && is_bash_op((*tmp)->string[pos->j - 1], '!') == 0)
		pos->j = 0;
	while ((*tmp)->string[pos->j] != '\0'
		&& is_bash_op((*tmp)->string[pos->j], '*') == 0)
	{
		*name = join_temp_to_name(name, (*tmp)->string, pos, 2);
		pos->j++;
	}
	if (is_bash_op((*tmp)->string[pos->j], '|') == TRUE)
		return (BREAK);
	if (get_lst_break_case(tmp, name, pos) == BREAK)
		return (BREAK);
	return (TRUE);
}
