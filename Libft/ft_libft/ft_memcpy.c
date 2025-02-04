/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:15:03 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/22 13:52:56 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((char *) dest == ((const char *) src))
		return (dest);
	while (i < n)
	{
		((char *) dest)[i] = ((const char *) src)[i];
		i++;
	}
	return (dest);
}

/*
int	main(int argc, char *argv[])
{
	size_t	b;
	void	*l;
	char	cl[100];

	b = 9;
	l = "123456789";
	argv = argv;
	argc = argc;
	printf("%s\n", (char *)l);
	printf("%s\n", cl);
	ft_memcpy(cl, l, b);
	printf("%s\n", (char *)l);
	printf("%s\n", cl);
	printf("____\n");
	l = "123456789";
	printf("%s\n", (char *)l);
	printf("%s\n", cl);
	memcpy(cl, l, b);
	printf("%s\n", (char *)l);
	printf("%s\n", cl);
	return (0);
}
*/
