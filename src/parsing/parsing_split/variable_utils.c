/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:23:28 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/25 13:29:15 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	after_case(char *after, t_lst_var **node)
{
	t_lst_var	*temp_next;

	temp_next = (*node)->next;
	if (after != NULL && ft_strcmp(after, "") != 0)
	{
		(*node)->next = create_new_node_var(ft_strdup(after),
				(*node)->is_squote);
		(*node)->next->next = temp_next;
	}
}
