/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:20:47 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/22 14:07:24 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/*
static void	rot1(unsigned int i, char *c)
{
	(void)i;
	if (*c != 127)
		*c += 1;
}


int	main(void)
{
	char	s[] = "Hello_World";

	printf("Avant : %s\n", s);
	ft_striteri(s, &rot1);
	printf("Apres : %s\n", s);
}
*/
