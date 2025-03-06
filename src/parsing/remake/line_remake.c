/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_remake.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:41:26 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/25 10:44:21 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	combine_cmd_add_line(t_lst_line	**new_line_list, char *str)
{
	t_lst_line	*line_create;

	if (str == NULL)
		return (ERROR);
	line_create = create_new_node_line(str);
	list_add_back_line(new_line_list, line_create);
	return (TRUE);
}

int	combine_cmd(t_remake_line *object)
{
	t_lst_line	*line_tmp;
	t_lst_cmd	*cmd_actual;
	t_char_arg	*cmd_tempo;

	combine_cmd_init(object, &cmd_tempo, &cmd_actual, &line_tmp);
	while (line_tmp != NULL)
	{
		if (combine_cmd_core(object, &cmd_tempo, &cmd_actual,
				&line_tmp) == ERROR)
			return (ERROR);
	}
	return (combine_cmd_end_case(object, &cmd_tempo), TRUE);
}

int	remake_line(t_lst_line **line_list, t_lst_cmd **cmd_list)
{
	t_remake_line	object;

	object.line_list = line_list;
	object.cmd_list = cmd_list;
	object.new_line_list = malloc(sizeof(t_lst_line));
	object.new_cmd_list = malloc(sizeof(t_lst_cmd));
	if (!object.new_line_list || !object.new_cmd_list)
		return (ERROR);
	*object.new_line_list = NULL;
	*object.new_cmd_list = NULL;
	if (combine_cmd(&object) == ERROR)
		return (ERROR);
	if (*cmd_list != NULL)
		free_list_cmd(cmd_list);
	if (*line_list != NULL)
		free_list_line(line_list);
	*object.line_list = *object.new_line_list;
	*object.cmd_list = *object.new_cmd_list;
	free(object.new_line_list);
	free(object.new_cmd_list);
	return (TRUE);
}
