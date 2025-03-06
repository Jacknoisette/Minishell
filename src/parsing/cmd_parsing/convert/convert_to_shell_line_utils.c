/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_shell_line_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:18:07 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/27 11:26:08 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_tmpjoin(char *tmp_str, char **temp_char, int mod)
{
	char	*tmp;

	tmp = NULL;
	if (mod == 1)
		tmp = ft_strjoin(*temp_char, tmp_str);
	else if (mod == 2)
		tmp = ft_strdup(tmp_str);
	free(*temp_char);
	return (tmp);
}

int	lst_cmd_len(t_bash *shell, t_lst_cmd **lst_cmd)
{
	t_lst_cmd	*tmp_cmd;
	int			cmd_size;

	cmd_size = 0;
	tmp_cmd = *lst_cmd;
	if (tmp_cmd == NULL)
		return (ERROR);
	if (tmp_cmd->arg == NULL && tmp_cmd->next == NULL)
		return (shell->line.cmd = NULL, TRUE);
	while (tmp_cmd != NULL)
	{
		tmp_cmd = tmp_cmd->next;
		cmd_size++;
	}
	return (cmd_size);
}

// ft_printf(1, "こんにちは せカい!!! %s\n", tmp_str);