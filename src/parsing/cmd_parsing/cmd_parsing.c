/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:37:42 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/27 13:38:02 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	cmd_parsing(t_bash *shell, t_lst_var *main_lst)
{
	t_cmd_pos		pos;
	t_lst_cmd		*cmd_list;
	t_lst_line		*line_list;
	t_lst_fd		*fd_list;

	(void)shell;
	line_list = NULL;
	fd_list = NULL;
	pos.start_of_arg = 0;
	pos.start_of_char = 0;
	pos.end_of_arg = 0;
	pos.end_of_char = 0;
	pos.last_type = FALSE;
	pos.i = 0;
	pos.j = 0;
	cmd_list = get_lst_cmd(main_lst, &line_list, &fd_list, &pos);
	free_list_var(&main_lst);
	if (cmd_list == NULL)
		return (free_list_line(&line_list), free_list_fd(&fd_list), ERROR);
	remake_line(&line_list, &cmd_list);
	// ft_printf_list_cmd(&cmd_list, 1);
	// ft_printf_list_line(&line_list, 1);
	// ft_printf_list_fd(&fd_list, 1);
	if (convert_lst_to_line(shell, &line_list, &cmd_list, &fd_list) == ERROR)
		return (free_list_line(&line_list), free_list_cmd(&cmd_list),
			free_list_fd(&fd_list), ERROR);
	return (free_list_cmd(&cmd_list), free_list_line(&line_list), 1);
}
