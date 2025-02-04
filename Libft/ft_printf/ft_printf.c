/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:11:47 by jdhallen          #+#    #+#             */
/*   Updated: 2025/01/28 10:57:02 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_string(int fd, char chr, va_list args)
{
	int	count;

	count = 0;
	if (chr == 'c')
		count = ft_putchar_n(fd, va_arg(args, int));
	else if (chr == 's')
		count = ft_putstr_n(fd, va_arg(args, char *));
	else if (chr == 'd' || chr == 'i')
		count = ft_putnbr_n(fd, va_arg(args, int));
	else if (chr == 'u')
		count = ft_putunnbr_n(fd, va_arg(args, unsigned int));
	else if (chr == '%')
		count = ft_putchar_n(fd, '%');
	else if (chr == 'x')
		count = ft_puthexamin_n(fd, va_arg(args, unsigned int));
	else if (chr == 'X')
		count = ft_puthexamaj_n(fd, va_arg(args, unsigned int));
	else if (chr == 'p')
		count = ft_putp_n(fd, va_arg(args, void *));
	else if (chr == 't')
		count = ft_puttab_n(fd, va_arg(args, char **));
	return (count);
}

int	ft_printf(int fd, const char *string, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%' )
		{
			count += check_string(fd, string[i + 1], args);
			i++;
		}
		else
			count += ft_putchar_n(fd, string[i]);
		i++;
	}
	va_end(args);
	return (count);
}
