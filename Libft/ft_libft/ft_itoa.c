/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:46:07 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/22 13:46:45 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

static char	*ft_alloc(int i, int n, int min)
{
	char	*c;

	c = (char *)malloc((i + 1) * sizeof(char));
	if (c == NULL)
		return (NULL);
	c[i] = '\0';
	if (n == 0)
		c[0] = '0';
	if (min == 1)
	{
		c[--i] = '8';
		n /= 10;
	}
	while (n)
	{
		c[--i] = (n % 10) + '0';
		n /= 10;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char	*c;
	int		i;
	int		s;
	int		k;
	int		min;

	min = 0;
	i = 1;
	s = 0;
	if (n == -2147483648)
	{
		min = 1;
		n += 1;
	}
	if (n < 0 && --s && ++i)
		n = -n;
	k = n;
	while ((k / 10) && ++i)
		k /= 10;
	c = ft_alloc(i, n, min);
	if (c == NULL)
		return (NULL);
	if (s == -1)
		c[0] = '-';
	return (c);
}

/*
int	main(void)
{
	int	str1;
	int	str2;
	int	str3;

	str1 = -2147483648;
	printf("%s\n", ft_itoa(str1));
	str2 = 1111212;
	printf("%s\n", ft_itoa(str2));
	str3 = 0;
	printf("%s\n", ft_itoa(str3));
}
*/
