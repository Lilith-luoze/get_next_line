#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
#define BUFFER_SIZE 42

int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_free(char *old_lft, char *buf);
char	*ft_strdup_until_nl(char *s);
int		free_when_NULL_or_0(char *check, int i, char *fry);
char	*ft_save_leftover(char *s);

char	*get_next_line(int fd);

#endif
