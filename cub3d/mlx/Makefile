NOM = libmlx.a
SRC = mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC += mlx_png.c mlx_mouse.m
OBJ1 = $(SRC:.c=.o)
OBJ = $(OBJ1:.m=.o)
CFLAGS += -O2

# Add flags to compile for arm64 architecture
CFLAGS += -arch arm64

# Specify the library path for arm64 'mlx' library
MLX_DIR = ./

# Adjust the compiler and linker flags for 'mlx' library
LDFLAGS += -L$(MLX_DIR) -lmlx
LDFLAGS += -arch arm64

# Add the -DSTRINGPUTX11 flag
CFLAGS += -DSTRINGPUTX11

all: $(NOM)

$(NOM): $(OBJ)
	ar -r $(NOM) $(OBJ)
	ranlib $(NOM)

clean:
	rm -f $(NOM) $(OBJ) *~

re: clean all