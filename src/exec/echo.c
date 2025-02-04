/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:14:25 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/03 18:06:30 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_echo_printf(t_cmd *cmd, int output, t_var *v)
{
	while (cmd->args[v->i] != NULL)
	{
		ft_printf(output, "%s", cmd->args[v->i]);
		v->i++;
		if (cmd->args[v->i] == NULL)
			break ;
		if (cmd->args[v->i] != NULL)
		{
			if (v->i != 0)
				if (strcmp(cmd->args[v->i], "") == 0)
					continue ;
			ft_printf(output, " ");
		}
	}
}

int ft_echo(t_bash *shell, t_cmd *cmd, int output)
{
	t_var	v;
	int newline;

	newline = TRUE;
	v.i = 1;
	if (cmd->args[1] == NULL)
		return (ft_printf(output, "\n"), shell->prev_return = 0, 0);
	while (cmd->args[v.i] != NULL)
	{
		if (cmd->args[v.i] == NULL)
			break ;
		if (cmd->args[v.i][0] != '-')
			break ;
		v.j = 1;
		while (cmd->args[v.i][v.j] == 'n')
			v.j++;
		if (cmd->args[v.i][v.j] != '\0')
			break ;
		newline = FALSE;
		v.i++;
	}
	ft_echo_printf(cmd, output, &v);
	if (newline == TRUE)
		ft_printf(output, "\n");
	return (shell->prev_return = 0, 0);
}
