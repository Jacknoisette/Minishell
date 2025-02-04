/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:14:10 by jdhallen          #+#    #+#             */
/*   Updated: 2025/01/06 09:18:41 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_n(int fd, char c)
{
	write(fd, &c, 1);
	return (1);
}

// int	main(void)
// {
// 	char st = 'h';
// 	printf("%d\n", ft_putchar_n(st));
// }
