#include "get_next_line.h"


/// @brief go through param s to find the first new line and return it.
/// @param s 
/// @return pointer to 1st new line. NULL if not found.
char	*where_is_newline(char *buf_terminated)
{
	int i;

	i = 0;
	if (!buf_terminated)
		return (NULL);
	while (buf_terminated[i])
	{
		if (buf_terminated[i] == '\n')
			return ((buf_terminated + i));
		i++;
	}
	return (NULL);
}

/// @brief join two strs ending with sep into a malloced param. Before returning the new filled content, free the old one that is unused.
/// @return a new malloced str. NULL if malloc fail.
char	*ft_join_strs(char *pending_content, char **buf , char *new_content)
{
	int		i;
	int		j;

	if (!(*buf))
		return (pending_content);
	i = 0;
	while (pending_content && pending_content[i])
	{
		new_content[i] = pending_content[i];
		i++;
	}
	j = 0;
	while ((*buf)[j])
		new_content[i++] = (*buf)[j++];
	new_content[i] = '\0';
	(*buf)[0] = '\0';
	free(pending_content);
	return (new_content);
}

/// @brief split buf by the 1st sep. Update the buf with the leftover part. notice that user has to make sure at lease one sep exists or segmentfault.
/// @param buf 
/// @param sep 
/// @return the first part array buf
char *ft_split_strs(char **buf, char sep)
{
	char *to_append[BUFFER_SIZE + 1];
	int i;
	int j;

	i = 0;
	while ((*buf)[i] != sep)
	{
		to_append[i] = (*buf)[i];
		i++;
	}
	to_append[i] = sep;
	i++;
	j = 0; 
	
	(*buf)[j] = (*buf)[i];
	return to_append;
}

/// @brief copy one whole str to dst, then part of another str (until param sep) to dst, nul term it. copy left part to the original second str. Free the whole str.
/// @param  
/// @param  
/// @param  
split_buf_and_join_to_cnt(pending_content, buf, new_content, next_line)
{

}

/// @brief two case (todo: create first) : ------b) \n ? split: return the 1st half part, and store the latter half to static buf c) no \n and EOF? (the condition can be refined if needed) : combined with b) return the whole thing.
/// @return return new pending content. NULL if malloc failed.
char	*split_or_join_with_malloc(char **buf, char *pending_content, int bytes_read, int len_pendingcnt , char *next_line)
{
	char	*new_content;
	int	len_new_content;

	if (!next_line && !bytes_read)
	{
		len_new_content = bytes_read + len_pendingcnt;
		if (len_new_content)
		{
			new_content = malloc(len_new_content +1);
			if (!new_content)
				return NULL;
			new_content = ft_join_strs(pending_content, buf, new_content);
			return new_content;
		}
		return NULL;
	}
	else if(next_line)
	{
		len_new_content = len_pendingcnt + ft_strlen_sep(*buf , '\n') + 1;
		new_content = malloc(len_new_content +1);
		if (!new_content)
				return NULL;
		new_content = split_buf_and_join_to_cnt(pending_content, buf, new_content , next_line);
	}
	return new_content;
}

/// @brief count length of string ends with param the 1st char of sep. (notice if sep isn't '\0', then at least one sep must exist in s , or else it will cause segfault)
/// @param s 
/// @param sep
/// @return length of str until first sep. If NULL then 0.
int	ft_strlen_sep(char *s , char sep)
{
	int	i;

	i = 0;
	while (s && s[i] != sep)
		i++;
	return (i);
}
