/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:20:47 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/22 14:08:49 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*t;

	i = 0;
	while (s[i] != '\0')
		i++;
	t = (char *)malloc((i + 1) * sizeof(char));
	if (t == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		t[i] = f(i, s[i]);
		i++;
	}
	t[i] = '\0';
	return (t);
}

/*
static char	rot1(unsigned int i, char c)
{
	(void)i;
	if (c == 127)
		return (1);
	else
		return (c + 1);
}

int	main(void)
{
	char	*result;

	result = ft_strmapi("Hello_World", &rot1);
	if (result != NULL)
	{
		printf("Avant : Hello_World\n");
		printf("Apres : %s\n", result);
		free(result);
	}
	result = ft_strmapi("abcdefghijklmnopqrstuvwxyz0123456789", &rot1);
	if (result != NULL)
	{
		printf("Avant : abcdefghijklmnopqrstuvwxyz0123456789\n");
		printf("Apres : %s\n", result);
		free(result);
	}
}
*/
