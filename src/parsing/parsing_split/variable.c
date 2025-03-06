/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:50:54 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/27 13:02:48 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*var_check(t_bash *shell, char *str, t_lst_var *node, int *return_value)
{
	if (str[0] != '$')
		return (ft_strdup(str));
	if (str[1] == '?')
		return (ft_itoa(shell->prev_return));
	if (str[1] == '\0' && node->next != NULL)
		if (node->next->is_squote != node->is_squote)
			return (ft_strdup(""));
	if (!(ft_isalpha(str[1]) || str[1] == '_'))
		return (ft_strdup(str));
	if (str[1] == '\0')
		return (ft_strdup("$"));
	*return_value = TRUE;
	return (NULL);
}

char	*var_find(t_bash *shell, char *var, char *after, t_lst_var **node)
{
	t_lst		*search;
	char		*tmp;

	search = shell->lst_env;
	while (search != NULL)
	{
		if (ft_strcmp_var(search->name, var) == 0)
		{
			tmp = ft_strdup(search->data);
			after_case(after, node);
			return (free(var), free(after), tmp);
		}
		search = search->next;
	}
	tmp = ft_strdup("");
	after_case(after, node);
	return (free(var), free(after), tmp);
}

char	*return_var(t_bash *shell, char *str, t_lst_var **node)
{
	char	*str_check;
	char	*var;
	char	*after;
	int		var_len;
	int		return_value;

	return_value = FALSE;
	str_check = var_check(shell, str, *node, &return_value);
	if (return_value != TRUE)
		return (str_check);
	var_len = 0;
	while (str[var_len + 1] && (ft_isalnum(str[var_len + 1])
			|| str[var_len + 1] == '_' ))
		var_len++;
	var = ft_substr(str, 1, var_len);
	if (!var)
		return (NULL);
	after = ft_strdup(str + var_len + 1);
	if (!after)
		return (free(var), NULL);
	return (var_find(shell, var, after, node));
}

void	demolish_var_core(t_bash *shell, t_lst_var **node, int *is_var)
{
	char	*var;

	var = return_var(shell, (*node)->string, node);
	if (var != NULL && ft_strcmp(var, (*node)->string) != 0)
		*is_var = TRUE;
	free((*node)->string);
	if (var == NULL)
		(*node)->string = ft_strdup("");
	else
	{
		(*node)->string = var;
		if (*is_var == TRUE && (*node)->is_squote == FALSE)
			(*node)->is_var = TRUE;
	}
}

t_lst_var	*demolish_var(t_bash *shell, t_lst_var	*temp)
{
	t_lst_var	*node;
	int			is_var;

	node = temp;
	is_var = FALSE;
	while (node != NULL)
	{
		if (node->is_squote != 39)
			demolish_var_core(shell, &node, &is_var);
		node = node->next;
		is_var = FALSE;
	}
	return (temp);
}
