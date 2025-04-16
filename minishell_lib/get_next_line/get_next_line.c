/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:35:32 by lusimon           #+#    #+#             */
/*   Updated: 2024/12/10 13:33:13 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_and_store(int fd, char **storage, int bytes_read)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*temp = NULL;

	bytes_read = 0;
	if (!(*storage))
		*storage = ft_strdup("");
	if (!*storage)
		return (-1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(*storage, buffer);
		free(*storage);
		if (!temp)
		{
			*storage = NULL;
			return (-1);
		}
		*storage = temp;
		if (check_end_line(storage) > 0)
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (bytes_read);
}

int	len_new_storage(char **storage, char **line)
{
	int		len_line;
	int		len_old_storage;
	int		i;

	len_line = 0;
	len_old_storage = 0;
	i = 0;
	len_old_storage = (ft_strlen(*storage)); //taille tout le storage 
	len_line = (strlen_line(*storage, '\n'));
	*line = (char *)malloc(sizeof(char) * (len_line + 1)); //+1 character 0
	if (!*line)
		return (-1);
	while (i < len_line) //prend en compte le n ???
	{
		(*line)[i] = (*storage)[i];
		i++;
	}
	(*line)[i] = '\0';
	return ((len_old_storage - len_line));
}

char	*extract_line_storage(char **storage, char **line)
{
	int		len_newstorage;
	int		len_line;
	char	*temp;
	int		i;

	len_newstorage = 0;
	len_line = 0;
	i = 0;
	len_line = (strlen_line(*storage, '\n'));
	len_newstorage = len_new_storage(storage, line);
	temp = (char *)malloc(sizeof(char) * ((len_newstorage) + 1));
	if (!temp)
		free(*line);
	while (i < (len_newstorage))
	{
		(temp)[i] = (*storage)[len_line];
		i++;
		len_line++;
	}
	(temp)[i] = '\0';
	if (*storage != NULL)
		free(*storage);
	(*storage) = (temp);
	return (*line);
}

// int	len_new_storage(char **storage, char **line)
// {
// 	int	len_line;
// 	int	len_storage;
// 	int	i;

// 	len_line = 0;
// 	len_storage = 0;
// 	i = 0;
// 	len_storage = (ft_strlen(*storage)); //taille tout le storage 
// 	len_line = (storage_len(*storage, '\n'));
// 	*line = (char *)malloc(sizeof(char) * (len_line + 1)); //+1 character 0
// 	if (!*line)
// 		return (-1);
// 	while (i < len_line) //prend en compte le n ???
// 	{
// 		(*line)[i] = (*storage)[i];
// 		i++;
// 	}
// 	(*line)[i] = '\0';
// 	*temp = (char *)malloc(sizeof(char) * ((len_storage - len_line) + 1));
// 	if (!temp)
// 	{
// 		free(*line);
// 		return (-1);
// 	}
// 	return ((len_storage - len_line));
// }

// char	*extract_line_storage(char **storage, char **line)
// {
// 	int		len_newstorage;
// 	int		len_line;
// 	char	*temp;
// 	int		i;
// 	int		y;

// 	len_newstorage = 0;
// 	len_line = 0;
// 	i = 0;
// 	y = 0;
// 	len_line = (storage_len(*storage, '\n'));
// 	len_newstorage = len_new_storage(storage, line);
// 	while (y < (len_newstorage))
// 	{
// 		(temp)[y] = (*storage)[len_line];
// 		y++;
// 		len_line++;
// 	}
// 	(temp)[y] = '\0';
// 	if (*storage != NULL)
// 		free(*storage);
// 	(*storage) = (*temp);
// 	return (*line);
// }

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line = NULL;
	int			result;
	int			bytes_r;

	result = 0;
	bytes_r = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result = read_and_store(fd, &storage, bytes_r);
	if (result < 0 || (result == 0 && (!storage || !*storage)))
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	extract_line_storage(&storage, &line);
	return (line);
}

#include <stdio.h>

int main() {
    int fd = open("test.txt", O_RDONLY);
    char *line;
	line = get_next_line(fd);
    while (line != NULL) {
        printf("%s", line);
        free(line);
		line = get_next_line(fd);
    }
    close(fd);
	// system("leaks get_next_line");
    return 0;
}