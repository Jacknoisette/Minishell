/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:15:03 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/22 14:09:38 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if ((unsigned char)c == '\0')
	{
		return ((char *)s + i);
	}
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i--;
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
	printf("%p\n", ft_strrchr(l, v));
	printf("%p\n", strrchr(l, v));
	return (0);
}
*/
