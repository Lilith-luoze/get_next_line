#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 66
#endif

typedef struct s_join_vars
{
	int	i;
	int	j;
	int	len_hd;
	int	len_tl;
}		t_join_vars;


void	*reset_return_null(char **pending_content);
char	*get_next_line(int fd);

// Utility prototypes (if needed from utils)
char	*has_newline(char *buf_terminated);
char	*ft_join(char *hd, char *tl, char sep);
void	ft_update_static_array(char **buf, char *s);
int		ft_strlen_sep(char *s, char sep);

#endif
