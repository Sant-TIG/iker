M = mandatory/
S = srcs/
O = objs/

NAME = cub3d

SRCS =  $M$Scheck_content_utils.c\
		$M$Scheck_content.c\
		$M$Scheck_map.c\
		$M$Scheck.c\
		$M$Serror.c\
		$M$Sfree.c\
		$M$Sget_map.c\
		$M$Sget_player.c\
		$M$Sget_rgb_textures.c\
		$M$Sget_textures.c\
		$M$Sinit.c\
		$M$Smain.c\
		$M$Smemory.c\
		$M$Ssplit_textures.c\
		$M$Sstring_utils.c\
		$M$Sstring_utils_1.c\
		$M$Sstring.c\
		$M$Sprint.c\
		$M$Sread_file.c\
		$M$Sprocess_game.c\
		$M$Sraycasting.c\
		$M$Splayer_movements.c\
		$M$Scamera.c

OBJS = 	$M$Ocheck_content_utils.o\
		$M$Ocheck_content.o\
		$M$Ocheck_map.o\
		$M$Ocheck.o\
		$M$Oerror.o\
		$M$Ofree.o\
		$M$Oget_map.o\
		$M$Oget_player.o\
		$M$Oget_rgb_textures.o\
		$M$Oget_textures.o\
		$M$Oinit.o\
		$M$Omain.o\
		$M$Omemory.o\
		$M$Osplit_textures.o\
		$M$Ostring_utils.o\
		$M$Ostring_utils_1.o\
		$M$Ostring.o\
		$M$Oprint.o\
		$M$Oread_file.o\
		$M$Oprocess_game.o\
		$M$Oraycasting.o\
		$M$Ocamera.o\
		$M$Oplayer_movements.o

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
	$(CC) $(CFLAGS)  -Imlx -c $< -o $@

$(NAME): $(OBJS)
	@echo "Compiling mandatory...."
	$(MAKE) -C mlx/
	$(CC) $(CFLAGS)  -lmlx -Lmlx -framework OpenGL -framework AppKit $^ -o $(NAME)
	@echo "Mandatory compiled"

clean:
	$(RM) $(OBJS) $M$O


fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C mlx/ clean

re: fclean all

.PHONY: all bonus clean fclean re
