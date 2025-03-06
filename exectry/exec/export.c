/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:24:23 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/12 20:26:56 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	insert_export(t_bash *shell, char *str)
{
	t_lst	*tmp;
	t_lst	*new;
	char	*tmp_str;

	tmp = shell->lst_env;
	shell->prev_return = 0;
	while (tmp)
	{
		tmp_str = get_name(str);
		if (ft_strcmp(tmp->name, tmp_str) == 0)
		{
			tmp->data = ft_strdup(get_data(str));
			free(tmp_str);
			return ;
		}
		tmp = tmp->next;
		free(tmp_str);
	}
	new = create_new_node(get_data(str),
			get_name(str));
	list_add_back(&shell->lst_env, new);
}

int	check_args_export(t_bash *shell, char *str)
{
	int	i;

	i = 0;
	if (ft_isalpha(str[i]) == 0 && str[i] != '_')
	{
		printf("\033[31m'%s': not a valid identifier.\033[0m\n", str);
		shell->prev_return = 1;
		return (1);
	}
	while (str[i] != '\0')
	{
		if (str[i] == '=')
			break ;
		if (ft_isalnum(str[i]) == 0 && str[i] != '_')
		{
			ft_printf(1, "\033[31m'%s': not a valid identifier\033[0m\n", str);
			shell->prev_return = 1;
			return (1);
		}
		++i;
	}
	return (0);
}

int	ft_export(t_bash *shell, t_cmd *cmd, int output)
{
	int	i;

	i = 1;
	(void)output;
	while (cmd->args[i])
	{
		while (ft_strchr(cmd->args[i], '=') == NULL)
		{
			++i;
			if (cmd->args[i] == NULL)
			{
				shell->prev_return = 0;
				return (0);
			}
		}
		if (check_args_export(shell, cmd->args[i]) == 1)
			return (1);
		insert_export(shell, cmd->args[i]);
		++i;
	}
	shell->prev_return = 0;
	return (0);
}
