/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:45:02 by tgoudman          #+#    #+#             */
/*   Updated: 2025/03/06 13:39:47 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	redirect_fd(t_bash *shell, int actual_cmd)
{
	if (dup2(shell->line.cmd[actual_cmd].input, STDIN_FILENO) == ERROR)
		return (ERROR);
	if (dup2(shell->line.cmd[actual_cmd].output, STDOUT_FILENO) == ERROR)
		return (ERROR);		
	return (1);
}

int	check_cmds(t_bash *shell)
{
	if (shell->line.cmd_nbr == 1)
	{
		if (single_function(shell, shell->line.cmd, 0) == 1)
			return (1);
	}
	return (0);
}

int	get_fd_type(t_bash *shell, char *str, char *t)
{
	t_lst_fd	*tmp;

	tmp = shell->line.lst_fd;
	if (!tmp)
		return (ERROR);
	while (tmp)
	{
		if (ft_strcmp(str, tmp->name) == 0)
		{
			*t = tmp->type;
			return (tmp->fd);
		}
		tmp = tmp->next;
	}
	return (ERROR);
}

int	search_redirection(t_bash *shell, int cmd_nbr)
{
	char	*cmd_nbr_str;
	char	t;
	int		find_output;
	int		i;
	int		fd;

	i = 0;
	find_output = FALSE;
	cmd_nbr_str = ft_itoa(cmd_nbr);
	if (cmd_nbr_str == NULL)
		return (ERROR);
	while (shell->line.group[i] != NULL
		&& ft_strcmp(shell->line.group[i], cmd_nbr_str) != 0)
		i++;
	while (i != 0 && shell->line.group[i][0] != '|')
		i--;
	if (i == 0)
		shell->line.cmd[cmd_nbr].input = STDIN_FILENO;
	while (shell->line.group[i] != NULL
		&& shell->line.group[i][0] != '|')
	{
		if (shell->line.group[i][0] == '!')
		{
			fd = get_fd_type(shell, ft_substr(shell->line.group[i], 1,
				ft_strlen(shell->line.group[i] - 1)), &t);
			if (fd == ERROR)
				return (ERROR);
			if (t == 'i' || t == 'h')
				shell->line.cmd[cmd_nbr].input = fd;
			if (t == 'o' || t == 'a')
			{
				shell->line.cmd[cmd_nbr].output = fd;
				find_output = TRUE;
			}
		}
		i++;
	}
	if (find_output == FALSE && shell->line.group[i] == NULL)
		shell->line.cmd[cmd_nbr].input = STDOUT_FILENO;
	return (0);
}
