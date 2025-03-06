/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:21:14 by tgoudman          #+#    #+#             */
/*   Updated: 2025/03/04 15:40:52 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_exit_signale(t_bash *shell, pid_t pid)
{
	int		status;
	pid_t	childpid;
	int		exit_status;
	int		signal_number;

	childpid = waitpid(pid, &status, 0);
	if (WIFEXITED(status))
	{
		exit_status = WEXITSTATUS(status);
		if (exit_status == 127)
			shell->prev_return = 127;
	}
	else if (WIFSIGNALED(status))
	{
		signal_number = WTERMSIG(status);
		shell->prev_return = 128 + signal_number;
	}
}
// fprintf(stderr, "Erreur d'exécution du programme enfant avec code 127\n");
// fprintf(stderr, "Le programme enfant a été tué signal %d\n", signal_number);