/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:12:48 by jdhallen          #+#    #+#             */
/*   Updated: 2025/01/06 09:20:19 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_puthexa_n(int fd, unsigned long n)
{
	char	*hex;
	char	c;
	int		i;

	i = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
		i += ft_puthexa_n(fd, n / 16);
	i ++;
	c = (hex[n % 16]);
	write(fd, &c, 1);
	return (i);
}

int	ft_putp_n(int fd, void *n)
{
	unsigned long	i;
	unsigned long	add;

	i = 0;
	if (!n)
		return (ft_putstr_n(fd, "(nil)"));
	add = (unsigned long)n;
	i += ft_putstr_n(fd, "0x");
	i += ft_puthexa_n(fd, add);
	return (i);
}

// int main(void)
// {
//     int i;
// 	char *str = "hello";

//     i = ft_putp_n(str);
//     printf("\n%d\n", i);
// }
