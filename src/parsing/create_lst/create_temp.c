/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_temp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:17:35 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/27 13:25:08 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_lst_var	*create_new_node_var(char *string, int is_squote)
{
	t_lst_var	*new_node;

	new_node = malloc(sizeof(t_lst_var));
	if (!new_node)
		return (NULL);
	new_node->string = string;
	new_node->is_squote = is_squote;
	new_node->is_var = FALSE;
	new_node->next = NULL;
	return (new_node);
}

void	list_add_back_var(t_lst_var **list, t_lst_var *new_node)
{
	t_lst_var	*tmp;

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

int	lst_create_new_var(t_lst_var **lst_var, char *str, t_var v, char quote)
{
	t_lst_var	*tmp;
	char		*string;

	string = ft_subvar(str, v.j, v.i - v.j, quote);
	if (string == NULL)
		return (ERROR);
	tmp = create_new_node_var(string, quote);
	tmp->is_space = 0;
	if (tmp == NULL)
		return (ERROR);
	list_add_back_var(lst_var, tmp);
	return (TRUE);
}

// ft_printf(1, "1 %c %i : len %i\n", str[v.i], v.i, v.i - v.j);