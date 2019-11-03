#ifndef FILLIT_H
#define FILLIT_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"
#define BUFF_SIZE 1

typedef struct		s_line
{
	int				fd;
	char			*str1;
	struct s_line	*next;
}					t_line;
int					get_next_line(int fd, char **line);

#endif