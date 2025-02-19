/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:29:28 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/13 11:05:34 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	single_function(t_bash *shell, t_cmd *cmd)
{
	if (ft_strncmp(cmd->name, "echo", 5) == 0)
		shell->func[ECHO].exec(shell, cmd, 1);
	else if (ft_strncmp(cmd->name, "cd", 3) == 0)
		shell->func[CD].exec(shell, cmd, 1);
	else if (ft_strncmp(cmd->name, "pwd", 4) == 0)
		shell->func[PWD].exec(shell, cmd, 1);
	else if (ft_strncmp(cmd->name, "export", 7) == 0)
		shell->func[EXPORT].exec(shell, cmd, 1);
	else if (ft_strncmp(cmd->name, "unset", 6) == 0)
		shell->func[UNSET].exec(shell, cmd, 1);
	else if (ft_strncmp(cmd->name, "env", 4) == 0)
		shell->func[ENV].exec(shell, cmd, 1);
	else if (ft_strncmp(cmd->name, "exit", 5) == 0)
		shell->func[EXIT].exec(shell, cmd, 1);
	else
		init_execve(shell);
	return (0);
}
	// else 
	// {
	// 	ft_printf(1, "Command '%s' not found\n", cmd->name);
	// 	shell->prev_return = 127;
	// }