#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

// join the new one to the leftover, free the 
// we don't want to free s1 early, as it can be NULL in the 
// first read but just a phase. It's not the end of the world.
char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*new;
	int		len1;
	int		len2;
	int		i;
	int		j;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = (char *)malloc(len1 + len2 + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		new[i++] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	if (s1)
		free(s1);
	return (new);
}

// Extract exactly one line (up to and including \n if present).
char	*ft_strdup_until_nl(char *s)
{
	char	*dup;
	int		i;

	if (!s || !*s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	dup = (char *)malloc(i + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		dup[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		dup[i++] = '\n';
	dup[i] = '\0';
	return (dup);
}
int free_when_NULL_or_0(char *check, int i, char *fry)
{
	if (i == -1 && !check)
	{
		free(fry);
		return (1);
	}
	if (i != -1 && !check[i])
	{
		free(fry);
		return (1);
	}
	return 0;
}

char * ft_save_leftover(char *s)
{
	int i;
	int new_itor;

	i = 0;
	if (!s || !*s)
		return (NULL);
	while(s[i] != '\0' && s[i] != '\n')
		i++;
	if (free_when_NULL_or_0(s,i,s))
		return(NULL);
	i++;
	char *new_left;
	new_left = (char *) malloc(ft_strlen(s+i) + 1);
	if (free_when_NULL_or_0(new_left, -1 , s))
		return NULL;
	new_itor = 0;
	while(s[i] != '\0')
		new_left[new_itor++] = s[i++];
	new_left[new_itor] = '\0';
	free(s);
	return new_left;
}



