/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:39:07 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/22 14:00:31 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	i;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	i = (n % 10) + '0';
	write(fd, &i, 1);
}

/*
int	main(void)
{
	ft_putnbr_fd(-314, 1);
	printf("\n");
	ft_putnbr_fd(0x10, 1);
	return (0);
}
*/
