/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:13:55 by jdhallen          #+#    #+#             */
/*   Updated: 2025/01/06 10:11:21 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# ifndef MAX_FD
#  define MAX_FD 1024
# endif
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

size_t	ft_strlen_g(const char *s);
char	*ft_strdup_g(const char *s);
char	*get_next_line(int fd);
char	*ft_strchr_g(const char *s, int c);
char	*ft_strjoin_g(char const *s1, char const *s2);
char	*ft_substr_g(char const *s, unsigned int start, size_t len);

#endif
