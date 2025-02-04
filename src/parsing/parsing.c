/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:06:49 by tgoudman          #+#    #+#             */
/*   Updated: 2025/02/04 14:03:23 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int parsing(t_bash *shell)
{
	int	len;
	int	i;

	if (search_for_var(shell) == ERROR)
		return (ERROR);
	ft_printf(1, "Command after variable replacement is : %t\n", shell->line.group);
	if (shell->line.group == NULL)
		return (ERROR);
	len = 0;
	while (shell->line.group[len] != NULL)
		len++;
	shell->line.cmd = malloc(shell->line.cmd_nbr * sizeof(t_cmd));
	if (shell->line.cmd == NULL)
		return (ERROR);
	shell->line.cmd[0].args = malloc((len + 1) * sizeof(char*));
	if (shell->line.cmd[0].args == NULL)
		return (ERROR);
	i = 0;
	while (i < len)
	{
		if (i == 0)
		{
			shell->line.cmd[0].name = ft_strdup(shell->line.group[i]);
			if (shell->line.cmd[0].name == NULL)
				return (ERROR);
		}
		shell->line.cmd[0].args[i] = ft_strdup(shell->line.group[i]);
		if (shell->line.cmd[0].args[i] == NULL)
			return (ERROR);
		i++;
	}
	shell->line.cmd[0].args[i] = NULL;
	single_function(shell, &shell->line.cmd[0]);
	return (1);
}

int	cmd_manager(t_bash *shell, char *input)
{
	if (search_for_quote(shell, input) == ERROR)
		return (ERROR);
	ft_printf(1, "Command after creation is : %t\n", shell->line.group);
	shell->line.cmd_nbr = 1;
	if (shell->line.group == NULL)
		return (0);
	free(input);
	// if (parsing(shell) == ERROR)
	// 	return (ERROR);
	parsing(shell);
	if (shell->line.cmd[0].name)
		free(shell->line.cmd[0].name);
	if (shell->line.cmd[0].args)
		free_cmd(shell->line.cmd[0].args);
	if (shell->line.cmd)
		free(shell->line.cmd);
	if (shell->line.group)
		free_cmd(shell->line.group);
	return (0);
}

	// shell->line.group = ft_split(input, ' ');