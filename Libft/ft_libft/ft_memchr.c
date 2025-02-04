/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:15:03 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/22 13:51:52 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)p[i] == (unsigned char)c)
			return (s + i);
		i++;
	}
	return (NULL);
}

/*
int	main(int argc, char *argv[])
{
	unsigned int	v;
	size_t			b;
	char			*l;

	v = 'Z';
	b = 3;
	l = argv[argc - 1];
	printf("%p\n", ft_memchr(l, v, b));
	v = 'Z';
	b = 3;
	l = argv[argc - 1];
	printf("%p\n", memchr(l, v, b));
	return (0);
}
*/
