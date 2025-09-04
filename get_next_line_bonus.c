# include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*update_line_n_left_bonus(char **leftover)
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
    static t_fdnode	*head;
    t_fdnode *cur;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		cur = find_or_create_node(&head, fd);
        if (bytes_read < 0)
			return (reset_static(&(cur ->leftover)));
        if (bytes_read > 0)
		{
			buf[bytes_read] = '\0';
			cur ->leftover = strjoin_free_bonus(&(cur ->leftover), buf);
			if (!(cur ->leftover))
				return (NULL);
		}
		if (ft_strchr(cur ->leftover, '\n'))
			return (update_line_n_left(&(cur ->leftover)));
	}
	if (cur ->leftover)
		return (update_line_n_left(&(cur ->leftover)));
	return (NULL);
}

