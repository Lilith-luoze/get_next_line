#include "get_next_line.h"


/* Read as little data as possible each time get_next_line() is called.
If a newline character is encountered, return the current line
immediately.
Don’t read the whole file and then process each line. */

 /* question- understanding: get_next_line() exhibits undefined behavior if the file associated with the file
descriptor is modified after the last call, while read() has not yet reached the end
of the file. */
/* todo: use valgrind to check mem leak */

/// @brief free pendingContent and line,ie. deal with malloc and set both to NULL 
/// (pass double pointer is actually safer way to free smth, as it can set the original pointer to NULL.)
/// @param pendingContent 
/// @return NULL
void *reset_static(char **pendingContent)
{
	free(*pendingContent); // double free possibility? 
	*pendingContent = NULL;
	return (NULL);
}

// FRAME: let main, owns all of the memory control. It's a safer way.
char	*get_next_line(int fd)
{
	static char  buf[BUFFER_SIZE + 1];
	char	     *pendingContent;
	int			bytes_read;
	int len;

	bytes_read = 1;
	// 1. read once
	// 2. add to malloced pendingcontent.
	// 3. check pendingcontent - no \n and no EOF? go to 1. - \n ? (on - building ) (deal with -1 later) 
		// my question: is the static char big enough to hold the "leftover"? 
	while (bytes_read)
	{
		// this branch deals with pendingContent is non-null AND includes the newline. 
		if (ft_strchr(pendingContent, '\n', &len))
			return (split_leftover_eq_new_line_and_new_leftover(&pendingContent));
		/// read some data (also normal case: first call when pendingContent is NULL)
		bytes_read = read(fd, buf, BUFFER_SIZE);
        if (bytes_read < 0) // gurd for read error
			return (reset_static(&pendingContent));
        if (bytes_read > 0)
		{
			buf[bytes_read] = '\0';
			pendingContent = join_leftover_and_buf(pendingContent, buf);
			if (!pendingContent) // guard when malloc fail
				return (NULL);
		}
	}
	// this branch deals with EOF and pendingContent is non-null.
	if (pendingContent && bytes_read == 0)
	{// if pendingContent has \n, split and return the line
		if(pendingContent && ft_strchr(pendingContent, '\n', &len))
			return (split_leftover_eq_new_line_and_new_leftover(&pendingContent));
		return (leftover_as_new_line(&pendingContent));
	}
	return (NULL);
}
