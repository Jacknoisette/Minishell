/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_fd_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:13:49 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/07 12:42:01 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_file_type(t_lst_var **tmp, t_cmd_pos *pos, char *type)
{
	ft_printf(1, "%c\n", (*tmp)->string[pos->j]);
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
	if ((*tmp)->string[pos->j] == '\0')
	{
		*tmp = (*tmp)->next;
		if (*tmp == NULL)
			return (ft_printf(1, "minishell : syntax error heredoc"), BREAK);
		pos->i++;
		pos->j = 0;
	}
	return (CONTINUE);
}

t_lst_var	*init_cmdfd(t_lst_var *m_lst, t_cmd_pos *pos)
{
	t_lst_var	*tmp;
	
	ft_printf(1, "start : arg[%i], char[%i]\nend : arg[%i], char[%i]\n",
		pos->start_of_arg,
		pos->start_of_char,
		pos->end_of_arg,
		pos->end_of_char);
	tmp = m_lst;
	while (tmp->id < pos->start_of_arg)
		tmp = tmp->next;
	// pos->j = pos->start_of_char;
	ft_printf(1, "%s\n", tmp->string);
	return (tmp);
}

char *get_lst_fd(t_lst_var *main_lst, t_cmd_pos *pos, char *type, char **limit)
{
	t_lst_var	*tmp;
	char		*name;
	char		*temp;
	char		*temp2;
	
	tmp = init_cmdfd(main_lst, pos);
	name = ft_strdup("");
	if (name == NULL)
		return (NULL);
	if (check_file_type(&tmp, pos, type) == BREAK)
		return (NULL);
	ft_printf(1, "%c\n", *type);
	ft_printf(1, "FD TEST 2!!!\n");
	ft_printf(1, "char :%c\n", tmp->string[pos->j]);
	while (tmp != NULL)
	{
		if (is_bash_op(tmp->string[pos->j - 1], '!') == 0)
			pos->j = 0;
		while (tmp->string[pos->j] != '\0' && is_bash_op(tmp->string[pos->j], '*') == 0)
		{
			temp = ft_substr(tmp->string, pos->j, 1);
			if (temp == NULL)
				return (NULL);
			temp2 = ft_strdup(name);
			if (temp2 == NULL)
				return (NULL);
			free(name);
			name = ft_strjoin(temp2, temp);
			if (name == NULL)
				return (NULL);
			free(temp);
			free(temp2);
			pos->j++;
		}
		if (is_bash_op(tmp->string[pos->j], '*') == 1)
		{
			ft_printf(1,"BASHOPTEST1\n");
			if (pos->j != 0)
				pos->j -= 1;
			// tmp = tmp->next;
			// pos->i++;
			break ;
		}
		ft_printf(1,"BASHOPTEST2\n");
		if (tmp->next != NULL)
		{
			if (tmp->is_squote == tmp->next->is_squote)
			{
				tmp = tmp->next;
				pos->i++;
				break ;
			}
		}
		ft_printf(1, "fd name at lst[%i] : \033[35m%s\033[0m\n", tmp->id, name);
		tmp = tmp->next;
		if (tmp == NULL)
			break ;
		pos->i++;
	}
	if (*type == 'h')
	{
		*limit = name;
		name = ft_strdup("");
	}
	// if (tmp != NULL)
	// {
	// 	pos->start_of_arg = pos->i;
	// 	pos->end_of_arg = pos->i;
	// 	pos->start_of_char = pos->j;
	// 	pos->end_of_char = pos->j;
	// }
	return (name);
}

void	fd_create(t_lst_var *main_lst, t_lst_fd	**fd_list, t_cmd_pos *pos)
{
	t_lst_fd	*fd;
	char	*name;
	char	type;
	char	*limit;

	name = get_lst_fd(main_lst, pos, &type, &limit);
	if (name == NULL)
		return ;
	fd = create_new_node_fd(name, type, limit);
	list_add_back_fd(fd_list, fd);
	pos->j++;
}

int	act_is_fd(t_lst_var *main_lst, t_lst_fd **fd_list,
		t_lst_var **tmp, t_cmd_pos *pos)
{
	ft_printf(1, "FD TEST 1!!!\n");
	ft_printf(1, "pos i %i, pos j %i\n", pos->i, pos->j);
	fd_create(main_lst, fd_list, pos);
	ft_printf(1, "pos i %i, pos j %i\n", pos->i, pos->j);
	pos->last_type = FILE;
	while ((*tmp)->id < pos->i)
	{
		*tmp = (*tmp)->next;
		if (*tmp == NULL)
			return (BREAK);
		pos->j = 0;
	}
	ft_printf(1, "\033[35mpos i %i, pos j %i\n\033[0m", pos->i, pos->j);
	if (is_bash_op((*tmp)->string[pos->j], '|') == 1)
		return (pos->j++, TRUE);
	if ((*tmp)->string[pos->j] == '\0')
	{
		*tmp = (*tmp)->next;
		if (*tmp == NULL)
			return (BREAK);
		pos->i++;
		pos->j = 0;
	}
	if (is_bash_op((*tmp)->string[pos->j], '|') == 1)
		return (pos->j++, TRUE);
	return (0);
}

int	exec_fd(t_lst_var *main_lst, t_lst_cmd **cmd_list,
		t_lst_var **tmp, t_cmd_pos *pos)
{
	exec_create(main_lst, cmd_list, pos);
	if ((*tmp)->string[pos->j] == '\0')
	{
		*tmp = (*tmp)->next;
		if (*tmp == NULL)
			return (BREAK) ;
		pos->i++;
		pos->j = 0;
	}
	pos->start_of_arg = pos->i;
	pos->start_of_char = pos->j;
	ft_printf(1, "aibo : %c\n", (*tmp)->string[pos->j]);
	return (GO_ON);
}

//echo $USER<file1|echo $USER