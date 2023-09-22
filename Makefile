M = mandatory/
S = srcs/
O = objs/

NAME = cub3d

SRCS =  $M$Scheck.c\
		$M$Serror.c\
		$M$Sfree.c\
		$M$Sget_map.c\
		$M$Sget_next_line.c\
		$M$Sget_textures.c\
		$M$Sinit.c\
		$M$Smain.c\
		$M$Smemory.c\
		$M$Ssplit_textures.c\
		$M$Sstring_utils.c\
		$M$Sstring.c\
		$M$Slinked.c\
		$M$Sprint.c\

OBJS = 	$M$Ocheck.o\
		$M$Oerror.o\
		$M$Ofree.o\
		$M$Oget_map.o\
		$M$Oget_next_line.o\
		$M$Oget_textures.o\
		$M$Oinit.o\
		$M$Omain.o\
		$M$Omemory.o\
		$M$Osplit_textures.o\
		$M$Ostring_utils.o\
		$M$Ostring.o\
		$M$Olinked.o\
		$M$Oprint.o\

CC = gcc -g3
CFLAGS = -Wall -Werror -Wextra
DEPURATE = -fsanitize=address -g3
OPTIMIZATION = -O3

RM = rm -rf

all: mandatory

mandatory: $(NAME)

$M$O:
	@echo "Creating Objects Folder...."
	mkdir $@
	@echo "Folder created."

$(OBJS): | $M$O

$(OBJS): $M$O%.o : $M$S%.c
	$(CC) $(CFLAGS) $(DEPURATE) -c $< -o $@

$(NAME): $(OBJS)
	@echo "Compiling mandatory...."
	$(CC) $(CFLAGS) $(DEPURATE) $^ -o $(NAME)
	@echo "Mandatory compiled"

clean:
	$(RM) $(OBJS) $M$O

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
