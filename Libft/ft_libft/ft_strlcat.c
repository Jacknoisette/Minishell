/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:23:16 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/22 14:07:49 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ls;
	size_t	ld;

	ls = 0;
	ld = 0;
	while (src[ls] != '\0')
		ls++;
	while (dst[ld] != '\0')
		ld++;
	if (ld >= size)
		return (ls + size);
	i = ld;
	while (src[i - ld] && i < size - 1)
	{
		dst[i] = src[i - ld];
		i++;
	}
	dst[i] = '\0';
	return (ld + ls);
}

/*
int	main(int argc, char *argv[])
{
	size_t	b;
	char	*l;
	char	cl[9] = "bonjour";

	b = 11;
	l = "123456789";
	argv = argv;
	argc = argc;
	printf("%s\n", l);
	printf("%s\n", cl);
	printf("%ld\n", ft_strlcat(cl, l, b));
	printf("%s\n", l);
	printf("%s\n", cl);
	printf("____\n");
}
*/
