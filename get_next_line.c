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
	char * new_line;

	// nec init
	bytes_read = 1;
	pending_content = NULL;
	new_line = 	NULL;
	// 1. read once -- get signal of EOF, len_buf
	
	// 2. while in each loop, check buf 
	//a) no \n and no EOF?	only join.
	//b) \n ? 				split and join and return.
	//c) no \n and EOF?		just return. 

	//d) read int is -1? just return NULL. 
	// solved question: is the static char big enough to hold the "leftover"?  -- yes, cuz it's only discovered in buf.
	

	// 3. add to malloced pendingcontent and/or return.
	while (bytes_read)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		// cheked whether to append \0 -- exclude cases
		if (bytes_read == -1)
			return (reset_return_null(&pending_content));
		if (bytes_read == 0)
			return ;
		buf[bytes_read] = '\0';
		// check whether newline appears and where
		new_line = where_is_newline(buf);
		len_pendingcnt = ft_strlen(pending_content);
		split_or_join_with_malloc();


		// all append from now on in this cycle?
		
	}
	return (NULL);
}
