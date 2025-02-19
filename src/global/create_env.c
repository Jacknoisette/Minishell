/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:41:56 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/14 11:43:41 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_lst	*create_new_node(char *data, char *name)
{
	t_lst	*new_node;

	new_node = malloc(sizeof(t_lst));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->name = name;
	new_node->next = NULL;
	return (new_node);
}

void	list_add_back(t_lst **list, t_lst *new_node)
{
	t_lst	*tmp;

	tmp = *list;
	if (*list == NULL)
	{
		*list = new_node;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
	new_node->next = NULL;
}
