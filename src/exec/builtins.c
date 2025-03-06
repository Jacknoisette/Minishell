/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:32:57 by jdhallen          #+#    #+#             */
/*   Updated: 2025/03/03 11:54:00 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// int	ft_cd(t_bash *shell, t_cmd *cmd, int output)
// {
// 	(void)output;
// 	if (cmd->name == NULL)
// 		return (0);
// 	if (cmd->args[1] == NULL)
// 		chdir(getenv("HOME"));
// 	else
// 	{
// 		if (chdir(cmd->args[1]) != 0)
// 		{
// 			ft_printf(2, "minishell: cd: %s: %s\n",
// 				cmd->args[1], strerror(errno));
// 			return (shell->prev_return = 1, 1);
// 		}
// 	}
// 	return (shell->prev_return = 0, 0);
// }

int	ft_pwd(t_bash *shell, t_cmd *cmd, int output)
{
	char	*pathname;

	(void)cmd;
	pathname = getcwd(NULL, 0);
	if (pathname == NULL)
		return (ft_printf(2, "pwd: %s\n", strerror(errno)),
			shell->prev_return = 1, 1);
	ft_printf(output, "%s\n", pathname);
	free(pathname);
	return (shell->prev_return = 0, 0);
}

int	ft_env(t_bash *shell, t_cmd *cmd, int output)
{
	(void)cmd;
	ft_printf_list(&shell->lst_env, output);
	shell->prev_return = 0;
	return (0);
}

void	init_func(t_func *builtin)
{
	builtin[0].name = "echo";
	builtin[0].exec = ft_echo;
	builtin[0].rtn = 0;
	builtin[1].name = "cd";
	builtin[1].exec = ft_cd;
	builtin[1].rtn = 0;
	builtin[2].name = "pwd";
	builtin[2].exec = ft_pwd;
	builtin[2].rtn = 0;
	builtin[3].name = "export";
	builtin[3].exec = ft_export;
	builtin[3].rtn = 0;
	builtin[4].name = "unset";
	builtin[4].exec = ft_unset;
	builtin[4].rtn = 0;
	builtin[5].name = "shell";
	builtin[5].exec = ft_env;
	builtin[5].rtn = 0;
	builtin[6].name = "exit";
	builtin[6].exec = ft_exit;
	builtin[6].rtn = 0;
}
