

typedef struct s_fdnode
{
	int				fd;
	char			*leftover;
	struct s_fdnode	*next;
}	t_fdnode;
