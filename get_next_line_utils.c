#include "get_next_line.h"

/// only two elements here needs to be dealt with :
char *ft_structure_dealer(char **mmid, char *ttemp)
{
	// first, if *mmid is NULL. Then no need to care about free of malloc. three to go. 
	if (!(*mmid))
		return ft_join(*hd_stat , *ttemp , '\n', 1);

	char *rp;
	// // if the static head array isn't empty
	// if (*hd_stat && (*hd_stat)[0])
	// {
		
	// 	rp = ft_join(*hd_stat , *mmid , sep , append_sep);
	// }
	
	// the case when temp continuously adding to mmid
	if (ttemp[0])
	{
		if (has_newline(ttemp))
			rp = ft_join(*mmid , ttemp , '\n' , 1);
		else
			rp = ft_join(*mmid , ttemp , '\0' , 0);
		free(*mmid);
		*mmid = NULL;
		return rp;
	}
	// the case when bytes_read is 0, so ttemp[0] is \0.
	if( !ttemp[0] && !(*hd_stat) && !(*mmid))
	{

	}
	
	ft_join(*hd , *mmid , sep , append_sep);

	
	// join_pending_content_to_static_array
	// join_temp_until_nl_to_pending_content
}



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
	// #test: does it need to check when len_hd plus len_tl still is zero
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
	while (tl && tl[j] && tl[j] != sep)
		joint[i++] = tl[j++];
	if (append_sep)
		joint[i++] = sep;
	joint[i] = '\0';
	return (joint);
}

/// @brief update static array buf before return in get_next_line. can always use it before return. // #test the case when buf is the address of s. should be okay.
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

/// @brief split s1 (array), its first part joining to s2, the other part joining to 
ft_split_and_join_twice()
{

}
/// @brief update static array right before return in get_next_line
ft_update_static_array()
{

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
