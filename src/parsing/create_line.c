/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:08:33 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/19 11:24:42 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_lst_line	*create_new_node_line(char *param)
{
	t_lst_line	*new_node;

	new_node = malloc(sizeof(t_lst_line));
	if (!new_node)
		return (NULL);
	new_node->param = param;
	new_node->next = NULL;
	return (new_node);
}

void	list_add_back_line(t_lst_line **list, t_lst_line *new_node)
{
	t_lst_line	*tmp;

	tmp = *list;
	if (*list == NULL)
	{
		*list = new_node;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
	new_node->next = NULL;
}

t_lst_fd	*create_new_node_fd(char *name, char type, char *limit)
{
	static int	hd_numb = 0;
	t_lst_fd	*new_node;
	char		*nameh;

	new_node = malloc(sizeof(t_lst_fd));
	if (!new_node)
		return (NULL);
	new_node->type = type;
	if (new_node->type == 'h')
	{
		free(name);
		nameh = ft_strjoin(ft_strdup("heredoc"), ft_itoa(hd_numb));
		while (access(nameh, F_OK) != -1)
		{
			free(nameh);
			hd_numb++;
			nameh = ft_strjoin(ft_strdup("heredoc"), ft_itoa(hd_numb));
		}
		new_node->name = nameh;
		hd_numb++;
	}
	else
		new_node->name = ft_strjoin(ft_strdup("!"), ft_strdup(name));
	new_node->limit = limit;
	return (new_node->next = NULL, new_node);
}

void	list_add_back_fd(t_lst_fd **list, t_lst_fd *new_node)
{
	t_lst_fd	*tmp;

	tmp = *list;
	if (*list == NULL)
	{
		*list = new_node;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
	new_node->next = NULL;
}
