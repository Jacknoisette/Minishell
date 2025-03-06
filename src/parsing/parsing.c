/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:06:49 by tgoudman          #+#    #+#             */
/*   Updated: 2025/03/06 13:12:14 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	call_free(t_bash *shell)
{
	int	i;

	i = 0;
	if (shell->line.cmd != NULL)
	{
		while (i < shell->line.cmd_nbr)
		{
			if (shell->line.cmd[i].name == NULL)
				break ;
			free(shell->line.cmd[i].name);
			if (shell->line.cmd[i].args == NULL)
				break ;
			free_cmd(shell->line.cmd[i].args);
			i++;
		}
		free(shell->line.cmd);
	}
	if (shell->line.group != NULL)
		free_cmd(shell->line.group);
	if (shell->line.lst_fd != NULL)
		free_list_fd(&shell->line.lst_fd);
}

int	parsing(t_bash *shell)
{
	if (parsing_split(shell) == ERROR)
		return (shell->prev_return = 2, ERROR);
	if (shell->line.group == NULL)
		return (ERROR);
	ft_printf(1, "LINE after parsing is : %t\n", shell->line.group);
	return (1);
}

int	cmd_manager(t_bash *shell, char *input)
{
	int	parsing_res;

	interactive_mode(FALSE);
	shell->line.group = NULL;
	shell->line.cmd = NULL;
	shell->line.lst_fd = NULL;
	input = input_remake(input);
	if (input != NULL)
	{
		if (search_for_quote(shell, input) == ERROR)
			return (ERROR);
		ft_printf(1, "LINE after creation is : %t\n", shell->line.group);
		shell->line.cmd_nbr = 1;
		if (shell->line.group == NULL)
			return (0);
		free(input);
		parsing_res = parsing(shell);
		if (parsing_res != ERROR)
			init_execve(shell);
	}
	call_free(shell);
	return (0);
}
