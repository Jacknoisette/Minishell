/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:13:44 by jdhallen          #+#    #+#             */
/*   Updated: 2025/01/06 10:12:18 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_g(const char *s, int c)
{
	int	i;

	i = 0;
	if ((unsigned char)c == '\0')
	{
		while (s[i] != '\0')
			i++;
		return ((char *)s + i);
	}
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*ft_strdup_g(const char *s)
{
	char	*store;
	int		l;
	int		i;

	l = 0;
	while (s[l] != '\0')
		l++;
	store = (char *)malloc((l + 1) * sizeof(char));
	if (store == NULL)
		return (NULL);
	i = 0;
	while (i < l)
	{
		store[i] = s[i];
		i++;
	}
	store[l] = '\0';
	return (store);
}

size_t	ft_strlen_g(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr_g(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*t;

	if (start >= ft_strlen_g(s))
	{
		t = malloc(1);
		if (t != NULL)
			t[0] = '\0';
		return (t);
	}
	if (ft_strlen_g(s) - start < len)
		t = (char *)malloc(((ft_strlen_g(s) - start) + 1) * (sizeof(char)));
	else
		t = (char *)malloc((len + 1) * (sizeof(char)));
	if (t == NULL)
		return (NULL);
	i = start;
	j = 0;
	while (s[i] != '\0' && j < len)
		t[j++] = s[i++];
	t[j] = '\0';
	return (t);
}

char	*ft_strjoin_g(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;
	char	*t;

	i = 0;
	j = 0;
	l = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	t = (char *)malloc((i + j + 1) * (sizeof(char)));
	if (t == NULL)
		return (NULL);
	k = -1;
	while (++k < i)
		t[k] = s1[k];
	t[k] = s2[l];
	while (k < i + j)
		t[++k] = s2[++l];
	t[k] = '\0';
	return (t);
}
