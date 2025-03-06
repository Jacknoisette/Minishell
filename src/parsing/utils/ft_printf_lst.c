/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:02:28 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/25 14:48:50 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_printf_list_cmd(t_lst_cmd **list, int output)
{
	t_lst_cmd	*tmp;
	int			i;
	int			j;

	tmp = *list;
	i = 0;
	while (tmp)
	{
		ft_printf(output, "Arg %i is \033[34m", i);
		j = 0;
		while (tmp->arg[j].str != NULL)
		{
			ft_printf(output, "[%s]", tmp->arg[j].str);
			if (tmp->arg[j].is_space == TRUE)
				ft_printf(output, " ");
			j++;
		}
		ft_printf (output, "\033[0m\n");
		i++;
		tmp = tmp->next;
	}
}

void	ft_printf_list_line(t_lst_line **list, int output)
{
	t_lst_line	*tmp;
	int			i;

	tmp = *list;
	i = 0;
	while (tmp)
	{
		ft_printf(output, "Param %i is \033[34m%s\033[0m\n", i, tmp->param);
		i++;
		tmp = tmp->next;
	}
}

void	ft_printf_list_fd(t_lst_fd **list, int output)
{
	t_lst_fd	*tmp;
	int			i;

	tmp = *list;
	i = 0;
	while (tmp)
	{
		ft_printf(output, "FD %i is \033[34m%s\033[0m of type %c so", i,
			tmp->name, tmp->type);
		if (tmp->type == 'i')
			ft_printf(output, " type \033[34minput\033[0m\n");
		if (tmp->type == 'o')
			ft_printf(output, " type \033[34moutput\033[0m\n");
		if (tmp->type == 'a')
			ft_printf(output, " type \033[34mappend\033[0m\n");
		if (tmp->type == 'h')
		{
			ft_printf(output, " type \033[34mheredoc\033[0m ");
			ft_printf(output, "with limiter \033[34m%s\033[0m\n", tmp->limit);
		}
		i++;
		tmp = tmp->next;
	}
}

void	ft_printf_list_var(t_lst_var **list, int output)
{
	t_lst_var	*tmp;

	tmp = *list;
	ft_printf(1, "%sLST_VAR$%s\n", YLW, NTL);
	while (tmp)
	{
		ft_printf(output, "String is \033[34m%s\033[0m ", tmp->string);
		ft_printf(output, "is in quote \033[34m%c\033[0m ", tmp->is_squote);
		ft_printf(output, "is in var \033[34m%i\033[0m ", tmp->is_var);
		ft_printf(output, "and is space \033[34m%i\033[0m\n", tmp->is_space);
		tmp = tmp->next;
	}
}
