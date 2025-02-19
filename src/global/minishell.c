/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:00:43 by tgoudman          #+#    #+#             */
/*   Updated: 2025/02/14 11:40:33 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_minishell(t_bash *shell, char **env)
{
	char				*input;
	int					sig_return;

	init_struct(shell, env);
	while (1)
	{
		input = readline("Input : ");
		sig_return = return_signal(0, 0);
		if (sig_return == 130)
			shell->prev_return = sig_return;
		sig_return = 0;
		if (input == NULL)
			return (free_list(&shell->lst_env),
				ft_printf(1, "exit\n"), 0);
		if (!*input)
		{
			free(input);
			continue ;
		}
		add_history(input);
		cmd_manager(shell, input);
	}
	return (rl_clear_history(), 0);
}

// char *test = ft_strjoin(getenv("USER"), getcwd(NULL, 0));
// char *test2 = ft_strjoin(test, " : ");