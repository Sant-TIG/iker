#ifndef CUB3D_H

# define CUB3D_H

# define INVALID_EXTENSION	1
# define INVALID_FILE		2
# define INVALID_TEXTURE	3
# define INVALID_PARAMS		4
# define INVALID_MAP		5
# define MALLOC_ERROR		6
# define COLOR_ERROR		7
# define IMAGE_ERROR		8
# define NL_MAP_ERROR		9
# define OPEN_ERROR			10
# define READ_ERROR			11
# define PLAYER_NOT_FOUND	12
# define REPEATED_PLAYER	13
# define MISSING_TEXTURE	14
# define INVALID_XPM		15


# define TEXTURES 			"NO EA WE SO C F"
# define WIDTH				900
# define HEIGHT				600
# define ROT_SPEED			0.3
# define MOVE_SPEED			0.2

# include "../incs/colors.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>

/* STRUCTURES */
typedef struct	s_raycast
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;
	int		tex_y;
}	t_raycast;

typedef struct	s_mlx
{
	void		*mlx;
	void		*img;
	void		*addr;
	void		*window;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_mlx;

typedef struct	s_img
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;	
}	t_img;

typedef struct	s_textures
{
	t_img			*no;
	t_img			*so;
	t_img			*ea;
	t_img			*we;
	unsigned int	c;
	unsigned int	f;
}	t_textures;

typedef struct	s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int 	found;
}	t_player;

typedef struct	s_game
{
	char		**map;
	char		**textures;
	char		**content;
	int			map_index;
	t_img		*texture;
	t_player	*player_data;
	t_textures	*textures_data;
	t_mlx		*mlx_data;
}	t_game;

/* CAMERA FUNCTIONS */
void    right_move( t_game *game );
void    left_move( t_game *game );

/* CHECK CONTENT FUNCTIONS */
void	check_content( int i, int j, t_game *game );
int		check_cross( int i, int j, char **map );
char	*validate_char( int c );

/* CHECK MAP FUNCTIONS */
void	check_map( t_game *game );
void	check_extension( char *file, char *extension, t_game *game );
int		check_complete_map( char *file_content );

/* CHECK FUNCTIONS */
int 	ft_isspace( int c );
int 	ft_isdigit( int c );

/* ERROR FUNCTIONS */
void	process_error( int type , t_game *game );

/* FREE FUNCTIONS */
void	free_2dstr( char **str );
void	general_free( t_game *game );

/* GET MAP FUNCTIONS */
void	get_map( char *file, t_game *game );
char	*read_file( char *filename, t_game *game );

/* GET PLAYER FUNCTIONS */
void    get_player( int i, int j, char direction, t_game *game );
void	check_player( t_game *game, int j, int i, char direction );

/* GET RGB TEXTURES FUNCTION */
unsigned int	get_rgb_texture( char *texture, t_game *game );
unsigned int	get_rgb_texture_aux( char **texture, t_game *game );

/* GET TEXTURES */
void	get_textures( t_game *game );
char	**split_textures( char *str , t_game *game);

/* INIT FUNCTIONS */
void    init( t_game *game );

/* MEMORY FUNCTIONS */
void	*ft_calloc( size_t count, size_t size );

/* PROCESS GAME FUNCTIONS */
void	process_game( t_game *game );
int    raycasting( t_game *game );

/* PRINT FUNCTIONS */
void	print_2dstr( char **str );
void	print_player(t_game *game);

/* STRING FUNCTIONS */
size_t	ft_strlen( const char *str );
int		ft_atoi( const char *str );
char	*ft_strrchr( const char *str , int c );
char	*ft_strchr( const char *str , int c );
int		ft_strcmp( const char *str1, const char *str2 );
char	*ft_strstr( const char *haystack, const char *needle );
char	*ft_strjoin( char const *s1, char const *s2 );
char	*ft_substr( char const *s, int start, int len );
char	*ft_strdup( const char *str );
int		ft_2dstrlen( char **str );
char	*ft_strtrim( const char *str, char const *set );
char	**ft_split( const char *s, char c );


void	move_up( t_game *game );
void	move_back( t_game *game );
void	move_left( t_game *game );
void	move_right( t_game *game );

#endif
