#include "get_next_line.h"


/* Read as little data as possible each time get_next_line() is called.
If a newline character is encountered, return the current line
immediately.
Don’t read the whole file and then process each line. */

 /* question- understanding: get_next_line() exhibits undefined behavior if the file associated with the file
descriptor is modified after the last call, while read() has not yet reached the end
of the file. */
/* todo: use valgrind to check mem leak */

/// @brief free pending_content and line,ie. deal with malloc and set to NULL to avoid double free 
/// @param pending_content 
/// @return NULL
void *reset_return_null(char **pending_content)
{
	free(*pending_content); 
	*pending_content = NULL;
	return (NULL);
}

// FRAME: let main, owns all of the memory control. It's a safer way.
char	*get_next_line(int fd)
{
	static char  buf[BUFFER_SIZE + 1];
	int			bytes_read;
	char	     *pending_content;
	int len_pendingcnt;
	char * next_line;

	// nec init
	bytes_read = 1;
	pending_content = NULL;
	next_line = 	NULL;
	// 1. read once -- get signal of EOF, len_buf
	// 2. check buf a) no \n and no EOF? go to 1. --b) \n ? split: return the 1st half part, and store the latter 
	// half to static buf [it will definitely less than the length of the buf (cuz it's only discovered in this round)] while (bytes_read)
	//  --c) no \n and EOF? (the condition can be refined if needed) : combined with b) return the whole thing. d) read int is -1? just return NULL.
		// solved question: is the static char big enough to hold the "leftover"?  -- yes, see the brackets above.
	// 3. add to malloced pendingcontent and/or return.
	while (bytes_read)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		// cheked .when to append \0
		if (bytes_read == -1)
			return (reset_return_null(&pending_content));
		buf[bytes_read] = '\0';
		next_line = where_is_newline(buf);
		if ((!next_line) && bytes_read)
			continue;
		len_pendingcnt = ft_strlen(pending_content);
		split_or_join_with_malloc();


		// all append from now on in this cycle?
		
	}
	return (NULL);
}
