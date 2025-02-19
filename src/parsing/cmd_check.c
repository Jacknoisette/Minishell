/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:44:56 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/14 12:55:54 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_cmd(t_lst_var **main_lst)
{
	t_lst_var	*tmp;
	int			len;

	len = 0;
	tmp = *main_lst;
	if (tmp->string[0] == '|')
		return (ft_printf(1, "minishell: syntax error near '|'\n"), ERROR);
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp->string[len] != '\0')
		len++;
	if (len > 0)
		if (tmp->string[len - 1] == '|' && tmp->is_squote == FALSE)
			return (ft_printf(1, "minishell: syntax error near '|'\n"), ERROR);
	return (TRUE);
}

void	null_lst_cmd(t_lst_cmd **cmd_list)
{
	t_lst_cmd	*cmd_tmp;

	cmd_tmp = create_new_node_cmd(NULL);
	list_add_back_cmd(cmd_list, cmd_tmp);
}
