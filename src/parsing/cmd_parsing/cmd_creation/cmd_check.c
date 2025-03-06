/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:44:56 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/25 11:34:30 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_consecutive_pipe(char *str, int *pipe_mod)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		if (*pipe_mod == FALSE && str[i] == '|')
			*pipe_mod = TRUE;
		else if (*pipe_mod == TRUE && str[i] == '|')
			return (ft_printf(1, "minishell: consecutive '|'\n"), ERROR);
		else if (str[i] != '|' && str[i] != '\0')
			*pipe_mod = FALSE;
		i++;
	}
	return (TRUE);
}

int	check_cmd(t_lst_var **main_lst)
{
	t_lst_var	*tmp;
	int			pipe_mod;
	int			i;

	pipe_mod = FALSE;
	tmp = *main_lst;
	if (tmp->string[0] == '|')
		return (ft_printf(1, "minishell: syntax error near '|'\n"), ERROR);
	while (tmp->next != NULL)
	{
		if (check_consecutive_pipe(tmp->string, &pipe_mod) == ERROR)
			return (ERROR);
		tmp = tmp->next;
	}
	if (check_consecutive_pipe(tmp->string, &pipe_mod) == ERROR)
		return (ERROR);
	i = 0;
	while (tmp->string[i] != '\0')
		i++;
	if (i > 0)
		if (tmp->string[i - 1] == '|' && tmp->is_squote == FALSE)
			return (ft_printf(1, "minishell: syntax error near '|'\n"), ERROR);
	return (TRUE);
}

void	null_lst_cmd(t_lst_cmd **cmd_list)
{
	t_lst_cmd	*cmd_tmp;

	cmd_tmp = create_new_node_cmd(NULL);
	list_add_back_cmd(cmd_list, cmd_tmp);
}
