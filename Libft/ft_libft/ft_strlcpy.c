/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:23:16 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/22 14:07:58 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ls;

	i = 0;
	ls = 0;
	while (src[ls] != '\0')
		ls++;
	if (size == 0)
		return (ls);
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ls);
}
/*
int	main(int argc, char *argv[])
{
	size_t	b;
	char	*l;
	char	cl[100] = "bonjour";

	b = 1000;
	l = "123456789";
	argv = argv;
	argc = argc;
	printf("%s\n", (char *)l);
	printf("%s\n", cl);
	printf("%ld\n", ft_strlcpy(cl, l, b));
	printf("%s\n", (char *)l);
	printf("%s\n", cl);
	printf("____\n");
}
*/
