/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:15:34 by jdhallen          #+#    #+#             */
/*   Updated: 2025/01/28 10:56:39 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(int fd, const char *string, ...);
int	ft_puthexamaj_n(int fd, unsigned int n);
int	ft_puthexamin_n(int fd, unsigned int n);
int	ft_putchar_n(int fd, char c);
int	ft_puttab_n(int fd, char **str);
int	ft_putstr_n(int fd, char *str);
int	ft_putunnbr_n(int fd, unsigned int n);
int	ft_putnbr_n(int fd, int n);
int	ft_putp_n(int fd, void *n);

#endif
