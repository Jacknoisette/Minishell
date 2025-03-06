/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:05:14 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/14 11:46:36 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_charjoin(char *str, char chr)
{
	char	*temp;
	char	*temp2;

	temp = str;
	temp2 = malloc(2 * sizeof(char));
	if (temp == NULL)
		return (NULL);
	temp2[0] = chr;
	temp2[1] = '\0';
	str = ft_strjoin(temp, temp2);
	free(temp);
	free(temp2);
	return (str);
}
