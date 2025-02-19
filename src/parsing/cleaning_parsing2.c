/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_parsing2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:21:22 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/14 15:25:26 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
	*lst_arg = NULL;
}

void	free_char_arg(t_char_arg *arg)
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
