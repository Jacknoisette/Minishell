/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:33:03 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/22 13:45:38 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

int	ft_isascii(int c)
{
	if (c >= 0x00 && c <= 0x7F)
	{
		return (1);
	}
	return (0);
}

/*
int	main(void)
{
	int	ch;

	ch = 'h';
	printf("\n%d", ft_isascii(ch));
	ch = '0';
	printf("\n%d", ft_isascii(ch));
	ch = 0x8A;
	printf("\n%d", ft_isascii(ch));
}
*/
