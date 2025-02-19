/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_remake2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:09:19 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/19 13:09:26 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*space_add(t_lst_var **tmp, char *input)
{
	char	*temp;

	if (input == NULL)
		return (NULL);
	if ((*tmp)->is_space == 1)
	{
		temp = input;
		input = ft_strjoin(temp, " ");
		free(temp);
	}
	return (input);
}

char	*quote_add(t_lst_var **tmp, char *input)
{
	char	*temp;

	if (input == NULL)
		return (NULL);
	if ((*tmp)->is_squote != FALSE)
	{
		temp = input;
		if ((*tmp)->is_squote == 34)
			input = ft_strjoin(temp, "\"");
		else if ((*tmp)->is_squote == 39)
			input = ft_strjoin(temp, "'");
		free(temp);
	}
	else if (is_bash_op((*tmp)->string[0], '*') == TRUE
		&& (*tmp)->is_var == TRUE)
	{
		temp = input;
		input = ft_strjoin(temp, "\"");
		free(temp);
	}
	return (input);
}

char	*input_core_remake2(t_lst_var **tmp, char *input)
{
	char		*temp;
	char		*temp2;

	input = quote_add(tmp, input);
	if (input == NULL)
		return (NULL);
	temp = input;
	temp2 = ft_strdup((*tmp)->string);
	input = ft_strjoin(temp, temp2);
	free(temp);
	free(temp2);
	input = quote_add(tmp, input);
	input = space_add(tmp, input);
	if (input == NULL)
		return (NULL);
	return (input);
}

char	*input_remake2(t_lst_var *lst_var)
{
	t_lst_var	*tmp;
	char		*input;
	int			id;

	id = 0;
	input = ft_strdup("");
	tmp = lst_var;
	while (tmp != NULL)
	{
		if (tmp->is_var == TRUE)
			input = var_case(&tmp, input);
		else
			input = input_core_remake2(&tmp, input);
		tmp = tmp->next;
		id++;
	}
	return (input = input_remake(input), input);
}
