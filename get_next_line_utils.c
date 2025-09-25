#include "get_next_line.h"

/// @brief starting from the first char after \n, save the rest as new leftover.Append \0 at the end. Free the old leftover. 
/// @param s
/// @param nl pointer to the first \n in s 
/// @return the new leftover with nul-term. NULL if no leftover or malloc fail.
char	*save_leftover(char *s, char *nl)
{
	int		i;
	char	*new_left;
	
	if (!s || !nl) // extra guard
		return (NULL);
	new_left = malloc(ft_strlen(nl + 1) + 1);
	if (!new_left)
		return (NULL);
	i = 0;
	while ((nl+1)[i] != '\0')
	{
		new_left[i] = (nl+1)[i];
		i++;
	}
	new_left[i] = '\0';
	free(s);
	return (new_left);
}

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

/// @brief join two strs ending with '\0' into a malloced param. Before returning the new filled content, free the old one that is unused.
/// @param left 
/// @param buf 
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
	free(pending_content);
	return (new_content);
}

/// @brief two case (todo: create first) : ------b) \n ? split: return the 1st half part, and store the latter half to static buf c) no \n and EOF? (the condition can be refined if needed) : combined with b) return the whole thing.
/// @return return new pending content. NULL if malloc failed.
char	*split_or_join_with_malloc(char **buf, char *pending_content, int bytes_read, int len_pendingcnt , char *next_line)
{
	char	*new_content;
	int	len_new_content;

	len_new_content = bytes_read + len_pendingcnt;
	if (!next_line && !bytes_read)
	{
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
	split
	line = generate_line_nl(*left , nl , len);
	*left = save_leftover(*left , nl);
	return (line);
}

/// @brief count length of string ends with \0.
/// @param s 
/// @return length of str. If NULL then 0.
int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}



/// @brief make the whole leftover as the newline. set static leftover to NULL. (essentially switch the string it points to)
/// @param leftover 
/// @return the whole leftover as the new line. NULL if leftover is NULL or malloc fail.
char *leftover_as_new_line(char **leftover)
{
	char *line;

	line = *leftover;
	*leftover = NULL;
	return (line);
}

/// @brief  duplicate the new line with \n. The end pointer to \n is given as parameter.
/// @param s 
/// @param nl 
/// @return a malloced line with \n. NULL if s is NULL or empty string or malloc fail.
char *generate_line_nl(char *s, char *nl , int len) 
{
	char	*dup;
	int		i;

	if (!s || !nl) // extra guard
		return (NULL);
	dup = (char *)malloc(len+1);
	if (!dup)
		return (NULL);
	i = 0;
	while ((s + i - 1) != nl)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

