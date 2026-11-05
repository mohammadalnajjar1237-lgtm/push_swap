#include "get_next_line.h"
 
char	*get_next_line(int fd)
{
	static int	bytes_read;
	static char	*remainning;
	char		*line;
	int			index;
 
	line = NULL;
	if (remainning != NULL)
	{
		index = ft_find_chr(remainning);
		line = ft_strjoin_m(remainning, line, index);
		if (remainning[index] == '\n' && line != NULL)
		{
			remainning = cut(remainning, index, 1);
			return (line);
		}
		free(remainning);
		remainning = NULL;
	}
	line = read_file(fd, line, &remainning, &bytes_read);
	if (bytes_read < 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
