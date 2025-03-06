/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:39:23 by tgoudman          #+#    #+#             */
/*   Updated: 2025/03/04 10:39:33 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_atoi_exit(const char *nptr)
{
	int	i;
	int	s;
	int	n;

	i = 0;
	s = 0;
	n = 0;
	if ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		while (((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
			i++;
	if ((nptr[i] == '+' && ++s) || (nptr[i] == '-' && --s))
		i++;
	else
		s = 1;
	if ((nptr[i] != '\0') && nptr[i] >= 48 && nptr[i] <= 57)
	{
		while ((nptr[i] != '\0' && nptr[i] >= 48 && nptr[i] <= 57))
		{
			n = (n * 10) + (nptr[i] - '0');
			i++;
		}
		if ((nptr[i] != '\0' && (nptr[i] < 48 || nptr[i] > 57)))
			return (printf("%s: numeric argument required\n", nptr), 2);
	}
	return (n *= s);
}

int	ft_exit(t_bash *shell, t_cmd *cmd, int output)
{
	int	i;

	i = 0;
	(void)output;
	while (cmd->args[i])
		++i;
	if (i > 3)
	{
		shell->prev_return = 127;
		printf("bash: exit: too many arguments\n");
		return (1);
	}
	if (i == 2)
		shell->prev_return = ft_atoi_exit(cmd->args[1]);
	free_list_env(shell->lst_env);
	if (cmd->args)
		free_cmd(cmd->args);
	if (cmd->name)
		free(cmd->name);
	if (shell->line.cmd)
		free(shell->line.cmd);
	if (shell->line.group)
		free_cmd(shell->line.group);
	exit(shell->prev_return);
	return (0);
}
