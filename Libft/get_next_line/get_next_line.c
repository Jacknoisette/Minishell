/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:25:03 by jdhallen          #+#    #+#             */
/*   Updated: 2025/01/06 10:11:39 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_store(int fd, char *store)
{
	char	*temp;
	ssize_t	readbyte;
	char	*local;

	local = malloc(BUFFER_SIZE + 1);
	if (local == NULL)
		return (NULL);
	while (store != NULL && ft_strchr_g(store, '\n') == NULL)
	{
		readbyte = read(fd, local, BUFFER_SIZE);
		if (readbyte == -1)
			return (free(local), free(store), NULL);
		if (readbyte == 0 || store == NULL)
			break ;
		local[readbyte] = '\0';
		temp = store;
		store = ft_strjoin_g(store, local);
		free(temp);
		if (store == NULL)
			return (free(local), NULL);
	}
	return (free(local), store);
}

static char	*extract_line(char **store)
{
	char	*line;
	char	*enl_pos;
	char	*temp;

	if (*store == NULL || **store == '\0')
		return (NULL);
	enl_pos = ft_strchr_g(*store, '\n');
	if (enl_pos == NULL)
	{
		line = ft_strdup_g(*store);
		if (line == NULL)
			return (NULL);
		free(*store);
		*store = NULL;
		return (line);
	}
	line = ft_substr_g(*store, 0, enl_pos - *store + 1);
	if (line == NULL)
		return (free(*store), *store = NULL, NULL);
	temp = *store;
	*store = ft_strdup_g(enl_pos + 1);
	free(temp);
	if (*store == NULL)
		return (free(line), NULL);
	return (line);
}

static size_t	ft_strlcpy_g(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ls;

	i = 0;
	ls = 0;
	while (src[ls] != '\0')
		ls++;
	if (size == 0)
		return (ls);
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ls);
}

char	*get_next_line(int fd)
{
	static char		buffer[MAX_FD][BUFFER_SIZE + 1];
	char			*store;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store = ft_strdup_g(buffer[fd]);
	if (store == NULL)
		return (NULL);
	if (ft_strchr_g(store, '\n') == NULL)
	{
		store = read_and_store(fd, store);
		if (store == NULL)
			return (NULL);
	}
	line = extract_line(&store);
	if (store != NULL && *store != '\0')
		ft_strlcpy_g(buffer[fd], store, BUFFER_SIZE + 1);
	else
		buffer[fd][0] = '\0';
	free(store);
	return (line);
}

// int	main(void)
// {
// 	char	*line;
// 	int		fd1 = open("lines_around_10.txt", O_RDONLY);
// 	int		fd2 = open("file.txt", O_RDONLY);

// 	while (100)
// 	{
// 		line = get_next_line(fd1);
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd1);
// 	close(fd2);
// 	return 0;
// }
