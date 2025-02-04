/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexamaj_n.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:13:01 by jdhallen          #+#    #+#             */
/*   Updated: 2025/01/06 09:18:59 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexamaj_n(int fd, unsigned int n)
{
	unsigned int	i;
	char			c;
	char			*hex;

	i = 0;
	hex = "0123456789ABCDEF";
	if (n >= 16)
		i += ft_puthexamaj_n(fd, n / 16);
	i ++;
	c = (hex[n % 16]);
	write(fd, &c, 1);
	return (i);
}

// int main(void)
// {
//     int i;
//     i = ft_puthexamaj_n(-15);
//     printf("\n%d\n", i);
// }
