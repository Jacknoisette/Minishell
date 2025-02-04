/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:23:30 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/22 14:10:28 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

static unsigned int	ft_intlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*t;

	if (start >= ft_intlen(s))
	{
		t = malloc(1);
		if (t != NULL)
			t[0] = '\0';
		return (t);
	}
	if (ft_intlen(s) - start < len)
		t = (char *)malloc(((ft_intlen(s) - start) + 1) * (sizeof(char)));
	else
		t = (char *)malloc((len + 1) * (sizeof(char)));
	if (t == NULL)
		return (NULL);
	i = start;
	j = 0;
	while (s[i] != '\0' && j < len)
		t[j++] = s[i++];
	t[j] = '\0';
	return (t);
}

/*
int	main(void)
{
	unsigned int	sta;
	size_t			le;
	size_t			j;
	char			*str;
	char			*sto;

	str = "Hello-World";
	sta = 3;
	le = 7;
	j = 0;
	sto = ft_substr(str, sta, le);
	while (j < strlen(sto))
	{
		printf("%c", sto[j]);
		j++;
	}
	return (0);
}
*/
