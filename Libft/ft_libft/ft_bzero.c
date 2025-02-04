/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:15:03 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/22 13:32:46 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}

/*
int	main(void)
{
	size_t	byte;
	char	l[] = "Hello_World";
	char	t[] = "Hello_World";
	int		j;
	int		k;

	byte = 4;
	k = 0;
	j = 0;
	while (l[k] != '\0')
		k++;
	ft_bzero(l, byte);
	while (j < k)
	{
		printf("%c", l[j]);
		j++;
	}
	printf("\n-------\n");
	byte = 4;
	k = 0;
	j = 0;
	while (t[k] != '\0')
		k++;
	bzero(t, byte);
	while (j < k)
	{
		printf("%c", t[j]);
		j++;
	}
	return (0);
}
*/
