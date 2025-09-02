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
        buf[bytes_read] = '\0';
        if (ft_strchr((const char *)leftover, '\n'))
        {
           line =  ft_strdup_until_nl(leftover);
           leftover = ft_save_leftover(leftover);
           return (line);
        }
        leftover = ft_strjoin_free(leftover, buf);

        if (ft_strchr((const char *)leftover, '\n'))
            return(leftover);
        if (!leftover)
            return(NULL);
    }
    return NULL;
  
}
