/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:40:19 by tgoudman          #+#    #+#             */
/*   Updated: 2025/02/11 17:41:15 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_path(char *cmd)
{
	int		j;
	char	**all_path;
	char	*join;
	char	*exec;

	all_path = ft_split(getenv("PATH"), ':');
	if (!all_path)
		exit(1);
	j = 0;
	while (all_path[j])
	{
		join = ft_strjoin(all_path[j], "/");
		exec = ft_strjoin(join, cmd);
		free(join);
		if (access(exec, F_OK | X_OK) == 0)
		{
			free_cmd(all_path);
			return (exec);
		}
		free(exec);
		j++;
	}
	free_cmd(all_path);
	return (cmd);
}
