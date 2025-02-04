/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:32:18 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/22 13:57:55 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*s;
	size_t		i;
	char		*d;

	d = (char *)dest;
	s = (const char *) src;
	if (d == s)
		return (dest);
	if (d > s && d < s + n)
	{
		i = n;
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
		return (dest);
	}
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*
int	main(int argc, char *argv[])
{
	size_t	b;
	void	*l;
	char	cl1[100] = {'a'};
	char	cl2[100] = {'a'};

	b = 4;
	l = "123456789";
	argv = argv;
	argc = argc;
	printf("%s\n", (char *)l);
	printf("%s\n", cl1);
	ft_memmove(cl1, l, b);
	printf("%s\n", (char *)l);
	printf("%s\n", cl1);
	printf("____\n");
	l = "123456789";
	printf("%s\n", (char *)l);
	printf("%s\n", cl2);
	memmove(cl2, l, b);
	printf("%s\n", (char *)l);
	printf("%s\n", cl2);
	return (0);
}
*/
