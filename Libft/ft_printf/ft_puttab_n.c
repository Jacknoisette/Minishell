/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:56:14 by jdhallen          #+#    #+#             */
/*   Updated: 2025/01/28 11:00:00 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puttab_n(int fd, char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return (ft_putstr_n(fd, "(null)"));
	while (tab[i] != NULL)
	{
		ft_putstr_n(fd, tab[i]);
		ft_putchar_n(fd, ' ');
		i++;
	}
	return (i);
}

/*
int	main(void)
{
	char *st = "hello";
	
	printf("%d\n", ft_puttab_n(st));
}
*/
