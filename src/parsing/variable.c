/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:50:54 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/06 14:04:57 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *var_find(t_bash *shell, char *var, char *after)
{
	t_lst	*node;
	char	*tmp;

	node = shell->lst_env;
	while (node != NULL)
	{
		if (ft_strcmp_var(node->name, var) == 0)
		{
			tmp = ft_strjoin(node->data, after);
			return (free(var), free(after), tmp);
		}
		node = node->next;
	}
	tmp = ft_strjoin("", after);
	return (free(var), free(after), tmp);
}

char *return_var_value(t_bash *shell, char *str, t_lst_var	*node)
{
	char	*var;
	char	*after;
	int		var_len;

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
	var_len = 0;
	while (str[var_len + 1] && (ft_isalnum(str[var_len + 1]) || str[var_len + 1] == '_' ))
		var_len++;
	var = ft_substr(str, 1, var_len);
	if (!var)
		return (NULL);
	after = ft_strdup(str + var_len + 1);
	if (!after)
		return (free(var), NULL);
	return (var_find(shell, var, after));
}

t_lst_var	*demolish_var(t_bash *shell, t_lst_var	*temp)
{
	t_lst_var	*node;
	char	*var;
	int		i;

	i = 0;
	node = temp;
	while (node != NULL)
	{
		if (node->is_squote != 39)
		{
			var = return_var_value(shell, node->string, node);
			free(node->string);
			if (var == NULL)
				node->string = ft_strdup("");
			else
				node->string = var;
		}
		node = node->next;
	}
	return (temp);
}

char *rebuild_temp(t_lst_var	*temp)
{
	t_lst_var	*node;
	char	*result;
	char	*temp_join;
	int		i;

	node = temp;
	result = ft_strdup("");
	if (result == NULL)
		return (NULL);
	i = 0;
	while (node != NULL)
	{
		temp_join = ft_strjoin(result, node->string);
		free(result);
		if (temp_join == NULL)
			return (NULL);
		result = temp_join;
		node = node->next;
	}
	return (result);
}

int	search_for_var(t_bash *shell)
{
	t_lst_var	**temp;
	t_lst_var	*result;
	int			i;
	int			len;

	len = 0;
	while (shell->line.group[len] != NULL)
		len++;
	temp = malloc((len + 1) * sizeof(t_lst_var *));
	if (temp == NULL)
		return (ERROR);
	temp[len] = NULL;
	i = 0;
	while (i < len)
	{
		temp[i] = temp_creation(shell->line.group[i]);
		if (temp[i] == NULL)
			return (free_list_point(&temp, len), free_cmd(shell->line.group), ERROR);
		temp[i] = demolish_var(shell, temp[i]);
		if (temp[i] == NULL)
			return (free_list_point(&temp, len), free_cmd(shell->line.group), ERROR);
		i++;
	}
	result = convert_lst(temp);
	cmd_parsing(shell, result);
	i = 0;
	while (i < len)
	{
		free(shell->line.group[i]);
		shell->line.group[i] = rebuild_temp(temp[i]);
		if (shell->line.group[i] == NULL)
			return (free_list_point(&temp, len), free_cmd(shell->line.group), ERROR);
		i++;
	}
	ft_printf(1, "test\n");
	free_list_point(&temp, len);
	return (0);
}

// temp = ft_sep(shell->line.group[i], '$');