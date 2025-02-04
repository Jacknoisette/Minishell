/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunnbr_n.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:13:18 by jdhallen          #+#    #+#             */
/*   Updated: 2025/01/06 09:20:47 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunnbr_n(int fd, unsigned int n)
{
	unsigned int	i;
	char			c;

	i = 0;
	if (n >= 10)
		i += ft_putunnbr_n(fd, n / 10);
	i ++;
	c = (n % 10) + '0';
	write(fd, &c, 1);
	return (i);
}

/*
int main(void)
{
    int i;

    i = ft_putunnbr_n(1400);
    printf("\n%d\n", i);
}
*/
