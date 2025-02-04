/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:29:02 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/22 14:07:10 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

char	*ft_strdup(const char *s)
{
	char	*store;
	int		l;
	int		i;

	l = 0;
	while (s[l] != '\0')
		l++;
	store = (char *)malloc((l + 1) * sizeof(char));
	if (store == NULL)
		return (NULL);
	i = 0;
	while (i < l)
	{
		store[i] = s[i];
		i++;
	}
	store[l] = '\0';
	return (store);
}

/*
int	main(int ac, char **av)
{
	char	*func;
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (i < ac - 1)
	{
		func = ft_strdup(av[j]);
		printf("Original : %s\n", av[j]);
		printf("Fonction : %s\n", func);
		free(func);
		i++;
		j++;
	}
	return (0);
}
*/
