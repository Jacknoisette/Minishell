/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_remake_strcmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:38:02 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/20 12:12:38 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_char_arg	*strcmddup(t_char_arg *source)
{
	t_char_arg	*result;
	int			len;
	int			i;

	if (source == NULL)
		return (NULL);
	len = 0;
	while (source[len].str != NULL)
		len++;
	result = malloc(sizeof(t_char_arg) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (source[i].str != NULL)
	{
		result[i].str = ft_strdup(source[i].str);
		result[i].is_space = source[i].is_space;
		i++;
	}
	result[i].str = NULL;
	return (result);
}

t_char_arg	*return_result__malloc(t_char_arg *source, t_char_arg *dest)
{
	t_char_arg	*result;
	int			len;
	int			len2;

	len = 0;
	len2 = 0;
	if (source == NULL && dest == NULL)
		return (NULL);
	if (source == NULL)
		return (strcmddup(dest));
	if (dest == NULL)
		return (strcmddup(source));
	while (source[len].str != NULL)
		len++;
	while (dest[len2].str != NULL)
		len2++;
	result = malloc(sizeof(t_char_arg) * (len + len2 + 1));
	return (result);
}

t_char_arg	*strcmdjoin(t_char_arg *source, t_char_arg *dest)
{
	t_char_arg	*result;
	int			i;
	int			j;

	result = return_result__malloc(source, dest);
	if (result == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (source[i].str != NULL)
	{
		result[i].str = ft_strdup(source[i].str);
		result[i].is_space = source[i].is_space;
		i++;
	}
	while (dest[j].str != NULL)
	{
		result[i + j].str = ft_strdup(dest[j].str);
		result[i + j].is_space = dest[j].is_space;
		j++;
	}
	result[i + j].str = NULL;
	free_char_arg(source);
	return (result);
}
