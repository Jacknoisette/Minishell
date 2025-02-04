/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_temp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:17:35 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/04 10:12:06 by jdhallen         ###   ########.fr       */
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
	new_node->next = NULL;
	return (new_node);
}

void	list_add_back_var(t_lst_var **list, t_lst_var *new_node)
{
	t_lst_var *tmp;

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

void	ft_printf_list_var(t_lst_var **list, int output)
{
	t_lst_var	*tmp;

	tmp = *list;
	while (tmp)
	{
		ft_printf(output, "String is \033[34m%s\033[0m and is in quote \033[34m%c\033[0m\n", tmp->string, tmp->is_squote);
		tmp = tmp->next;
	}
}

int	lst_create_new_var(t_lst_var **lst_var, char *str, t_var v, char quote)
{
	t_lst_var *tmp;
	char *string;

	string = ft_subvar(str, v.j, v.i - v.j, quote);
	if (string == NULL)
		return (ERROR);
	if (string[0] == '\0')
		return (TRUE);
	tmp = create_new_node_var(string, quote);
	if (tmp == NULL)
		return (ERROR);
	list_add_back_var(lst_var, tmp);
	return (TRUE);
}

// ft_printf(1, "1 %c %i : len %i\n", str[v.i], v.i, v.i - v.j);