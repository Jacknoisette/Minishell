/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:45:38 by tgoudman          #+#    #+#             */
/*   Updated: 2025/02/18 13:09:02 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_line_lst(t_lst *lst)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	if (!lst)
		return (-1);
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		++i;
	}
	return (i);
}

char	**lst_to_tab(t_lst *lst)
{
	t_lst	*tmp;
	char	*name;
	char	*result;
	char	**tab;
	int		i;

	i = 0;
	tmp = lst;
	i = count_line_lst(lst);
	tab = malloc(sizeof(char *) * (i + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (tmp)
	{
		name = ft_strjoin(tmp->name, "=");
		result = ft_strjoin(name, tmp->data);
		tab[i] = result;
		free(name);
		tmp = tmp->next;
		++i;
	}
	tab[i] = NULL;
	return (tab);
}

void	print_tabs(char **str, char *s)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("%s %i = %s\n", s, i, str[i]);
		i++;
	}
}

int	count_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		++i;
	return (i);
}

char	**join_tab(char **tab_dst, char **tab_src)
{
	int		tab_len;
	char	**join;
	int		i;
	int		j;

	j = 0;
	i = 0;
	tab_len = count_tab(tab_src) + count_tab(tab_src) + 1;
	join = malloc(sizeof(char *) * tab_len);
	if (!join)
		return (NULL);
	while (tab_src[i] != NULL)
	{
		join[i] = tab_src[i];
		++i;
	}
	while (tab_dst[j] != NULL)
	{
		join[i + j] = tab_dst[j];
		j++;
	}
	return (join);
}
