/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:52:37 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/22 14:10:02 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

static size_t	ft_testchr(char const *test, char sample)
{
	size_t	j;

	j = 0;
	while (test[j] != '\0')
	{
		if (test[j] == sample)
			return (1);
		j++;
	}
	return (0);
}

static void	ft_middle(char const *s1, char const *set, size_t *e, size_t *l)
{
	while (s1[*l] != '\0' && ft_testchr(set, s1[*l]))
		(*l)++;
	(*e) = 0;
	while (s1[*e] != '\0')
		(*e)++;
	(*e)--;
	while ((*e) > (*l) && ft_testchr(set, s1[*e]))
		(*e)--;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	l;
	size_t	e;
	char	*t;

	i = 0;
	l = 0;
	if (s1[0] == '\0')
	{
		t = malloc(1);
		if (t == NULL)
			return (NULL);
		return (t[0] = '\0', t);
	}
	ft_middle(s1, set, &e, &l);
	t = (char *)malloc((e - l + 2) * (sizeof(char)));
	if (t == NULL)
		return (NULL);
	while (l <= e)
		t[i++] = s1[l++];
	return (t[i] = '\0', t);
}

/*
int	main(void)
{
	char	*so1;
	char	*so2;
	char	*so3;

	so1 = "Hello_World";
	so2 = "elw";
	so3 = ft_strtrim(so1, so2);
	printf("Avant : %s, %s \n", so1, so2);
	printf("Apres : %s\n", so3);
	free(so3);
	so1 = "12345-6789";
	so2 = "02468";
	so3 = ft_strtrim(so1, so2);
	printf("Avant : %s, %s \n", so1, so2);
	printf("Apres : %s\n", so3);
	free(so3);
	so1 = "##\n##Hello#\n#World#\n##";
	so2 = "#\n#";
	so3 = ft_strtrim(so1, so2);
	printf("Avant : %s, %s \n", so1, so2);
	printf("Apres : %s\n", so3);
	free(so3);
	so1 = "";
	so2 = "abc";
	so3 = ft_strtrim(so1, so2);
	printf("Avant : %s, %s \n", so1, so2);
	printf("Apres : %s\n", so3);
	free(so3);
	return (0);
}
*/
