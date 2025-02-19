/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_remake2_var.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:04:36 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/19 13:09:13 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*quote_add_var(char *input, char chr, char quote, int mod)
{
	if (input == NULL)
		return (NULL);
	if (mod == 2)
		input = ft_charjoin(input, chr);
	if (input == NULL)
		return (NULL);
	if (quote == 39)
	{
		input = ft_charjoin(input, 34);
		if (input == NULL)
			return (NULL);
	}
	else if (quote == 34)
	{
		input = ft_charjoin(input, 39);
		if (input == NULL)
			return (NULL);
	}
	if (mod == 1)
		input = ft_charjoin(input, chr);
	return (input);
}

char	*quote_case_var(t_lst_var **tmp, char *input, int *i)
{
	char		quote;

	quote = (*tmp)->string[*i];
	input = quote_add_var(input, (*tmp)->string[*i], quote, 1);
	if (input == NULL)
		return (NULL);
	(*i)++;
	while ((*tmp)->string[*i] != '\0' && ((*tmp)->string[*i] != quote))
	{
		input = ft_charjoin(input, (*tmp)->string[*i]);
		if (input == NULL)
			return (NULL);
		(*i)++;
	}
	input = quote_add_var(input, (*tmp)->string[*i], quote, 2);
	if (input == NULL)
		return (NULL);
	return (input);
}

char	*var_case(t_lst_var **tmp, char *input)
{
	int			i;

	i = 0;
	input = quote_add(tmp, input);
	if (input == NULL)
		return (NULL);
	while ((*tmp)->string[i] != '\0')
	{
		if ((*tmp)->string[i] == 39 || (*tmp)->string[i] == 34)
			input = quote_case_var(tmp, input, &i);
		else
			input = ft_charjoin(input, (*tmp)->string[i]);
		i++;
	}
	input = quote_add(tmp, input);
	input = space_add(tmp, input);
	return (input);
}
