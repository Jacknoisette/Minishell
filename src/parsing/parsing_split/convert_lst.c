/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:14:58 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/27 13:04:56 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	convert_core(t_lst_var	**result, t_lst_var	**temp, int *id)
{
	t_lst_var	*node;

	node = create_new_node_var(ft_strdup((*temp)->string), (*temp)->is_squote);
	node->id = *id;
	node->is_var = (*temp)->is_var;
	(*id)++;
	list_add_back_var(result, node);
	if ((*temp)->next == NULL)
		node->is_space = TRUE;
	else if (is_bash_op((*temp)->next->string[0], '*') == 1
		&& (*temp)->next->is_squote == FALSE)
		node->is_space = TRUE;
	else
		node->is_space = FALSE;
	*temp = (*temp)->next;
}

t_lst_var	*convert_lst(t_lst_var **lst_point)
{
	t_lst_var	*result;
	t_lst_var	*temp;
	int			i;
	int			id;

	i = 0;
	id = 0;
	result = NULL;
	while (lst_point[i] != NULL)
	{
		temp = lst_point[i];
		while (temp != NULL)
			convert_core(&result, &temp, &id);
		i++;
	}
	ft_printf_list_var(&result, 1);
	return (result);
}
