/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:00:43 by tgoudman          #+#    #+#             */
/*   Updated: 2025/02/03 18:09:09 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_minishell(t_bash *shell, char **env)
{
	struct sigaction	sa;
	char			    *input;
	int					sig_return;

	init_struct(shell, env);
	init_signale(&sa);
	if (sigaction(SIGINT, &sa, NULL) == -1)
		perror("Signal error");
	init_func(shell->func);
	while (1)
	{
		input = readline("Input: ");
		sig_return = return_signal(0, 0);
		if (sig_return == 130)
			shell->prev_return = sig_return;
		sig_return = 0;
		if (input == NULL)
		{
			ft_printf(1, "exit\n");
			return ;
		}
		if (!*input)
		{
			free(input);
			continue ;
		}
		add_history(input);
		cmd_manager(shell, input);
	}
	rl_clear_history();
}
