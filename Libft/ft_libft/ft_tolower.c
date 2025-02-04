/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:33:03 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/22 14:10:43 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c += 32;
	}
	return (c);
}

/*
int	main(void)
{
	int	ch;

	ch = 'a';
	printf("\n%c", ft_tolower(ch));
	ch = '0';
	printf("\n%c", ft_tolower(ch));
	ch = 'H';
	printf("\n%c", ft_tolower(ch));
}
*/
