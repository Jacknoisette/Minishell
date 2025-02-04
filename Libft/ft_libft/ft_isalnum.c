/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:10:15 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/22 13:45:01 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
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
	printf("\n%d", ft_isalnum(ch));
	ch = '0';
	printf("\n%d", ft_isalnum(ch));
	ch = 'H';
	printf("\n%d", ft_isalnum(ch));
	ch = '/';
	printf("\n%d", ft_isalnum(ch));
}
*/
