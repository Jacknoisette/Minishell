/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_shell_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:42:51 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/07 15:44:00 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	lst_line_to_charpp(t_bash *shell, t_lst_line **lst_line)
{
	t_lst_line *tmp_line;
	int			line_size;
	int			i;

	line_size = 0;
	tmp_line = *lst_line;
	while (tmp_line != NULL)
	{
		tmp_line = tmp_line->next;
		line_size++;
	}
	free_cmd(shell->line.group);
	shell->line.group = malloc((line_size + 1) * sizeof(char *));
	if (shell->line.group == NULL)
		return (free_list_line(lst_line), ERROR);
	tmp_line = *lst_line;
	i = 0;
	while (tmp_line != NULL)
	{
		shell->line.group[i] = ft_strdup(tmp_line->param);
		if (shell->line.group[i] == NULL)
			return (free_list_line(lst_line), free_cmd(shell->line.group), ERROR);
		i++;
		tmp_line = tmp_line->next;
	}
	return (shell->line.group[i] = NULL, *lst_line = NULL, free_list_line(lst_line), TRUE);
}

t_lst_arg *ft_new_cmd(t_lst_cmd **tmp_cmd, int *len)
{
	t_lst_arg	*arg_lst;
	t_lst_arg	*arg;
	char		*temp_char;
	char		*tmp;

	arg_lst = NULL;
	while ((*tmp_cmd) != NULL)	
	{
		*len = 0;
		while ((*tmp_cmd)->arg[*len].str != NULL)
		{
			temp_char = ft_strdup("");
			if (temp_char == NULL)
				return (arg_lst);
			while ((*tmp_cmd)->arg[*len].is_space != FALSE)
			{
				tmp = temp_char;
				temp_char = ft_strjoin((*tmp_cmd)->arg[*len++].str, tmp);
				free(tmp);
			}
			arg = create_new_node_arg(temp_char);
			list_add_back_arg(&arg_lst, arg);
			free(temp_char);
			(*len)++;
		}
		(*tmp_cmd) = (*tmp_cmd)->next;
	}
	return (arg_lst);
}

char	**get_charpp_cmd(t_lst_cmd **tmp_cmd)
{
	t_lst_arg	*arg_lst;
	t_lst_arg	*arg;
	char		**args;
	int			len;
	int			i;
	
	len = 0;
	arg_lst = ft_new_cmd(tmp_cmd, &len);
	arg = arg_lst;
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
	return (args[len] = NULL, args);
}

int	lst_cmd_to_cmd_tab(t_bash *shell, t_lst_cmd **lst_cmd)
{
	t_lst_cmd	*tmp_cmd;
	int			cmd_size;
	int			i;

	cmd_size = 0;
	tmp_cmd = *lst_cmd;
	while (tmp_cmd != NULL)
	{
		tmp_cmd = tmp_cmd->next;
		cmd_size++;
	}
	free_cmd(shell->line.group);
	shell->line.cmd = malloc(cmd_size * sizeof(t_cmd));
	if (shell->line.group == NULL)
		return (ERROR);
	i = 0;
	tmp_cmd = *lst_cmd;
	while (tmp_cmd == NULL)
	{
		shell->line.cmd[i].args = get_charpp_cmd(&tmp_cmd);
		if (shell->line.cmd[i].args == NULL)
			return (free(shell->line.cmd), free_cmd(shell->line.cmd[i].args),
				free_list_cmd(lst_cmd), ERROR);
		i++;
	}
	return (shell->line.cmd_nbr = i, free_list_cmd(lst_cmd), TRUE);
}

int	convert_lst_to_line(t_bash *shell, t_lst_line **lst_line,
		t_lst_cmd **lst_cmd, t_lst_fd **lst_fd)
{
	int	i;

	i = 0;
	if (lst_line_to_charpp(shell, lst_line) == ERROR)
		return (ERROR);
	if (lst_cmd_to_cmd_tab(shell, lst_cmd) == ERROR)
		return (ERROR);
	shell->line.lst_fd = *lst_fd;
	ft_printf_list_fd(lst_fd, 1);
	ft_printf(1, "%s\n", shell->line.group[0]);
	ft_printf(1, "SHELL LINE GROUP : %t\n", shell->line.group);
	ft_printf_list_fd(&shell->line.lst_fd, 1);
	while (i < shell->line.cmd_nbr)
	{
		if (shell->line.cmd[i].args != NULL
			&& shell->line.cmd[i].args[0] != NULL)
		{
			shell->line.cmd->name = ft_strdup(shell->line.cmd[i].args[0]);
			if (shell->line.cmd[i].name == NULL)
				return (ERROR);
		}
		ft_printf(1, "CMD[%i] : %t\n", i, shell->line.cmd[i].args);
	}
	return (TRUE);
}
