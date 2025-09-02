#include "get_next_line.h"

char	*update_line_n_left(char **leftover)
{
	char	*line;

	line = ft_strdup_until_nl(*leftover);
	*leftover = ft_save_leftover(*leftover);
	return (line);
}

void	*reset_static(char **leftover)
{
	free(*leftover);
	*leftover = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	int			bytes_read;
	static char	*leftover;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
        if (bytes_read < 0)
			return (reset_static(&leftover));
        if (bytes_read > 0)
		{
			buf[bytes_read] = '\0';
			leftover = ft_strjoin_free(leftover, buf);
			if (!leftover)
				return (NULL);
		}
		if (ft_strchr(leftover, '\n'))
			return (update_line_n_left(&leftover));
	}
	if (leftover)
		return (update_line_n_left(&leftover));
	return (NULL);
}
