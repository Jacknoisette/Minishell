/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:08:33 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/27 13:25:11 by jdhallen         ###   ########.fr       */
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

char	*create_heredoc_name(int hd_numb)
{
	char		*heredoc;
	char		*temp1;
	char		*temp2;

	temp1 = ft_strdup("heredoc");
	temp2 = ft_itoa(hd_numb);
	if (!temp1 || !temp2)
		return (NULL);
	heredoc = ft_strjoin(temp1, temp2);
	free(temp1);
	free(temp2);
	return (heredoc);
}

t_lst_fd	*create_new_node_fd(char *name, char type, char *limit)
{
	t_lst_fd	*new_node;
	static int	hd_numb = 0;
	char		*heredoc;

	new_node = malloc(sizeof(t_lst_fd));
	if (!new_node)
		return (NULL);
	new_node->type = type;
	if (new_node->type == 'h')
	{
		heredoc = create_heredoc_name(hd_numb);
		while (access(heredoc, F_OK) != -1)
		{
			hd_numb++;
			free(heredoc);
			heredoc = create_heredoc_name(hd_numb);
		}
		new_node->name = heredoc;
		hd_numb++;
	}
	else
		new_node->name = ft_strdup(name);
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
