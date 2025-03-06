/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_fd_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:13:49 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/25 13:23:28 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_lst_fd(t_lst_var *main_lst, t_cmd_pos *pos,
			char *type, char **limit)
{
	t_lst_var	*tmp;
	char		*name;
	int			core_res;

	tmp = init_cmdfd(main_lst, pos);
	name = ft_strdup("");
	if (name == NULL)
		return (NULL);
	if (check_file_type(&tmp, pos, type) == BREAK)
		return (free(name), NULL);
	while (tmp != NULL)
	{
		core_res = get_lst_fd_core(&tmp, &name, pos);
		if (core_res == CONTINUE)
			continue ;
		if (core_res == BREAK)
			break ;
		tmp = tmp->next;
		if (tmp == NULL)
			break ;
		pos->i++;
	}
	end_of_func(limit, &name, type, pos);
	return (name);
}

int	fd_create(t_lst_var *main_lst, t_lst_fd	**fd_list, t_cmd_pos *pos)
{
	t_lst_fd	*fd;
	char		*name;
	char		type;
	char		*limit;

	name = get_lst_fd(main_lst, pos, &type, &limit);
	if (name == NULL)
		return (ERROR);
	fd = create_new_node_fd(name, type, limit);
	if (name != NULL)
		free(name);
	list_add_back_fd(fd_list, fd);
	return (TRUE);
}

int	act_is_fd(t_lst_var *main_lst, t_lst_fd **fd_list,
		t_lst_var **tmp, t_cmd_pos *pos)
{
	if (fd_create(main_lst, fd_list, pos) == ERROR)
		return (ERROR);
	while ((*tmp)->id < pos->i)
	{
		*tmp = (*tmp)->next;
		if (*tmp == NULL)
			return (BREAK);
	}
	if (is_bash_op((*tmp)->string[pos->j], '|') == 1)
		return (pos->j++, TRUE);
	if ((*tmp)->string[pos->j] == '\0')
	{
		*tmp = (*tmp)->next;
		if (*tmp == NULL)
			return (BREAK);
		pos->i++;
		pos->j = 0;
	}
	if (is_bash_op((*tmp)->string[pos->j], '|') == 1)
		return (pos->j++, TRUE);
	return (0);
}

int	exec_fd(t_lst_var *main_lst, t_lst_cmd **cmd_list,
		t_lst_var **tmp, t_cmd_pos *pos)
{
	exec_create(main_lst, cmd_list, pos);
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

//echo $USER<file1|echo $USER