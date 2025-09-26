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

// WHY REBASED THE MEMORY STRUCTURE TO STATIC ARRAY: let main, owns all of the memory control. It's a safer way.
	// solved question: is the static char big enough to hold the "leftover"?  -- yes, cuz it's only discovered in buf.
char	*get_next_line(int fd)
{
	static char  buf[BUFFER_SIZE + 1];
	char temp[BUFFER_SIZE + 1];
	int			bytes_read;
	char	     *pending_content;

	// nec init
	bytes_read = 1;
	pending_content = NULL;
	while (bytes_read)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);  // notes: there are three parts interelated to each other. temp is for receving the reading each cycle and always empted by sub-function, pending_content is for accumulating txt during the loop in get_next_line, static buf is for storing the "leftover" right before return to main (it needs to be updated) 
			// cheked whether to append \0 -- exclude cases
		if (bytes_read == -1)
			return (reset_return_null(&pending_content));		
		if (bytes_read == 0)
			return(ft_join_strs(pending_content, buf)); // todo mark: check if called only once, will it cause memory leak?
		if (bytes_read > 0)
		{
			// "three parts interelated to each other" : this is THE main branch for it.
			// smmary: static array + malloc-ed + temp . at most three parts.
			temp[bytes_read] = '\0';
			if (has_newline())
				return (ft_split_and_join_twice());
			pending_content = ft_join_strs(buf , pending_content); 
			ft_update_buf(&buf);
			pending_content = ft_join_strs(pending_content, temp); // notes: it seems, only if there could be next call, should it use static array. In other words, if bytes_read == 0, it can't happen. 
		}
	}
	return (NULL);
}
		

ft_split_and_join_twice()
{
	join_pending_content_to_static_array
	join_temp_until_nl_to_pending_content


	
	

	//thoughts: whatever the memory structure is, the functioning aspect of join_strs is the same.
}