#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 66
#endif
char	*ft_strchr(const char *s, int c, int *len);
char	*split_leftover_eq_new_line_and_new_leftover(char **left);
int		ft_strlen(char *s);
char	*join_leftover_and_buf(char *left, char *buf);
char	*leftover_as_new_line(char **leftover);
char	*generate_line_nl(char *s, char *nl, int len);
char	*save_leftover(char *s, char *nl);

void	*reset_static(char **leftover);
char	*get_next_line(int fd);

#endif
