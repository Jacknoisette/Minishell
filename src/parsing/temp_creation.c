/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   temp_creation.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jdhallen <jdhallen@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/01/29 16:11:08 by jdhallen		  #+#	#+#			 */
/*   Updated: 2025/01/29 17:01:39 by jdhallen		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../minishell.h"

char quote_check(char chr)
{
	if (chr == 39)
		return (39);
	if (chr == 34)
		return (34);
	return (FALSE);
}

int	quote_parsing_var(t_lst_var **lst_var, char *str, t_var *v, char *quote)
{
	if (*quote != FALSE)
	{
		v->i++;
		while (str[v->i] != '\0' && str[v->i] != '$'
			&& str[v->i] != *quote)
			v->i++;
		if (lst_create_new_var(lst_var, str, *v, *quote) == ERROR)
			return (ERROR);
		if (str[v->i] == *quote)
			*quote = FALSE;
	}
	else
	{
		while (str[v->i] != '\0' && str[v->i] != '$'
			&& quote_check(str[v->i]) == FALSE)
			v->i++;
		if (v->i > v->j)
			if (lst_create_new_var(lst_var, str, *v, *quote) == ERROR)
				return (ERROR);
	if (quote_check(str[v->i]) != FALSE)
		*quote = quote_check(str[v->i]);
	}
	return (0);
}

t_lst_var	*temp_creation(char *str)
{
	t_lst_var *lst_var;
	t_var	v;
	char quote;

	v.i = 0;
	quote = quote_check(str[v.i]);
	lst_var = NULL;
	while (str[v.i] != '\0')
	{
		v.j = v.i;
		if (str[v.i] == '$')
			v.i++;
		if (quote_parsing_var(&lst_var, str, &v, &quote) == ERROR)
			return (free_list_var(&lst_var), NULL);
		if (str[v.i] != '$')
			v.i++;
	}
	ft_printf_list_var(&lst_var, 1);
	return (lst_var);
}


// 'echo $USER'test"$USER"
		// if (quote != FALSE)
		// {
		// 	v.i++;
		// 	while (str[v.i] != '\0' && str[v.i] != '$'
		// 		&& str[v.i] != quote)
		// 		v.i++;
		// 	if (lst_create_new_var(&lst_var, str, v, quote) == ERROR)
		// 		return (free_list_var(lst_var), NULL);
		// 	if (str[v.i] == quote)
		// 		quote = FALSE;
		// }
		// else
		// {
		// 	while (str[v.i] != '\0' && str[v.i] != '$'
		// 		&& quote_check(str[v.i]) == FALSE)
		// 		v.i++;
		// 	if (v.i > v.j)
		// 		lst_create_new_var(&lst_var, str, v, quote);
		// 	if (quote_check(str[v.i]) != FALSE)
		// 		quote = quote_check(str[v.i]);
		// }