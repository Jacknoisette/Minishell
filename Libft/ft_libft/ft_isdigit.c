/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:22:10 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/22 13:46:01 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
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
	printf("\n%d", ft_isdigit(ch));
	ch = '0';
	printf("\n%d", ft_isdigit(ch));
}
*/
