#include "get_next_line.h"

/* Read as little data as possible each time get_next_line() is called.
If a newline character is encountered, return the current line
immediately.
Don’t read the whole file and then process each line. */

/* question- understanding: get_next_line() exhibits undefined behavior if the file associated with the file
descriptor is modified after the last call,
	while read() has not yet reached the end
of the file. */
/* todo: use valgrind to check mem leak */
// todo mark: check if called only once, will it cause memory leak?

/// @brief free pending_content and line,ie. deal with malloc and set to NULL to avoid double free
/// @param pending_content
/// @return NULL
void	*reset_return_null(char **pending_content)
{
	free(*pending_content);
	*pending_content = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	hd_stat[BUFFER_SIZE + 1];
	char		temp[BUFFER_SIZE + 1];
	int			bytes_read;
	char		*pending_content;

	// nec init
	bytes_read = 1;
	pending_content = NULL;
	while (bytes_read)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
			return (reset_return_null(&pending_content));
		temp[bytes_read] = '\0';
		if (bytes_read == 0)
			return (ft_join_strs(pending_content, hd_stat));
		if (bytes_read > 0)
		{
			// smmary: static array + malloc-ed + temp . at most three parts.
			if (has_newline())
				return (ft_split_and_join_twice());
			// notes: it seems, only if there could be next call,
				// should it use static array. In other words, if bytes_read == 0,
				// it can't happen.
		}
	}
	return (NULL);
}
