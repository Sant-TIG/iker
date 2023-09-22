#include "../incs/cub3d.h"

void	print_list( t_var *vars )
{
	t_list	*tmp;
	tmp = vars->lst_map;
	while (tmp)
	{
		printf("%s", tmp->line);
		tmp = tmp->next;
	}
}

void	print_2dstr( char **str )
{
	int	i;

	i = -1;
	while (str[++i])
		printf("%s", str[i]);
}