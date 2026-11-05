#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
 
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
 
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif
 
char	*get_next_line(int fd);
void	copy_str(char *src, char *dest);
char	*ft_strjoin_m(char *buffer, char *line, int index);
size_t	ft_find_chr(char *buffer);
char	*cut(char *buffer, int index, int flag);
char	*read_file(int fd, char *line, char **rem, int *bytes_read);
 
#endif