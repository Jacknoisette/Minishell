/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:29:28 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/06 13:32:49 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	single_function(t_bash *shell, t_cmd *cmd, int index)
{
	(void)index;
	if (ft_strncmp(cmd->name, "echo", 5) == 0)
		return (shell->func[ECHO].exec(shell, cmd, cmd->input), 1);
	else if (ft_strncmp(cmd->name, "cd", 3) == 0)
		return (shell->func[CD].exec(shell, cmd, cmd->input), 1);
	else if (ft_strncmp(cmd->name, "pwd", 4) == 0)
		return (shell->func[PWD].exec(shell, cmd, cmd->input), 1);
	else if (ft_strncmp(cmd->name, "export", 7) == 0)
		return (shell->func[EXPORT].exec(shell, cmd, cmd->input), 1);
	else if (ft_strncmp(cmd->name, "unset", 6) == 0)
		return (shell->func[UNSET].exec(shell, cmd, cmd->input), 1);
	else if (ft_strncmp(cmd->name, "env", 4) == 0)
		return (shell->func[ENV].exec(shell, cmd, cmd->input), 1);
	else if (ft_strncmp(cmd->name, "exit", 5) == 0)
		return (shell->func[EXIT].exec(shell, cmd, cmd->input), 1);
	return (0);
}

// char	get_input(t_bash *shell, char *str)
// {
// 	char		file;
// 	t_lst_fd	*fd;

// 	file = 'n';
// 	fd = shell->line.lst_fd;
// 	if (!fd)
// 		return (file);
// 	while (fd)
// 	{
// 		if (ft_strcmp(fd->name, str) == 0)
// 			file = fd->type;
// 		fd = fd->next;
// 	}
// 	return (file);
// }
