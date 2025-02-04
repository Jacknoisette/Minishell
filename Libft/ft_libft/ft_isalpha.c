/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:33:03 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/22 13:45:16 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

int	ft_isalpha(int c)
{
	if (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
	{
		return (1);
	}
	return (0);
}

/*
int	main(void)
{
	int	ch;

	ch = 'a';
	printf("\n%d", ft_isalpha(ch));
	ch = '0';
	printf("\n%d", ft_isalpha(ch));
	ch = 'H';
	printf("\n%d", ft_isalpha(ch));
}
*/
