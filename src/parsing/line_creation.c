/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:00:14 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/17 10:40:28 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	skip_quote(char *input, int char_nbr, int i, int search_error)
{
	i++;
	while (input[i] != '\0' && input[i] != char_nbr)
		i++;
	if (search_error == 1 && input[i] == '\0')
		return (ft_printf(1, "\033[31mIncorrect quote\n\033[0m"), ERROR);
	return (i);
}

int	count_group(char *input, int count)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == ' ')
			count++;
		else if (input[i] == 34)
		{
			i = skip_quote(input, 34, i, 1);
			if (i == ERROR)
				return (ERROR);
		}
		else if (input[i] == 39)
		{
			i = skip_quote(input, 39, i, 1);
			if (i == ERROR)
				return (ERROR);
		}
		i++;
	}
	count += 1;
	return (count);
}

int	get_group_size(char *input, int i)
{
	int	size;

	size = i;
	while (input[i] != '\0' && input[i] != ' ')
	{
		if (input[i] == 34)
			i = skip_quote(input, 34, i, 0);
		else if (input[i] == 39)
			i = skip_quote(input, 39, i, 0);
		i++;
	}
	return (i - size);
}

int	create_group(t_bash *shell, char *input, int group_nbr, int pos)
{
	int	size;
	int	i;
	int	j;
	int	limit;

	pos = 0;
	i = 0;
	while (i < group_nbr)
	{
		j = 0;
		size = get_group_size(input, pos);
		limit = pos + size;
		shell->line.group[i] = malloc((size + 1) * sizeof(char));
		while (pos < limit)
		{
			shell->line.group[i][j] = input[pos];
			pos++;
			j++;
		}
		shell->line.group[i][j] = '\0';
		i++;
		pos++;
	}
	shell->line.group[i] = NULL;
	return (0);
}

int	search_for_quote(t_bash *shell, char *input)
{
	int	group_nbr;

	group_nbr = count_group(input, 0);
	if (group_nbr == ERROR)
		return (ERROR);
	shell->line.group = malloc((group_nbr + 1) * sizeof(char *));
	if (shell->line.group == NULL)
		return (ERROR);
	create_group(shell, input, group_nbr, 0);
	return (0);
}

	// ft_printf(1, "group_nbr %i\n", group_nbr);