/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:45:02 by tgoudman          #+#    #+#             */
/*   Updated: 2025/02/12 20:31:27 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*search_file(t_line *line, int index_cmd)
{
	char	*file;
	int		count;
	int		i;

	i = 0;
	count = 0;
	file = NULL;
	while (line->group[i] != NULL && index_cmd > count)
	{
		if (line->group[i][0] == '|')
			count++;
		i++;
	}
	while (line->group[i] != NULL && line->group[i][0] != '|')
	{
		if (line->group[i][0] == '!')
		{
			file = line->group[i];
			i++;
		}
		else
			i++;
	}
	return (file);
}
