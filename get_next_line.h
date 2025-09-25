#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 66
#endif
char	*ft_strchr(const char *s, int c, int *len);
char	*split_or_join_with_malloc(char **left);
int		ft_strlen(char *s);
char	*ft_join_strs(char *left, char *buf);
char	*leftover_as_new_line(char **leftover);
char	*generate_line_nl(char *s, char *nl, int len);
char	*save_leftover(char *s, char *nl);

void	*reset_return_null(char **leftover);
char	*get_next_line(int fd);

#endif
