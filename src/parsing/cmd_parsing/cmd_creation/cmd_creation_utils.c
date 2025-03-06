/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_creation_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:01:42 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/17 10:22:00 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_lst_var	*init_cmdarg(t_lst_var *m_lst, t_cmd_pos *pos, t_var *v)
{
	t_lst_var	*tmp;

	tmp = m_lst;
	while (tmp->id < pos->start_of_arg)
		tmp = tmp->next;
	v->i = pos->start_of_char;
	return (tmp);
}

t_char_arg	*make_arg(t_lst_arg *arg_stack)
{
	t_char_arg	*args;
	t_lst_arg	*arg_str;
	int			len;
	int			i;

	arg_str = arg_stack;
	len = 0;
	while (arg_str != NULL)
	{
		arg_str = arg_str->next;
		len++;
	}
	args = malloc((len + 1) * sizeof(t_char_arg));
	i = 0;
	arg_str = arg_stack;
	while (arg_str != NULL)
	{
		args[i].str = ft_strdup(arg_str->str);
		args[i].is_space = arg_str->is_space;
		if (args[i].str == NULL)
			return (free_char_arg(args), free_list_arg(&arg_stack), NULL);
		i++;
		arg_str = arg_str->next;
	}
	return (args[len].str = NULL, args[len].is_space = 0, args);
}

void	move_pos_v(t_lst_var *tmp, t_var *v, t_cmd_pos *pos)
{
	if (tmp->id != pos->start_of_arg)
		v->i = 0;
	v->j = v->i;
	if (tmp->id == pos->end_of_arg)
		v->i = pos->end_of_char;
	else
		v->i = ft_strlen(tmp->string);
}

int	cmd_list_count(t_lst_cmd **list)
{
	t_lst_cmd	*tmp;
	int			count;

	tmp = *list;
	count = -1;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

char	find_char(t_lst_var **main_lst, t_cmd_pos *pos)
{
	t_lst_var	*tmp;

	tmp = *main_lst;
	while (tmp->id != pos->start_of_arg)
		tmp = tmp->next;
	return (tmp->string[pos->start_of_char]);
}
