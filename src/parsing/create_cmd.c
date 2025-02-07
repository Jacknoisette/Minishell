/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:08:33 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/07 11:54:48 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_lst_cmd	*create_new_node_cmd(t_char_arg *arg)
{
	t_lst_cmd	*new_node;

	new_node = malloc(sizeof(t_lst_cmd));
	if (!new_node)
		return (NULL);
	new_node->arg = arg;
	new_node->next = NULL;
	return (new_node);
}

void	list_add_back_cmd(t_lst_cmd **list, t_lst_cmd *new_node)
{
	t_lst_cmd *tmp;

	tmp = *list;
	if (*list == NULL)
	{
		*list = new_node;
		return;
	}
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
	new_node->next = NULL;
}

t_lst_arg	*create_new_node_arg(char *string)
{
	t_lst_arg	*new_node;

	new_node = malloc(sizeof(t_lst_arg));
	if (!new_node)
		return (NULL);
	new_node->str = string;
	new_node->next = NULL;
	return (new_node);
}

void	list_add_back_arg(t_lst_arg **list, t_lst_arg *new_node)
{
	t_lst_arg *tmp;

	tmp = *list;
	if (*list == NULL)
	{
		*list = new_node;
		return;
	}
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
	new_node->next = NULL;
}

void	ft_printf_list_cmd(t_lst_cmd **list, int output)
{
	t_lst_cmd	*tmp;
	int			i;
	int			j;

	tmp = *list;
	i = 0;
	while (tmp)
	{
		ft_printf(output, "Arg %i is \033[34m", i);
		j = 0;
		while (tmp->arg[j].str != NULL)
		{
			ft_printf(output, "%s", tmp->arg[j].str);
			if (tmp->arg[j].is_space == TRUE)
				ft_printf(output, " ");
			j++;
		}
		ft_printf (output, "\033[0m\n");
		i++;
		tmp = tmp->next;
	}
}
