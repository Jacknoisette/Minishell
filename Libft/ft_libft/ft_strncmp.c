/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:38:17 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/22 14:09:00 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && (s1[i] == s2[i]) && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
int	main(void)
{
	size_t	lenght;
	char	*string1;
	char	*string2;
	int		trncmp;

	string1 = "01";
	string2 = "0";
	lenght = 1;
	trncmp = ft_strncmp(string1, string2, lenght);
	printf("%d,", trncmp);
	printf("%d,\n", strncmp(string1, string2, lenght));
	string1 = "nnnnaaaaaa";
	string2 = "nnnnaa";
	lenght = 10;
	trncmp = ft_strncmp(string1, string2, lenght);
	printf("%d,", trncmp);
	printf("%d,\n", strncmp(string1, string2, lenght));
	string1 = "nnnnaa";
	string2 = "nnnnaaaaaa";
	lenght = 10;
	trncmp = ft_strncmp(string1, string2, lenght);
	printf("%d,", trncmp);
	printf("%d,\n", strncmp(string1, string2, lenght));
	string1 = "nnnnaa";
	string2 = "nnnnbb";
	lenght = 3;
	trncmp = ft_strncmp(string1, string2, lenght);
	printf("%d,", trncmp);
	printf("%d,\n", strncmp(string1, string2, lenght));
	string1 = " ";
	string2 = " ";
	lenght = 2;
	trncmp = ft_strncmp(string1, string2, lenght);
	printf("%d,", trncmp);
	printf("%d,\n", strncmp(string1, string2, lenght));
	string1 = "hello123";
	string2 = "hello123";
	lenght = 9;
	trncmp = ft_strncmp(string1, string2, lenght);
	printf("%d,", trncmp);
	printf("%d,\n", strncmp(string1, string2, lenght));
	string1 = "abcd";
	string2 = "rrcd";
	lenght = 0;
	trncmp = ft_strncmp(string1, string2, lenght);
	printf("%d,", trncmp);
	printf("%d,\n", strncmp(string1, string2, lenght));
	string1 = "";
	string2 = "okokokokokok";
	lenght = 12;
	trncmp = ft_strncmp(string1, string2, lenght);
	printf("%d,", trncmp);
	printf("%d,\n", strncmp(string1, string2, lenght));
	string1 = "bon";
	string2 = "bon4";
	trncmp = ft_strncmp(string1, string2, 2);
	printf("%d,", trncmp);
	printf("%d\n", strncmp(string1, string2, 2));
	string1 = "nnnnaa";
	string2 = "nnnnbb";
	lenght = -1;
	trncmp = ft_strncmp(string1, string2, lenght);
	printf("%d,", trncmp);
	printf("%d,\n", strncmp(string1, string2, lenght));
	return (0);
}
*/
