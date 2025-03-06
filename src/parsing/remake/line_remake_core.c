/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_remake_core.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:36:21 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/24 15:33:24 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	combine_cmd_digit_case(t_remake_line *object, t_lst_cmd **cmd_actual,
		t_char_arg **cmd_tempo)
{
	if (object->is_cmd == FALSE)
	{
		object->is_cmd = TRUE;
		*cmd_tempo = strcmddup((*cmd_actual)->arg);
		if (combine_cmd_add_line(object->new_line_list,
				ft_itoa(object->cmd_count)) == ERROR)
			return (ERROR);
		object->cmd_count += 1;
	}
	else if (object->is_cmd == TRUE)
	{
		(*cmd_actual) = (*cmd_actual)->next;
		*cmd_tempo = strcmdjoin(*cmd_tempo, (*cmd_actual)->arg);
		if (*cmd_tempo == NULL)
			return (ERROR);
	}
	return (TRUE);
}

int	combine_cmd_pipe_case(t_remake_line *object, t_char_arg **cmd_tempo,
		t_lst_cmd **cmd_actual)
{
	t_lst_line	*line_create;
	t_lst_cmd	*cmd_create;

	line_create = create_new_node_line(ft_strdup("|"));
	list_add_back_line(object->new_line_list, line_create);
	if (object->is_cmd == TRUE)
	{
		cmd_create = create_new_node_cmd(*cmd_tempo);
		list_add_back_cmd(object->new_cmd_list, cmd_create);
		object->is_cmd = FALSE;
		*cmd_actual = (*cmd_actual)->next;
	}
	return (TRUE);
}

int	combine_cmd_end_case(t_remake_line *object, t_char_arg **cmd_tempo)
{
	t_lst_cmd	*cmd_create;

	if (object->is_cmd == TRUE)
	{
		cmd_create = create_new_node_cmd(*cmd_tempo);
		list_add_back_cmd(object->new_cmd_list, cmd_create);
		object->is_cmd = FALSE;
	}
	return (TRUE);
}

int	combine_cmd_init(t_remake_line *object, t_char_arg **cmd_tempo,
	t_lst_cmd **cmd_actual, t_lst_line **line_tmp)
{
	object->is_cmd = FALSE;
	object->cmd_count = 0;
	*cmd_tempo = NULL;
	*cmd_actual = *object->cmd_list;
	*line_tmp = *object->line_list;
	return (TRUE);
}

int	combine_cmd_core(t_remake_line *object, t_char_arg **cmd_tempo,
	t_lst_cmd **cmd_actual, t_lst_line **line_tmp)
{
	if (ft_isdigit((*line_tmp)->param[0]) == 1)
	{
		if (combine_cmd_digit_case(object, cmd_actual, cmd_tempo) == ERROR)
			return (ERROR);
	}
	else if ((*line_tmp)->param[0] == '!')
	{
		if (combine_cmd_add_line(object->new_line_list,
				ft_strdup((*line_tmp)->param)) == ERROR)
			return (ERROR);
	}
	else if (is_bash_op((*line_tmp)->param[0], '|') == 1)
	{
		combine_cmd_pipe_case(object, cmd_tempo, cmd_actual);
	}
	*line_tmp = (*line_tmp)->next;
	return (TRUE);
}
