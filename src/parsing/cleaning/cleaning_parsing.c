/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:19:30 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/25 10:54:26 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_list_var(t_lst_var **lst_var)
{
	t_lst_var	*tmp;

	while (*lst_var)
	{
		tmp = *lst_var;
		(*lst_var) = (*lst_var)->next;
		if (tmp->string != NULL)
			free(tmp->string);
		if (tmp != NULL)
			free(tmp);
	}
	*lst_var = NULL;
}

void	free_list_cmd(t_lst_cmd **lst_cmd)
{
	t_lst_cmd	*tmp;

	while (*lst_cmd)
	{
		tmp = *lst_cmd;
		(*lst_cmd) = (*lst_cmd)->next;
		if (tmp->arg != NULL)
			free_char_arg(tmp->arg);
		if (tmp != NULL)
			free(tmp);
	}
	*lst_cmd = NULL;
}

void	free_list_fd(t_lst_fd **lst_fd)
{
	t_lst_fd	*tmp;

	while (*lst_fd)
	{
		tmp = *lst_fd;
		(*lst_fd) = (*lst_fd)->next;
		if (tmp->name != NULL)
			free(tmp->name);
		if (tmp->limit != NULL)
			free(tmp->limit);
		if (tmp != NULL)
			free(tmp);
	}
	*lst_fd = NULL;
}

void	free_list_line(t_lst_line **lst_line)
{
	t_lst_line	*tmp;

	while (*lst_line)
	{
		tmp = *lst_line;
		(*lst_line) = (*lst_line)->next;
		if (tmp->param != NULL)
			free(tmp->param);
		if (tmp != NULL)
			free(tmp);
	}
	*lst_line = NULL;
}

void	free_list_point(t_lst_var ***lst_var, int len)
{
	t_lst_var	*tmp;
	int			i;

	i = 0;
	while (i < len)
	{
		while ((*lst_var)[i] != NULL)
		{
			tmp = (*lst_var)[i];
			(*lst_var)[i] = (*lst_var)[i]->next;
			if (tmp->string != NULL)
				free(tmp->string);
			if (tmp != NULL)
				free(tmp);
		}
		i++;
	}
	if (*lst_var != NULL)
		free(*lst_var);
}
