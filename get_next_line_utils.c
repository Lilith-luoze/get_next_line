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

/// @brief check if char c is in string s. c can be '\0'.
/// @param s 
/// @param c 
/// @param len if not NULL, store the length from start of s to the first occurrence of c.
/// @return the pointer to the first occurrence of c in s; NULL if not found or s is NULL
char	*ft_strchr(const char *s, int c, int *len)
{
	int i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			if (len)
				*len = i + 1;
			return ((char *)(s + i));
		}
		i++;
	}
	if (c == '\0')
	{
		if (len)
			*len = i + 1;
		return ((char *)(s + i));
	}
	return (NULL);
}

/// @brief split the leftover with at least one \n. the front part - returned; the latter part - new leftover. Free the old leftover.
/// @param leftover 
/// @return return the new line with \n included. NULL if leftover is NULL or malloc fail. 
char	*split_leftover_eq_new_line_and_new_leftover(char **left)
{
	char	*line;
	char *nl;
	int len;

	nl = ft_strchr(*left, '\n', &len);
	if (!nl)
		return (NULL);
	line = generate_line_nl(*left , nl , len);
	*left = save_leftover(*left , nl);
	return (line);
}

// Add all the helper functions you need in the get_next_line_utils.c file.

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

// join the new one to the leftover, free the
// we don't want to free s1 early, as it can be NULL in the
// first read but just a phase. It's not the end of the world.

/// @brief join left and buf, free left. (left can be NULL)
/// @param left 
/// @param buf 
/// @return  a new malloced string which is the concatenation of left and buf. NULL if malloc fail.
char	*join_leftover_and_buf(char *left, char *buf)
{
	char	*new;
	int		len1;
	int		len2;
	int		i;
	int		j;

	len1 = ft_strlen(left);
	len2 = ft_strlen(buf);
	new = malloc(len1 + len2 + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (left && left[i])
	{
		new[i] = left[i];
		i++;
	}
	j = 0;
	while (buf && buf[j])
		new[i++] = buf[j++];
	new[i] = '\0';
	free(left);
	return (new);
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

