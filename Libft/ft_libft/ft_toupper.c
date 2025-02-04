/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:33:03 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/22 14:10:55 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c -= 32;
	}
	return (c);
}

/*
int	main(void)
{
	int	ch;

	ch = 'a';
	printf("\n%c", ft_toupper(ch));
	ch = '0';
	printf("\n%c", ft_toupper(ch));
	ch = 'H';
	printf("\n%c", ft_toupper(ch));
}
*/
