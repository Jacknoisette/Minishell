/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:46:07 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/22 13:47:00 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	s;
	int	n;

	i = 0;
	s = 0;
	n = 0;
	if ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
	{
		while (((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
			i++;
	}
	if ((nptr[i] == '+' && ++s) || (nptr[i] == '-' && --s))
		i++;
	else
		s = 1;
	if ((nptr[i] != '\0') && nptr[i] >= 48 && nptr[i] <= 57)
	{
		while ((nptr[i] != '\0' && nptr[i] >= 48 && nptr[i] <= 57))
		{
			n = (n * 10) + (nptr[i] - '0');
			i++;
		}
	}
	return (n *= s);
}

/*
int	main(void)
{
	char	*str1;
	char	*str2;
	char	*str3;

	str1 = " 12837628";
	printf("%d\n", ft_atoi(str1));
	printf("%d\n", atoi(str1));
	str2 = "    -1234500000000000";
	printf("%d\n", ft_atoi(str2));
	printf("%d\n", atoi(str2));
	str3 = "  \n-12";
	printf("%d\n", ft_atoi(str3));
	printf("%d\n", atoi(str3));
}
*/
