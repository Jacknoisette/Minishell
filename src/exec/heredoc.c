/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:56:24 by tgoudman          #+#    #+#             */
/*   Updated: 2025/02/05 11:27:46 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	heredoc(t_bash *shell, t_cmd *cmd)
{
	int		fd;
	char	*input;

	(void)shell;
	fd = open("heredoc00.txt", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd == -1)
		return (perror("Erreur lors de l'ouverture du fichier"));
	while (1)
	{
		input = readline("heredoc> ");
		if (input == NULL)
		{
			printf("!!here-document delimited by end-of-file (wanted `%s')!!\n",
				cmd->args[1]);
			break ;
		}
		if (!*input)
			free(input);
		if (ft_strcmp(input, cmd->args[1]) == 0)
			break ;
		ft_putendl_fd(input, fd);
	}
	close(fd);
}
