# include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *leftover;  // keeps what’s not yet returned
    char        buf[BUFFER_SIZE + 1];
    char        *line;

    // 1. If leftover already has '\n', cut directly.
    // 2. Otherwise, read(fd, buf, BUFFER_SIZE) in a loop
    //    until '\n' found or EOF.
    // 3. Build 'line' from leftover + buf.
    // 4. Save what comes after '\n' back into leftover.
    // 5. Return line.
}
