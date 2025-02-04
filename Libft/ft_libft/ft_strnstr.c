/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:32:20 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/22 14:09:19 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	t;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[0])
		{
			t = 0;
			while (big[i + t] != '\0' && little[t] != '\0'
				&& big[i + t] == little[t] && i + t < len)
				t++;
			if (little[t] == '\0')
			{
				return ((char *)big + i);
			}
		}
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	char	*str;
	char	*to_find;
	size_t	le;

	str = "hello_wored";
	to_find = "world";
	le = 3;
	printf("%s\n", ft_strnstr(str, to_find, le));
	return (0);
}
*/
