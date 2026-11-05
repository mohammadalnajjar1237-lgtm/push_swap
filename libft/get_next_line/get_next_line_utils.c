/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 12:08:59 by moalnajj          #+#    #+#             */
/*   Updated: 2026/10/29 12:10:40 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	copy_str_next_line(char *src, char *dest)
{
	size_t	i;

	i = 0;
	while (src[i] && src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		dest[i++] = '\n';
	dest[i] = '\0';
}

char	*ft_strjoin_next_line(char *buffer, char *line, int index)
{
	size_t	line_len;
	char	*compined;

	line_len = 0;
	if (line != NULL)
	{
		while (line[line_len])
			line_len++;
	}
	compined = malloc(index + line_len + 2);
	if (!compined)
	{
		free(line);
		return (NULL);
	}
	if (line != NULL)
	{
		copy_str_next_line(line, compined);
		free(line);
	}
	copy_str_next_line(buffer, compined + line_len);
	return (compined);
}

size_t	ft_find_chr(char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*cut(char *buffer, int index, int flag)
{
	int		i;
	char	*temp;
	size_t	len;

	i = 0;
	len = 0;
	while (buffer[len])
		len++;
	if (len - index <= 1 && flag == 1)
	{
		free(buffer);
		return (NULL);
	}
	if (len - index <= 1 && flag == 0)
		return (NULL);
	temp = malloc(len - index);
	if (!temp)
		return (NULL);
	index++;
	while (buffer[index])
		temp[i++] = buffer[index++];
	temp[i] = '\0';
	if (flag)
		free(buffer);
	return (temp);
}

char	*read_file(int fd, char *line, char **rem, int *bytes_read)
{
	char	*buffer;
	int		index;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	*bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (*bytes_read > 0)
	{
		buffer[*bytes_read] = '\0';
		index = ft_find_chr(buffer);
		line = ft_strjoin_next_line(buffer, line, index);
		if (!line)
			break ;
		if (buffer[index] == '\n')
		{
			*rem = cut(buffer, index, 0);
			break ;
		}
		*bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (line);
}
