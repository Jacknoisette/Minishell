/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:59:04 by jdhallen          #+#    #+#             */
/*   Updated: 2025/01/27 12:28:13 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

static void	freeall(char **l, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(l[i]);
		i++;
	}
	free(l);
}

static size_t	count_segment(const char *str, const char c)
{
	size_t	ts;
	size_t	x;
	int		in_sub;

	x = 0;
	ts = 0;
	in_sub = 0;
	while (str[x] != '\0')
	{
		if (str[x] != c && in_sub == 0)
		{
			in_sub = 1;
			ts++;
		}
		else if (c == str[x])
			in_sub = 0;
		x++;
	}
	return (ts);
}

static size_t	segment_length(const char *str, const char c, size_t *start)
{
	size_t	x;

	x = 0;
	while (str[*start] != '\0' && str[*start] == c)
		(*start)++;
	while (str[*start] != '\0' && str[*start] != c)
	{
		x++;
		(*start)++;
	}
	return (x);
}

static char	*alloc_segment(const char *str, char c, size_t *j)
{
	size_t	k;
	size_t	len;
	char	*t;

	len = segment_length(str, c, j);
	t = (char *)malloc((len + 1) * sizeof(char));
	if (t == NULL)
		return (NULL);
	k = 0;
	while (k < len)
	{
		t[k] = str[*j - len + k];
		k++;
	}
	t[k] = '\0';
	return (t);
}

char	**ft_split(char const *str, char c)
{
	size_t	i;
	size_t	j;
	char	**list;

	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (str[0] == '\0')
	{
		list = (char **)malloc(sizeof(char *));
		if (list == NULL)
			return (NULL);
		return (list[0] = NULL, list);
	}
	list = (char **)malloc((count_segment(str, c) + 1) * sizeof(char *));
	if (list == NULL)
		return (NULL);
	while (i < count_segment(str, c))
	{
		list[i] = alloc_segment(str, c, &j);
		if (list[i++] == NULL)
			return (freeall(list, i - 1), NULL);
	}
	return (list[i] = NULL, list);
}

/*
int	main(void)
{
	char	*so1;
	char	so2;
	char	**so3;
	size_t	p;

	so1 = "\0 abbsv\0gdv";
	so2 = '\0';
	p = 0;
	so3 = ft_split(so1, so2);
	printf("Avant : %s, %c \n", so1, so2);
	while (so3[p] != NULL)
	{
		printf("%s", so3[p]);
		printf("\n");
		p++;
	}
	printf("\n");
	free(so3);
	return (0);
}
*/
