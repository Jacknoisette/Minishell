/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:38:05 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/14 11:35:48 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_cmd(char **cmd)
{
	int	i;

	i = 0;
	if (cmd == NULL)
		return ;
	while (cmd[i] != NULL)
	{
		free(cmd[i++]);
	}
	if (cmd != NULL)
		free(cmd);
}

void	free_list(t_lst **env)
{
	t_lst	*tmp;

	while (*env)
	{
		tmp = *env;
		(*env) = (*env)->next;
		if (tmp->name != NULL)
			free(tmp->name);
		if (tmp->data != NULL)
			free(tmp->data);
		if (tmp != NULL)
			free(tmp);
	}
}
