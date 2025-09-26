#include "get_next_line.h"


/// @brief go through param s to find the first new line and return it.
/// @param s 
/// @return pointer to 1st new line. NULL if not found.
char	*has_newline(char *buf_terminated)
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

/// @brief join array s2 to malloc-ed s1. // when to do this and how? (maybe not free if you wanna reuse it)  notice to free s1 and set array s2[0] to null.
/// @return joined malloc-ed str. NULL if malloc fail.
	/// hd: head 
	/// hd is always a full str joint by tl until sep, int append decide if the sep is included.
	/// return a malloc-ed str
	char *ft_join(char *hd, char*tl, char sep , int append_sep)
{
	int		i;
	int		j;
	char *joint;
	int len_hd;
	int len_tl;
	len_hd = ft_strlen(hd , sep);
	len_tl = ft_strlen(tl , sep);
	if (append_sep)
		joint = malloc(len_hd + len_tl + 2);
	else
		joint = malloc(len_hd + len_tl + 1);
	if (!joint)
		return (NULL);
	i = 0;
	while (hd && hd[i])
	{
		joint[i] = hd[i];
		i++;
	}
	j = 0;
	while (tl[j])
		joint[i++] = tl[j++];
	if (append_sep)
		joint[i++] = sep;
	joint[i] = '\0';
	return (joint);
}

/// @brief update static array buf before return in get_next_line. can always use it before return.
void ft_update_static_array(char **buf, char *s)
{
	int i;
	int j;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	j = 0;
	while (s[i] != '\0')
	{
		(*buf)[j++] = s[i++];
	}
	(*buf)[j] = '\0';
}

/// @brief split buf by the 1st sep. Return the first part including the sep while update the double pointer buf with its second half. notice that user has to make sure at lease one sep exists or segmentfault.
/// @param buf 
/// @param sep 
/// @return the first part array buf
void ft_split_strs(char **buf, char **first_half, char sep)
{
	int i;
	int j;

	i = 0;
	while ((*buf)[i] != sep)
	{
		(*first_half)[i] = (*buf)[i];
		i++;
	}
	(*first_half)[i] = (*buf)[i];
	i++;
	(*first_half)[i] = '\0';
	j = 0; 
	while((*buf)[i] != '\0')
		(*buf)[j++] = (*buf)[i++];
	(*buf)[j] = '\0';
}

/// @brief copy one whole str to dst, then part of another str (until param sep) to dst, nul term it. copy left part to the original second str. Free the whole str in func join.
/// @param  
/// @param  
/// @param  
char *split_buf_and_join_to_cnt(char *pending_content, char **buf, char *new_content, char *next_line)
{
	char to_append[BUFFER_SIZE + 1];
	ft_split_strs(buf, &to_append, '\n');
	pending_content = ft_join_strs(pending_content, &to_append, new_content);
	return pending_content;
}

/// @brief split s1 (array), its first part joining to s2, the other part joining to 
ft_split_and_join_twice()
{

}
/// @brief update static array right before return in get_next_line
ft_update_static_array()
{

}

/// @brief two case (todo: create first) : ------b) \n ? split: return the 1st half part, and store the latter half to static buf c) no \n and EOF? (the condition can be refined if needed) : combined with b) return the whole thing.
/// @return return new pending content. NULL if malloc failed.
char	*split_or_join_with_malloc(char **buf, char *pending_content, int bytes_read, int len_pendingcnt , char *has_newline)
{
	char	*new_content;
	int	len_new_content;

	if (!has_newline && !bytes_read)
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
	}
	if(has_newline)
	{
		len_new_content = len_pendingcnt + ft_strlen_sep(*buf , '\n') + 1;
		new_content = malloc(len_new_content +1);
		if (!new_content)
				return NULL;
		new_content = split_buf_and_join_to_cnt(pending_content, buf, new_content , has_newline);
		return new_content;
	}
	return NULL;
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
