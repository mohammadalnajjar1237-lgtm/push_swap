/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalnajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 12:09:27 by moalnajj          #+#    #+#             */
/*   Updated: 2026/10/29 12:09:29 by moalnajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

char	*get_next_line(int fd);
void	copy_str_next_line(char *src, char *dest);
char	*ft_strjoin_next_line(char *buffer, char *line, int index);
size_t	ft_find_chr(char *buffer);
char	*cut(char *buffer, int index, int flag);
char	*read_file(int fd, char *line, char **rem, int *bytes_read);

#endif
