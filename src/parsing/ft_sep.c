/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:28:36 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/03 18:06:00 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	freeall(char **list, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(list[i]);
		i++;
	}
	free(list);
}

static size_t	count_segment(const char *str, const char c)
{
	size_t	nbr;
	size_t	i;

	i = 0;
	nbr = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			nbr++;
		i++;
	}
	return (nbr);
}

static size_t	segment_length(const char *str, const char c, size_t *start)
{
	size_t	len;

	len = 0;
	if (str[*start] == c)
	{
		len++;
		(*start)++;
	}
	while (str[*start] != '\0' && str[*start] != c)
	{
		len++;
		(*start)++;
	}
	return (len);
}

static char	*alloc_segment(const char *str, char c, size_t *start)
{
	size_t	i;
	size_t	len;
	char	*temp;

	len = segment_length(str, c, start);
	temp = (char *)malloc((len + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		temp[i] = str[*start - len + i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	**ft_sep(char const *str, char c)
{
	size_t	i;
	size_t	j;
	char	**list;

	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (str[0] == '\0')
	{
		list = (char **)malloc(sizeof(char *));
		if (list == NULL)
			return (NULL);
		return (list[0] = NULL, list);
	}
	list = (char **)malloc((count_segment(str, c) + 2) * sizeof(char *));
	if (list == NULL)
		return (NULL);
	while (i <= count_segment(str, c))
	{
		list[i] = alloc_segment(str, c, &j);
		if (list[i++] == NULL)
			return (freeall(list, i - 1), NULL);
	}
	return (list[i] = NULL, list);
}

// int	main(void)
// {
// 	char	*str;
// 	char	sep;
// 	char	**result;
// 	int	i;

// 	str = "$$$";
// 	sep = '$';
// 	i = 0;
// 	result = ft_sep(str, sep);
// 	printf("Avant :\nstr : %s\nsep : %c \n", str, sep);
// 	printf("Apres :\n");
// 	while (result[i] != NULL)
// 	{
// 		printf("%i : %s", i, result[i]);
// 		printf("\n");
// 		i++;
// 	}
// 	printf("\n");
// 	free(result);
// 	return (0);
// }
