/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:05:03 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/22 14:07:36 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;
	char	*t;

	i = 0;
	j = 0;
	l = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	t = (char *)malloc((i + j + 1) * (sizeof(char)));
	if (t == NULL)
		return (NULL);
	k = -1;
	while (++k < i)
		t[k] = s1[k];
	t[k] = s2[l];
	while (k < i + j)
		t[++k] = s2[++l];
	t[k] = '\0';
	return (t);
}

/*
int	main(void)
{
	char	*so1;
	char	*so2;
	char	*so3;
	size_t	j;

	so1 = "Hello_World";
	so2 = "_Add";
	j = 0;
	so3 = ft_strjoin(so1, so2);
	while (j < strlen(so3))
	{
		printf("%c", so3[j]);
		j++;
	}
	free(so3);
	return (0);
}
*/
