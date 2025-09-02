# include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *leftover;  // keeps what’s not yet returned
    char        buf[BUFFER_SIZE + 1];
    char        *line;
    int bytes_read;
    bytes_read = 1;
    while (bytes_read)
    {
        bytes_read = read(fd , buf, BUFFER_SIZE);//so read() remember where it pulls?
        if (bytes_read > 0)
        {
            buf[bytes_read] = '\0';
            leftover = ft_strjoin_free(leftover, buf);
        }
        if (bytes_read < 0)
        {
            free(leftover);
            leftover = NULL;
            return (NULL);
        }
        if (ft_strchr(leftover, '\n'))
        {
           line =  ft_strdup_until_nl(leftover);
           leftover = ft_save_leftover(leftover);
           return (line);
        }
    }
    if (leftover)
    {
        line =  ft_strdup_until_nl(leftover);
        leftover = ft_save_leftover(leftover);
        return (line);
    }
    return NULL;
}
