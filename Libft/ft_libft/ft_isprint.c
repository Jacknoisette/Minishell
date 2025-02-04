/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:33:03 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/22 13:46:18 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

int	ft_isprint(int c)
{
	if (c >= 0x20 && c <= 0x7E)
	{
		return (1);
	}
	return (0);
}

/*
int	main(void)
{
	int	ch;
	int	i;

	i = 0;
	while (i++, i <= 127)
	{
		ch = i;
		printf("%d : ", i);
		printf("%d\n", ft_isprint(ch));
	}
}
*/
