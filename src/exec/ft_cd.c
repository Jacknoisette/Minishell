/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:20:12 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/27 13:04:41 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	cmd_count_args(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->args[i] != NULL)
		i++;
	return (i);
}

void	cd_pwd_update(t_bash *shell)
{
	t_lst	*temp;

	temp = shell->lst_env;
	while (temp != NULL && ft_strcmp(temp->name, "PWD") != 0)
		temp = temp->next;
	if (temp != NULL)
	{
		free(temp->data);
		temp->data = getcwd(NULL, 0);
	}
}

int	better_chdir(t_bash *shell, char *str)
{
	if (chdir(str) != 0)
		return (FALSE);
	cd_pwd_update(shell);
	return (TRUE);
}

int	cd_home_case(t_bash *shell)
{
	t_lst	*temp;

	temp = shell->lst_env;
	while (temp != NULL && ft_strcmp(temp->name, "HOME") != 0)
		temp = temp->next;
	if (temp != NULL)
	{
		if (better_chdir(shell, temp->data) == FALSE)
		{
			ft_printf(2, "minishell: cd: %s: %s\n",
				temp->data, strerror(errno));
			return (shell->prev_return = 1, FALSE);
		}
	}
	else
	{
		ft_printf(2, "minishell: cd: HOME not set\n");
		return (shell->prev_return = 1, FALSE);
	}
	return (TRUE);
}

int	ft_cd(t_bash *shell, t_cmd *cmd, int output)
{
	if (cmd->name == NULL)
		return (FALSE);
	if (cmd_count_args(cmd) > 2)
		return (shell->prev_return = 1, FALSE);
	if (cmd->args[1] == NULL)
	{
		if (cd_home_case(shell) == FALSE)
			return (FALSE);
	}
	else
	{
		if (ft_strcmp(cmd->args[1], "-") == 0)
			ft_pwd(shell, cmd, output);
		else if (better_chdir(shell, cmd->args[1]) == FALSE)
		{
			ft_printf(2, "minishell: cd: %s: %s\n",
				cmd->args[1], strerror(errno));
			return (shell->prev_return = 1, FALSE);
		}
	}
	return (shell->prev_return = 0, TRUE);
}
