#include "get_next_line.h"

/// @brief go through param s to find the first new line and return it.
/// @param s
/// @return pointer to 1st new line. NULL if not found.
char	*has_newline(char *buf_terminated)
{
	int	i;

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

/// @brief join array s2 to malloc-ed s1.
	// when to do this and how? (maybe not free if you wanna reuse it)  notice to free s1 and set array s2[0] to null.
/// @return joined malloc-ed str. NULL if malloc fail.
/// hd: head
/// hd is always a full str joint by tl until sep, int append decide if the sep is included.
/// return a malloc-ed str
// #test: does it need to check when len_hd plus len_tl still is zero

char	*ft_join(char *hd, char *tl, char sep)
{
	char		*joint;
	t_join_vars	t;

	t.len_hd = ft_strlen_sep(hd, '\0');
	t.len_tl = ft_strlen_sep(tl, sep);
	if (sep != '\0')
		joint = malloc(t.len_hd + t.len_tl + 2);
	else
		joint = malloc(t.len_hd + t.len_tl + 1);
	if (!joint)
		return (NULL);
	t.i = 0;
	while (hd && hd[t.i])
	{
		joint[t.i] = hd[t.i];
		t.i++;
	}
	t.j = 0;
	while (tl && tl[t.j] && tl[t.j] != sep)
		joint[t.i++] = tl[t.j++];
	if (sep != '\0')
		joint[t.i++] = sep;
	joint[t.i] = '\0';
	return (joint);
}

/// @brief update static array buf before return in get_next_line. can always use it before return.
	// #test the case when buf is the address of s. should be okay.
void	ft_update_static_array(char **buf, char *s)
{
	int	i;
	int	j;

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

/// @brief count length of string ends with param the 1st char of sep. (notice if sep isn't '\0', then at least one sep must exist in s , or else it will cause segfault)
/// @param s
/// @param sep
/// @return length of str until first sep. If NULL then 0.
int	ft_strlen_sep(char *s, char sep)
{
	int	i;

	i = 0;
	while (s && s[i] != sep && s[i])
		i++;
	return (i);
}
