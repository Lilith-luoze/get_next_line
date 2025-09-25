# include "get_next_line_bonus.h"
/* 
// start here. what did I do?
char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	int			bytes_read;
    static t_fdnode	*head;
    t_fdnode *cur;
	int len;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		cur = find_or_create_node(&head, fd);
        if (bytes_read < 0)
			return (reset_return_null(&(cur ->leftover)));
        if (bytes_read > 0)
		{
			buf[bytes_read] = '\0';
			cur ->leftover = bonus_strjoin_free(&(cur ->leftover), buf);
			if (!(cur ->leftover))
				return (NULL);
		}
		if (ft_strchr(cur ->leftover, '\n', &len))
			return (split_or_join_with_malloc(&(cur ->leftover)));
	}
	if (cur ->leftover)
		return (split_or_join_with_malloc(&(cur ->leftover)));
	return (NULL);
}

 */