/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:46:04 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/22 13:33:45 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	size_t	m;
	void	*store;

	i = 0;
	m = nmemb * size;
	if (m == 0)
		return (malloc(0));
	if (4294967295 / size >= nmemb)
	{
		store = (void *)malloc(m);
		if (store == NULL)
			return (NULL);
		while (i < m)
		{
			((unsigned char *)store)[i] = 0;
			i++;
		}
	}
	else
		return (NULL);
	return (store);
}

/*
int	main(void)
{
	size_t	b;
	size_t	k;
	size_t	j;
	char	*s;

	j = 0;
	b = 2;
	k = 1;
	s = ft_calloc(b, k);
	while (j < strlen(s))
	{
		printf("%c", s[j]);
		j++;
	}
	free(s);
	j = 0;
	b = 1;
	k = 4;
	s = calloc(b, k);
	while (j < strlen(s))
	{
		printf("%c", s[j]);
		j++;
	}
	free(s);
}
*/
