# include "get_next_line.h"
// # include "get_next_line_bonus.h"
/* You will compile your code as follows (a buffer size of 42 is used as an example):
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
 */

/* Does your function still work if the BUFFER_SIZE value is 9999?
it is 1? 10000000? Do you know why? */

/* who's in charge of the memory?

Your function must guarantee:

No leftover leaks after EOF/error.

Every returned line is valid and owned by caller.

The caller (evaluation main) must guarantee:

Every line returned is eventually freed. */

# include <fcntl.h>
# include <stdio.h>
/// @brief get_next_line has no counterpart in libc
/// @return 
int main(int argc, char **argv)
{
    int   fd;
    char *line;
   // Reading from a file
    if (argc < 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return (1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return (1);
    }
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }


// // Reading from stdin
// printf("Type something (Ctrl+D to end):\n");
// while ((line = get_next_line(0)))
// {save_leftover
//     printf("line: %s", line);
//     free(line);
//     line = NULL;
// }
    close(fd);
    return (0);


}
