#ifndef CUB3D_H

# define CUB3D_H

# define INVALID_EXTENSION	1
# define INVALID_FILE		2
# define INVALID_TEXTURE	3
# define INVALID_PARAMS		4

# define TEXTURES 			"NO EA WE SO C F"

# include "../incs/colors.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

/* STRUCTURES */
typedef struct	s_list
{
	char			*line;
	struct s_list	*next;
}	t_list;

typedef struct	s_textures
{
	char*	no;
	char*	so;
	char*	ea;
	char*	we;
	char*	c;
	char*	f;
	int		filled;
}	t_textures;

typedef struct	s_var
{
	int			fd;
	char		**map;
	int			lines;
	int			map_index;
	t_list		*lst_map;
	t_textures	*textures;
}	t_var;

/* CHECK FUNCTIONS */
int 	ft_isspace(int c);
int 	ft_isdigit(int c);

/* ERROR FUNCTIONS */
void	process_error( int type , t_var *vars );

/* FREE FUNCTIONS */
void	ft_free( char **str );
void	free_2dstr( char **str );
void	general_free( t_var *vars );

/* GET MAP FUNCTIONS */
void	get_map( char *file, t_var *vars );

/* GET NEXT LINE FUNCTIONS */
char	*get_next_line(int fd);

/* GET TEXTURES */
char	**split_textures( char *str , t_var *vars);

/* INIT FUNCTIONS */
void    init(t_var *vars);

/* LINKED FUNCTIONS */
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

t_list	*ft_lstnew(void *content);

/* MEMORY FUNCTIONS */
void	*ft_calloc(size_t count, size_t size);

void	print_list( t_var *vars );
void	print_2dstr( char **str );

/* STRING FUNCTIONS */
size_t	ft_strlen( const char *str );
char	*ft_strrchr( const char *str , int c );
char	*ft_strchr( const char *str , int c );
int		ft_strcmp( const char *str1, const char *str2 );
char	*ft_strstr( const char *haystack, const char *needle );
char	*ft_strjoin( char const *s1, char const *s2 );
char	*ft_substr( char const *s, int start, int len );
char	*ft_strdup( const char *str );

#endif
