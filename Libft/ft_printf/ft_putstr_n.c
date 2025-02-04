/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:12:39 by jdhallen          #+#    #+#             */
/*   Updated: 2025/01/28 10:58:21 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_n(int fd, char *str)
{
	int	i;

	i = 0;
	if (str == 0)
	{
		return (ft_putstr_n(fd, "(null)"));
	}
	while (str[i] != '\0')
	{
		write(fd, &str[i], 1);
		i++;
	}
	return (i);
}

/*
int	main(void)
{
	char *st = "hello";
	
	printf("%d\n", ft_putstr_n(st));
}
*/
