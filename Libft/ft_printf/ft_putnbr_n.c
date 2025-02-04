/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:14:03 by jdhallen          #+#    #+#             */
/*   Updated: 2025/01/06 09:19:34 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_n(int fd, int n)
{
	char	c;
	int		i;

	i = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
		i++;
	}
	if (n >= 10)
		i += ft_putnbr_n(fd, n / 10);
	i ++;
	c = (n % 10) + '0';
	write(fd, &c, 1);
	return (i);
}

// int main(void)
// {
//     int i;

//     i = ft_putnbr_n(-1400);
//     printf("\n%d\n", i);
// }
