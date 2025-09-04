# ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#include "get_next_line.h"

typedef struct s_fdnode
{
	int				fd;
	char			*leftover;
	struct s_fdnode	*next;
}	t_fdnode;

t_fdnode	*find_or_create_node(t_fdnode **head, int fd);
char	*bonus_strjoin_free(char **old_lft, char *buf);

#endif