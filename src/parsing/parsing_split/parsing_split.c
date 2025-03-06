/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:15:13 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/27 13:12:16 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_lst_var	**temp_alloc(t_bash *shell, int *len)
{
	t_lst_var	**temp;

	while (shell->line.group[*len] != NULL)
		(*len)++;
	temp = malloc(((*len) + 1) * sizeof(t_lst_var *));
	if (temp == NULL)
		return (NULL);
	temp[*len] = NULL;
	return (temp);
}

int	parsing_split_part1(t_bash *shell, t_lst_var **result)
{
	t_lst_var	**temp;
	int			i;
	int			len;

	len = 0;
	temp = temp_alloc(shell, &len);
	if (temp == NULL)
		return (ERROR);
	i = 0;
	while (i < len)
	{
		temp[i] = temp_creation(shell->line.group[i]);
		if (temp[i] == NULL)
			return (free_list_point(&temp, len), ERROR);
		temp[i] = demolish_var(shell, temp[i]);
		if (temp[i] == NULL)
			return (free_list_point(&temp, len), ERROR);
		i++;
	}
	*result = convert_lst(temp);
	if (*result == NULL)
		return (free_list_point(&result, len), ERROR);
	return (free_list_point(&temp, len), TRUE);
}

int	parsing_split_part2(t_bash *shell, t_lst_var **result, char **input)
{
	t_lst_var	**temp;
	int			i;
	int			len;

	len = 0;
	free_cmd(shell->line.group);
	if (search_for_quote(shell, *input) == ERROR)
		return (free(*input), ERROR);
	free(*input);
	temp = temp_alloc(shell, &len);
	if (temp == NULL)
		return (ERROR);
	i = 0;
	while (i < len)
	{
		temp[i] = temp_creation(shell->line.group[i]);
		if (temp[i] == NULL)
			return (free_list_point(&temp, len), ERROR);
		i++;
	}
	*result = convert_lst(temp);
	if (cmd_parsing(shell, *result) == ERROR)
		return (free_list_point(&temp, len), ERROR);
	return (free_list_point(&temp, len), TRUE);
}

int	parsing_split(t_bash *shell)
{
	t_lst_var	*result;
	char		*input;

	if (parsing_split_part1(shell, &result) == ERROR)
		return (ERROR);
	input = input_remake2(result);
	free_list_var(&result);
	if (input == NULL)
		return (ERROR);
	ft_printf(1, "input v3 : %s\n", input);
	if (input != NULL)
		if (parsing_split_part2(shell, &result, &input) == ERROR)
			return (ERROR);
	return (0);
}
