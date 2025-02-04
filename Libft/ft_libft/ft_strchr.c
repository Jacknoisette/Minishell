/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:15:03 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/22 14:06:51 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

char	*ft_strchr(const char *s, int c)
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

/*
int	main(int argc, char *argv[])
{
	char	*l;
	int		v;

	v = 'v';
	l = argv[argc - 1];
	printf("%p\n", ft_strchr(l, v));
	printf("%p\n", strchr(l, v));
	return (0);
}
*/
