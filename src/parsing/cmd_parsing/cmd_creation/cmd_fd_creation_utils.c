/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_fd_creation_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:38:05 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/20 13:45:15 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_type(t_lst_var **tmp, t_cmd_pos *pos, char *type)
{
	if ((*tmp)->string[pos->j] == '>' && (*tmp)->string[pos->j + 1] == '>')
		*type = 'a';
	else if ((*tmp)->string[pos->j] == '<' && (*tmp)->string[pos->j + 1] == '<')
		*type = 'h';
	else if ((*tmp)->string[pos->j] == '<')
		*type = 'i';
	else if ((*tmp)->string[pos->j] == '>')
		*type = 'o';
	if (*type == 'a' || *type == 'h')
		pos->j += 2;
	else
		pos->j += 1;
}

int	check_file_type(t_lst_var **tmp, t_cmd_pos *pos, char *type)
{
	check_type(tmp, pos, type);
	pos->start_of_arg = pos->i;
	pos->start_of_char = pos->j;
	if (is_bash_op((*tmp)->string[pos->j], '*') == TRUE)
		return (ft_printf(1, "minishell : syntax error file\n"), BREAK);
	if ((*tmp)->string[pos->j] == '\0')
	{
		*tmp = (*tmp)->next;
		if (*tmp == NULL || is_bash_op((*tmp)->string[0], '*') == TRUE)
			return (ft_printf(1, "minishell : syntax error file\n"), BREAK);
		pos->i++;
		pos->j = 0;
		pos->start_of_arg = pos->i;
		pos->start_of_char = pos->j;
	}
	return (CONTINUE);
}

char	*join_temp_to_name(char **name, char *tmp_str, t_cmd_pos *pos, int mod)
{
	char		*temp;
	char		*temp2;

	if (mod == 1)
		temp = ft_substr(tmp_str, pos->j, ft_strlen(tmp_str));
	if (mod == 2)
		temp = ft_substr(tmp_str, pos->j, 1);
	temp2 = ft_strdup(*name);
	free(*name);
	if (temp == NULL || temp2 == NULL)
		return (NULL);
	*name = ft_strjoin(temp2, temp);
	if (name == NULL)
		return (free(temp), free(temp2), NULL);
	return (free(temp), free(temp2), *name);
}

void	end_of_func(char **limit, char **name, char *type, t_cmd_pos *pos)
{
	pos->start_of_arg = pos->i;
	pos->start_of_char = pos->j;
	*limit = NULL;
	if (*type == 'h')
	{
		*limit = *name;
		*name = ft_strdup("");
	}
}

t_lst_var	*init_cmdfd(t_lst_var *m_lst, t_cmd_pos *pos)
{
	t_lst_var	*tmp;

	tmp = m_lst;
	while (tmp->id < pos->start_of_arg)
		tmp = tmp->next;
	return (tmp);
}
