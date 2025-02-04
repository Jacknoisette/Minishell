/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:15:03 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/22 13:52:07 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*source1;
	const unsigned char	*source2;
	size_t				i;

	i = 0;
	source1 = (const unsigned char *) s1;
	source2 = (const unsigned char *) s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (source1[i] != source2[i])
			return (source1[i] - source2[i]);
		i++;
	}
	return (0);
}

/*
int	main(int argc, char *argv[])
{
	size_t	b;
	void	*l1;
	char	*l2;
	int		ft_memcmptest;

	b = 9;
	argv = argv;
	argc = argc;
	l1 = "01";
	l2 = "0";
	b = 1;
	ft_memcmptest = ft_memcmp(l1, l2, b);
	printf("%d,", ft_memcmptest);
	printf("%d,\n", memcmp(l1, l2, b));
	l1 = "nnnnaaaaaa";
	l2 = "nnnnaa";
	b = 10;
	ft_memcmptest = ft_memcmp(l1, l2, b);
	printf("%d,", ft_memcmptest);
	printf("%d,\n", memcmp(l1, l2, b));
	l1 = "nnnnaa";
	l2 = "nnnnaaaaaa";
	b = 10;
	ft_memcmptest = ft_memcmp(l1, l2, b);
	printf("%d,", ft_memcmptest);
	printf("%d,\n", memcmp(l1, l2, b));
	l1 = "nnnnaa";
	l2 = "nnnnbb";
	b = 3;
	ft_memcmptest = ft_memcmp(l1, l2, b);
	printf("%d,", ft_memcmptest);
	printf("%d,\n", memcmp(l1, l2, b));
	l1 = " ";
	l2 = " ";
	b = 2;
	ft_memcmptest = ft_memcmp(l1, l2, b);
	printf("%d,", ft_memcmptest);
	printf("%d,\n", memcmp(l1, l2, b));
	l1 = "hello123";
	l2 = "hello123";
	b = 9;
	ft_memcmptest = ft_memcmp(l1, l2, b);
	printf("%d,", ft_memcmptest);
	printf("%d,\n", memcmp(l1, l2, b));
	l1 = "abcd";
	l2 = "rrcd";
	b = 0;
	ft_memcmptest = ft_memcmp(l1, l2, b);
	printf("%d,", ft_memcmptest);
	printf("%d,\n", memcmp(l1, l2, b));
	l1 = "";
	l2 = "okokokokokok";
	b = 12;
	ft_memcmptest = ft_memcmp(l1, l2, b);
	printf("%d,", ft_memcmptest);
	printf("%d,\n", memcmp(l1, l2, b));
	l1 = "bon";
	l2 = "bon4";
	ft_memcmptest = ft_memcmp(l1, l2, 2);
	printf("%d,", ft_memcmptest);
	printf("%d\n", memcmp(l1, l2, 2));
	l1 = "nnnnaa";
	l2 = "nnnnaaa";
	b = 122;
	ft_memcmptest = ft_memcmp(l1, l2, b);
	printf("%d,", ft_memcmptest);
	printf("%d,\n", memcmp(l1, l2, b));
	return (0);
}
*/
