/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:40:17 by jdhalv.l          #+#    #+#             */
/*   Updated: 2025/02/04 15:23:35 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_bash_op(char chr, char mod)
{
	if (mod == '|' && (chr == '|'))
		return (TRUE);
	else if (mod == '!' && (chr == '<' || chr == '>'))
		return (TRUE);
	else if (mod == '*' && (chr == '|' || chr == '<' || chr == '>'))
		return (TRUE);
	return (FALSE);
}

char **cmd_create_arg(t_lst_var **lst_var, t_cmd_pos *pos)
{
	t_lst_var	*tmp;
	t_lst_arg	*arg_stack;
	t_lst_arg	*arg_str;
	t_var		v;
	char 		**args;
	
	ft_printf(1, "start : arg[%i], lst[%i], char[%i]\nend : arg[%i], lst[%i], char[%i]\n",
		pos->start_of_arg,
		pos->start_of_str,
		pos->start_of_char,
		pos->end_of_arg,
		pos->end_of_str,
		pos->end_of_char);
	arg_stack = NULL;
	while (pos->start_of_arg <= pos->end_of_arg)
	{
		tmp = lst_var[pos->start_of_arg];
		while ((pos->start_of_arg < pos->end_of_arg
			&& tmp != NULL) || (pos->start_of_arg == pos->end_of_arg
			&& pos->start_of_str <= pos->end_of_str))
		{
			if (tmp->is_squote != FALSE)
			{
				tmp = tmp->next;
				continue ;
			}
			v.i = pos->start_of_char;
			if (pos->start_of_arg == pos->end_of_arg)
				v.i = pos->end_of_char;
			else
				while (tmp->string[v.i] != '\0')
					v.i++;
			ft_printf(1, "%i, %i, %s\n", pos->start_of_char, v.i, ft_substr(tmp->string, pos->start_of_char, v.i - pos->start_of_char));
			arg_str = create_new_node_arg(ft_substr(tmp->string, pos->start_of_char, v.i - pos->start_of_char));
			list_add_back_arg(&arg_stack, arg_str);
			if (arg_str->str == NULL)
				return (free_list_arg(&arg_stack), NULL);
			ft_printf(1, "CA string in [%i] : \033[34m \033[4m%s\033[0m\n", pos->start_of_arg, tmp->string);
			tmp = tmp->next;
			pos->start_of_char = 0;
			if (pos->start_of_arg == pos->end_of_arg)
				break;
		}
		pos->start_of_arg++;
	}
	arg_str = arg_stack;
	v.l = 0;
	while (arg_str != NULL)
	{
		arg_str = arg_str->next;
		v.l++;
	}
	args = malloc((v.l + 1) * sizeof(char *));
	v.j = 0;
	arg_str = arg_stack;
	while (arg_str != NULL)
	{
		ft_printf(1, "arg count %s\n", arg_str->str);
		args[v.j] = ft_strdup(arg_str->str);
		if (args[v.j] == NULL)
			return (free_cmd(args), free_list_arg(&arg_stack), NULL);
		v.j++;
		arg_str = arg_str->next;
	}
	args[v.j] = NULL;
	ft_printf(1, "cmd : %t\n", args);
	free_list_arg(&arg_stack);
	return (args);
}

void	cmd_get_end_arg(t_lst_var **lst_var, int len, t_var *v, t_cmd_pos *pos)
{
	t_lst_var	*tmp;
	t_lst_cmd	*cmd_list;
	t_lst_cmd	*cmd;
	char **arg;
	
	cmd_list = NULL;
	v->i = -1;
	while (v->i < len)
	{
		v->i++;
		tmp = lst_var[v->i];
		v->j = 0;
		while (tmp != NULL)
		{
			ft_printf(1, "string in [%i] : \033[34m \033[4m%s\n\033[0m", v->i, tmp->string);
			v->k = 0;
			while (tmp->string[v->k] != '\0' && is_bash_op(tmp->string[v->k], '*') == 0)
				v->k++;
			if (tmp->string[v->k] == '\0')
			{
				tmp = tmp->next;
				v->j++;
			}
			else
			{
				pos->end_of_arg = v->i;
				pos->end_of_str = v->j;
				pos->end_of_char = v->k;
				arg = cmd_create_arg(lst_var, pos);
				if (arg == NULL)
					return ;
				cmd = create_new_node_cmd(arg);
				ft_printf(1, "hello\n");
				list_add_back_cmd(&cmd_list, cmd);
				pos->end_of_char += 1;
				pos->start_of_arg = pos->end_of_arg;
				pos->start_of_str = pos->end_of_str;
				pos->start_of_char = pos->end_of_char;
				v->j++;
			}
		}
	}
}

int	cmd_parsing(t_bash *shell, t_lst_var **lst_var, int len)
{
	t_cmd_pos		pos;
	t_var 				v;

	(void)shell;
	pos.start_of_arg = 0;
	pos.start_of_str = 0;
	pos.start_of_char = 0;
	pos.end_of_arg = 0;
	pos.end_of_str = 0;
	pos.end_of_char = 0;
	cmd_get_end_arg(lst_var, len, &v, &pos);
	return (1);
}

