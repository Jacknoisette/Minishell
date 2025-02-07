/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:19:30 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/07 15:24:35 by jdhallen         ###   ########.fr       */
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

void	free_list_arg(t_lst_arg **lst_arg)
{
	t_lst_arg	*tmp;

	while (*lst_arg)
	{
		tmp = *lst_arg;
		(*lst_arg) = (*lst_arg)->next;
		if (tmp->str != NULL)
			free(tmp->str);
		if (tmp != NULL)
			free(tmp);
	}
}

void free_char_arg(t_char_arg *arg)
{
	int	i;

	i = 0;
	if (arg == NULL)
		return ;
	while (arg[i].str != NULL)
	{
		free(arg[i++].str);
	}
	if (arg != NULL)
		free(arg);
}
