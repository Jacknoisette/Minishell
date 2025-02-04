/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:15:03 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/22 13:59:55 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/*
int	main(int argc, char *argv[])
{
	unsigned int	v;
	size_t			b;
	char			*l;

	v = 0x5A;
	b = 2;
	l = argv[argc - 1];
	ft_memset(l, v, b);
	printf("%s\n", l);
	v = 0x5A;
	b = 2;
	l = argv[argc - 1];
	memset(l, v, b);
	printf("%s\n", l);
	return (0);
}
*/
