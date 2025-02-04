/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:06:55 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/04 12:09:51 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_lst	*create_new_node(char *data, char *name)
{
	t_lst	*new_node;

	new_node = malloc(sizeof(t_lst));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->name = name;
	new_node->next = NULL;
	return (new_node);
}

void	list_add_back(t_lst **list, t_lst *new_node)
{
	t_lst *tmp;

	tmp = *list;
	if (*list == NULL)
	{
		*list = new_node;
		return;
	}
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
	new_node->next = NULL;
}

char	*get_name(char *str)
{
	char	*name;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	name = malloc(sizeof(char) * (len + 1));
	if (!name)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == '=')
			break ;
		name[i] = str[i];
		++i;
	}
	name[i] = '\0';
	return (name);
}

char	*get_data(char *str)
{
	char	*data;

	data = ft_strdup(ft_strchr(str, '=') + 1);
	if (!data)
		return (NULL);
	return (data);
}

void	ft_printf_list(t_lst **list, int output)
{
	t_lst	*tmp;

	tmp = *list;
	while (tmp)
	{
		ft_printf(output, "%s=%s\n", tmp->name, tmp->data);
		tmp = tmp->next;
	}
}

void	init_env(t_bash *shell, char **env)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	shell->lst_env = NULL;
	while (env[i] != NULL)
	{
		tmp = create_new_node(get_data(env[i]), get_name(env[i]));
		if (!tmp)
		{
			free_list(&shell->lst_env);
			return ;
		}
		list_add_back(&shell->lst_env, tmp);
		++i;
	}
}
