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

/// @brief syscalls of read() in a loop. stop when new line is met or bytes_read is 0. update the static array before return.
/// @param pending 
/// @param hd_stat 
/// @param fd 
/// @return the next line
char *reading_loop_body_of_get_next_line(char **pending, char *hd_stat , int fd)
{
	int			bytes_read;
	char		temp[BUFFER_SIZE + 1];
	char 		*ret;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
			return (reset_return_null(pending));
		temp[bytes_read] = '\0';
		if (bytes_read == 0)
			return (*pending);
		//this case has to have bytes_read > 0
		if (has_newline(temp))
		{
			ret = ft_join(*pending, temp, '\n');
			free(*pending);
			ft_update_static_array(hd_stat , temp);
			return (ret);
		}
		// this case has to continue looping
		ret = ft_join(*pending, temp, '\0');
		free(*pending);
		*pending = ret;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	hd_stat[BUFFER_SIZE + 1];


	char		*pending;
	char 		*ret;

	// nec init

	pending = NULL;

	if (hd_stat[0] && has_newline(hd_stat))
	{
		ret = ft_join(NULL, hd_stat, '\n');
		ft_update_static_array(hd_stat , hd_stat);
		return (ret);
	}
	pending = ft_join(NULL, hd_stat, '\0');
	ft_update_static_array(hd_stat , NULL);
	return (reading_loop_body_of_get_next_line(&pending, hd_stat , fd));
}
