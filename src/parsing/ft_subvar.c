/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subvar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:23:30 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/03 18:06:01 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_intlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static char	*table_alloc(char const *s, int start, int len, int *null)
{
	char	*t;
	int		intlen;

	intlen = ft_intlen(s);
	if (start >= intlen)
	{
		t = malloc(1);
		if (t == NULL)
			return (t);
		if (t != NULL)
			t[0] = '\0';
		*null = 1;
		return (t);
	}
	if (intlen - start < len)
		t = (char *)malloc(((intlen - start) + 1) * (sizeof(char)));
	else
		t = (char *)malloc((len + 1) * (sizeof(char)));
	return (t);
}

char	*ft_subvar(char const *s, int start, int len, char quote)
{
	char	*t;
	int		i;
	int		j;
	int		null;

	null = 0;
	t = table_alloc(s, start, len, &null);
	if (t == NULL)
		return (NULL);
	if (null == 1)
		return (t);
	i = start;
	j = 0;
	while (s[i] != '\0' && j < len)
	{
		if (s[i] == quote)
		{
			i++;
			len -= 1;
			continue ;
		}
		t[j++] = s[i++];
	}
	t[j] = '\0';
	return (t);
}

/*
int	main(void)
{
	int	sta;
	int			le;
	int			j;
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
