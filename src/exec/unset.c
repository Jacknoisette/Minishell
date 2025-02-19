/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:58:16 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/12 20:27:20 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_lst	*delete_node(t_lst *lst, int n)
{
	t_lst	*prev;
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	prev = NULL;
	if (lst == NULL)
		return (NULL);
	while (tmp && i < n)
	{
		prev = tmp;
		tmp = tmp->next;
		i++;
	}
	if (tmp)
	{
		prev->next = tmp->next;
		free(tmp);
	}
	return (lst);
}

t_lst	*search_node(t_bash *shell, char *str)
{
	t_lst	*lst;
	int		i;

	i = 0;
	lst = shell->lst_env;
	if (ft_strcmp(lst->name, str) == 0)
	{
		lst = lst->next;
		return (lst);
	}
	while (lst)
	{
		if (ft_strcmp(lst->name, str) == 0)
			return (delete_node(shell->lst_env, i));
		lst = lst->next;
		i++;
	}
	return (shell->lst_env);
}

int	check_args_unset(t_bash *shell, char *str)
{
	int	i;

	i = 0;
	if ((str[i] < 'a' || str[i] > 'z') && ((str[i] < 'A' || str[i] > 'Z'))
		&& (str[i] != '_'))
	{
		printf("\033[31m unset: %s: invalid parameter name.\033[0m\n", str);
		shell->prev_return = 1;
		return (1);
	}
	while (str[i] != '\0')
	{
		if (ft_isalnum(str[i]) == 0 && str[i] != '_')
		{
			printf("\033[31m unset: %s: invalid parameter name.\033[0m\n", str);
			shell->prev_return = 1;
			return (1);
		}
		++i;
	}
	return (0);
}

int	ft_unset(t_bash *shell, t_cmd *cmd, int output)
{
	int	i;

	(void)output;
	i = 1;
	while (cmd->args[i])
	{
		if (check_args_unset(shell, cmd->args[i]) == 1)
		{
			shell->prev_return = 1;
			return (1);
		}
		shell->lst_env = search_node(shell, cmd->args[i]);
		++i;
	}
	shell->prev_return = 0;
	return (0);
}
