/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_to_shell_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:00:04 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/25 13:31:08 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_new_cmd_core(t_lst_cmd *tmp_cmd, char **temp_char, t_var *v)
{
	if (tmp_cmd->arg[v->i].is_space == FALSE)
	{
		while (tmp_cmd->arg[v->i].str != NULL
			&& tmp_cmd->arg[v->i].is_space == FALSE)
		{
			*temp_char = ft_tmpjoin(tmp_cmd->arg[v->i].str, temp_char, 1);
			if (*temp_char == NULL)
				return (ERROR);
			v->i++;
		}
		if (tmp_cmd->arg[v->i].str != NULL)
		{
			*temp_char = ft_tmpjoin(tmp_cmd->arg[v->i].str, temp_char, 1);
			if (*temp_char == NULL)
				return (ERROR);
		}
	}
	else
	{
		*temp_char = ft_tmpjoin(tmp_cmd->arg[v->i].str, temp_char, 1);
		if (*temp_char == NULL)
			return (ERROR);
	}
	return (TRUE);
}

t_lst_arg	*ft_new_cmd(t_lst_cmd *tmp_cmd, int *len)
{
	t_lst_arg	*arg_lst;
	t_lst_arg	*arg;
	t_var		v;
	char		*temp_char;

	arg_lst = NULL;
	v.i = 0;
	v.j = 0;
	while (tmp_cmd->arg[v.i].str != NULL)
	{
		temp_char = ft_strdup("");
		if (temp_char == NULL)
			return (free_list_arg(&arg_lst), NULL);
		if (ft_new_cmd_core(tmp_cmd, &temp_char, &v) == ERROR)
			return (NULL);
		arg = create_new_node_arg(ft_strdup(temp_char));
		list_add_back_arg(&arg_lst, arg);
		free(temp_char);
		v.i++;
		v.j++;
	}
	return ((*len) = v.j, arg_lst);
}

char	**get_charpp_cmd(t_lst_cmd *tmp_cmd)
{
	t_lst_arg	*arg_lst;
	t_lst_arg	*arg;
	char		**args;
	int			len;
	int			i;

	len = 0;
	arg_lst = ft_new_cmd(tmp_cmd, &len);
	if (arg_lst == NULL)
		return (NULL);
	args = malloc((len + 1) * sizeof(char *));
	i = 0;
	arg = arg_lst;
	while (arg != NULL)
	{
		args[i] = ft_strdup(arg->str);
		if (args[i] == NULL)
			return (free_cmd(args), free_list_arg(&arg_lst), NULL);
		i++;
		arg = arg->next;
	}
	free_list_arg(&arg_lst);
	return (args[len] = NULL, args);
}

int	lst_cmd_to_cmd_tab(t_bash *shell, t_lst_cmd **lst_cmd)
{
	t_lst_cmd	*tmp_cmd;
	int			cmd_size;
	int			i;

	cmd_size = lst_cmd_len(shell, lst_cmd);
	if (cmd_size == ERROR)
		return (FALSE);
	shell->line.cmd = malloc((cmd_size + 1) * sizeof(t_cmd));
	if (shell->line.group == NULL)
		return (ERROR);
	i = 0;
	tmp_cmd = *lst_cmd;
	while (tmp_cmd != NULL)
	{
		shell->line.cmd[i].args = get_charpp_cmd(tmp_cmd);
		if (shell->line.cmd[i].args == NULL)
			return (ERROR);
		shell->line.cmd[i].input = STDIN_FILENO;
		shell->line.cmd[i].output = STDOUT_FILENO;
		i++;
		tmp_cmd = tmp_cmd->next;
	}
	return (TRUE);
}
