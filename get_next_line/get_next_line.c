/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshvydka <dshvydka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:14:05 by dshvydka          #+#    #+#             */
/*   Updated: 2024/12/10 15:28:31 by dshvydka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*append_buffer(char *basin_buffer, char *read_buffer)
{
	char	*temp;

	temp = ft_strjoin(basin_buffer, read_buffer);
	free(basin_buffer);
	return (temp);
}

char	*read_from_file(char *buffer, int fd)
{
	int		bytes_read;
	char	*small_buffer;

	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	small_buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (small_buffer == NULL)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, small_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(small_buffer), NULL);
		small_buffer[bytes_read] = '\0';
		buffer = append_buffer(buffer, small_buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(small_buffer);
	return (buffer);
}

char	*extract_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*update_buff(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

//! main function responsible for reading data from the fd that fills
// the basin_buffer to with the scooped content until atleast one ‘\n’
// new line character is found.
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_from_file(buffer, fd);
	if (!buffer)
		return (free(buffer), NULL);
	line = extract_line(buffer);
	buffer = update_buff(buffer);
	return (line);
}

// int	main(void)
// {
// 	int fd;
// 	char *line;
// 	int count;

// 	count = 0;
// 	fd = open("txt.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Error opening file");
// 		return (1);
// 	}
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break ;
// 		count++;
// 		printf("[%d]:%s\n", count, line);
// 		free(line);
// 		line = NULL;
// 	}
// 	close(fd);
// 	return (0);
// }