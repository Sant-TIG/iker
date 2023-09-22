#include "../incs/cub3d.h"

void	ft_free(char **str)
{
	free(*str);
	*str = NULL;
}

void	free_2dstr( char **str )
{
	int		i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	general_free( t_var *vars )
{
	(void)vars;
}