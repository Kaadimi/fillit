NAME = ikadimi.filler

LIBSRC = libft/libft.a
LIBPATH = libft/

OBJ = fill.o\
	  get_line.o\
	  map_file.o\
	  piece_file.o\
	  free_file.o
	  
FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(LIBSRC) $(OBJ)
		gcc $(FLAG) $(OBJ) $(LIBSRC) -o $(NAME)

%.o : %.c
		gcc $(FLAG) -c $< -o $@
$(LIBSRC):
		make -C $(LIBPATH)

clean:
		make clean -C $(LIBPATH)
			/bin/rm -f $(OBJ)
fclean: clean
		make fclean -C $(LIBPATH)
			/bin/rm -f $(NAME)
re: fclean all