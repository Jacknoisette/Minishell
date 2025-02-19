/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_remake.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:41:26 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/19 15:12:06 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_char_arg *strcmddup(t_char_arg *source)
{
	t_char_arg *result;
	int		len;
	int		i;

	if (source == NULL)
		return (NULL);
	len = 0;
	// ft_printf(1,"SELLO %s\n", source[0].str);
	while (source[len].str != NULL)
		len++;
	result = malloc(sizeof(t_char_arg) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (source[i].str != NULL)
	{
		result[i].str = ft_strdup(source[i].str);
		ft_printf(1, "%s\n", source[i].str);
		result[i].is_space = source[i].is_space;
		i++;
	}
	result[i].str = NULL;
	return (result);
}

t_char_arg *strcmdjoin(t_char_arg *source, t_char_arg *dest)
{
	t_char_arg *result;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (source == NULL && dest == NULL)
		return (NULL);
	if (source == NULL)
		return (strcmddup(dest));
	if (dest == NULL)
		return (strcmddup(source));
	// ft_printf(1,"KELLO %s\n", source->str);
	while (source[i].str != NULL)
		i++;
	while (dest[len].str != NULL)
		len++;
	result = malloc(sizeof(t_char_arg) * (len + i + 1));
	if (!result)
		return (NULL);
	i = 0;
	len = 0;
	while (source[i].str != NULL)
	{
		result[i].str = ft_strdup(source[i].str);
		result[i].is_space = source[i].is_space;
		i++;
	}
	while (dest[len].str != NULL)
	{
		result[i + len].str = ft_strdup(dest[len].str);
		result[i + len].is_space = dest[len].is_space;
		len++;
	}
	result[i + len].str = NULL;
	free_char_arg(source);
	return (result);
}

int	combine_cmd(t_lst_line **line_list, t_lst_cmd **cmd_list,
			t_lst_line	**new_line_list, t_lst_cmd	**new_cmd_list)
{
	int	is_cmd;
	int	cmd_count;
	t_lst_line	*line_create;
	t_lst_line	*line_tmp;
	t_lst_cmd	*cmd_create;
	t_lst_cmd	*cmd_actual;
	t_char_arg	*cmd_tempo;

	cmd_actual = *cmd_list;
	is_cmd = FALSE;
	cmd_count = 0;
	cmd_tempo = NULL;
	line_tmp = *line_list;
	while (line_tmp != NULL)
	{
		// ft_printf(1, "line %s\n", line_tmp->param);
		if (is_cmd == FALSE && ft_isdigit(line_tmp->param[0]) == 1)
		{
			// ft_printf(1,"HELLO %s\n", cmd_actual->arg[0].str);
			is_cmd = TRUE;
			cmd_tempo = strcmddup(cmd_actual->arg);
			// for (int i = 0; cmd_tempo[i].str != NULL; i++)
			// 	ft_printf(1, "cmd_tempo[i].str %s\n", cmd_tempo[i].str);
			line_create = create_new_node_line(ft_itoa(cmd_count));
			list_add_back_line(new_line_list, line_create);
			cmd_count += 1;
			// ft_printf(1, "oekodkeof\n");
		}
		else if (is_cmd == TRUE && ft_isdigit(line_tmp->param[0]) == 1)
		{
			// ft_printf(1,"IELLO %s\n", cmd_actual->arg[0].str);
			cmd_actual = cmd_actual->next;
			cmd_tempo = strcmdjoin(cmd_tempo, cmd_actual->arg);
			if (cmd_tempo == NULL)
				return (ERROR);
		}
		else if (line_tmp->param[0] == '!')
		{
			// ft_printf(1,"FELLO %s\n", cmd_actual->arg[0].str);
			line_create = create_new_node_line(ft_strdup(line_tmp->param));
			list_add_back_line(new_line_list, line_create);
			// cmd_actual = cmd_actual->next;
		}
		else if (is_bash_op(line_tmp->param[0], '|') == 1)
		{
			// ft_printf(1,"PELLO %s\n", cmd_actual->arg[0].str);
			line_create = create_new_node_line(ft_strdup("|"));
			list_add_back_line(new_line_list, line_create);
			if (is_cmd == TRUE)
			{
				cmd_create = create_new_node_cmd(cmd_tempo);
				list_add_back_cmd(new_cmd_list, cmd_create);
				cmd_create = NULL;
				is_cmd = FALSE;
			}
			cmd_actual = cmd_actual->next;
		}
		line_tmp = line_tmp->next;
	}
	if (is_cmd == TRUE)
	{
		cmd_create = create_new_node_cmd(cmd_tempo);
		list_add_back_cmd(new_cmd_list, cmd_create);
		is_cmd = FALSE;
	}
	return (TRUE);
}

int	remake_line(t_lst_line **line_list, t_lst_cmd **cmd_list)
{
	t_lst_line	*new_line_list;
	t_lst_cmd	*new_cmd_list;
	
	new_line_list = NULL;
	new_cmd_list = NULL;
	if (combine_cmd(line_list, cmd_list, &new_line_list, &new_cmd_list) == ERROR)
		return (ERROR);
	// ft_printf(1, "_END_REMAKE_\n");
	free_list_line(line_list);
	free_list_cmd(cmd_list);
	*line_list = new_line_list;
	*cmd_list = new_cmd_list;
	return (TRUE);
}
