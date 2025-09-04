#include "get_next_line_bonus.h"
#include <stddef.h>


/// @brief init node with given fd
/// @param s 
/// @param fd 
void init_node(t_fdnode *s, int fd)
{
    s->fd = fd;
    s ->leftover = NULL;
    s ->next = NULL;
}

/// @brief go through linked list to find same fd
/// @param head
/// @param fd
/// @return a pointer to the node found or a new node
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
            return(NULL);
        init_node(s, fd);
        s ->next = *head;
        *head = s;
    }
   return (s);
}
