#include "get_next_line.h"


/* Read as little data as possible each time get_next_line() is called.
If a newline character is encountered, return the current line
immediately.
Don’t read the whole file and then process each line. */

 /* question- understanding: get_next_line() exhibits undefined behavior if the file associated with the file
descriptor is modified after the last call, while read() has not yet reached the end
of the file. */
/* todo: use valgrind to check mem leak */

/// @brief free leftover and line,ie. deal with malloc and set both to NULL 
/// (pass double pointer is actually safer way to free smth, as it can set the original pointer to NULL.)
/// @param leftover 
/// @return NULL
void *reset_static(char **leftover)
{
	free(*leftover); // double free possibility? 
	*leftover = NULL;
	return (NULL);
}

// i think line is not needed as a parameter, as it's just a return value
char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	     *leftover;
	int			bytes_read;
	int len;

	bytes_read = 1;
	while (bytes_read)
	{
		// this branch deals with leftover is non-null AND includes the newline. 
		if (ft_strchr(leftover, '\n', &len))
			return (split_leftover_eq_new_line_and_new_leftover(&leftover));
		/// read some data (also normal case: first call when leftover is NULL)
		bytes_read = read(fd, buf, BUFFER_SIZE);
        if (bytes_read < 0) // gurd for read error
			return (reset_static(&leftover));
        if (bytes_read > 0)
		{
			buf[bytes_read] = '\0';
			leftover = join_leftover_and_buf(leftover, buf);
			if (!leftover) // guard when malloc fail
				return (NULL);
		}
	}
	// this branch deals with EOF and leftover is non-null.
	if (leftover && bytes_read == 0)
	{// if leftover has \n, split and return the line
		if(leftover && ft_strchr(leftover, '\n', &len))
			return (split_leftover_eq_new_line_and_new_leftover(&leftover));
		return (leftover_as_new_line(&leftover));
	}
	return (NULL);
}
