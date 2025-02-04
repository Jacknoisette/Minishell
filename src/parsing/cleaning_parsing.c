/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:19:30 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/04 14:23:07 by jdhallen         ###   ########.fr       */
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