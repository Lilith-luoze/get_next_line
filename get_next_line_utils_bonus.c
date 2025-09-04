#include "get_next_line_bonus.h"

// 4 func here

/// @brief a helper to find_or_create_node; init node with given fd
/// @param s
/// @param fd
void	init_node(t_fdnode *s, int fd)
{
	s->fd = fd;
	s->leftover = NULL;
	s->next = NULL;
}

/// @brief go through linked list to find the right node with para fd,
/// else create a new one with that fd and added to the head
/// @param head
/// @param fd
/// @return a pointer to the node found or the new node
t_fdnode	*find_or_create_node(t_fdnode **head, int fd)
{
	t_fdnode	*s;

	if (!*head)
	{
		*head = (t_fdnode *)malloc(sizeof(t_fdnode));
		if (!*head)
			return (NULL);
		init_node(*head, fd);
		return (*head);
	}
	s = *head;
	while (s && s->fd != fd)
		s = s->next;
	if (!s)
	{
		s = (t_fdnode *)malloc(sizeof(t_fdnode));
		if (!s)
			return (NULL);
		init_node(s, fd);
		s->next = *head;
		*head = s;
	}
	return (s);
}

// helper to bonus_strjoin_free
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

/// @brief malloc a new leftover with buf appended to a copied old_lft. free the old_lft. fill the new one to the node.
/// @param old_lft
/// @param buf
/// @return ???buf == NULL
char	*bonus_strjoin_free(char **old_lft, char *buf)
{
	char	*new_lft;
	int		len1;
	int		len2;

	if (!(*old_lft))
		len1 = 0;
	else
		len1 = ft_strlen(*old_lft);
	len2 = ft_strlen(buf);
	new_lft = (char *)malloc(len1 + len2 + 1);
	if (!new_lft)
		return (NULL);
	ft_memcpy(new_lft, *old_lft, (size_t)len1);
	ft_memcpy(new_lft + len1, buf, (size_t)len2);
	new_lft[len1 + len2] = '\0';
	if (*old_lft)
		free(*old_lft);
	*old_lft = new_lft;
	return (new_lft);
}
