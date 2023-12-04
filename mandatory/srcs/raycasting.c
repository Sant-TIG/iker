#include "../incs/cub3d.h"
#include <math.h>

/*
 * Calcula la posicion del rayo en el plano de la camara, las coordenadas de la direccion
 * del rayo y las coordenadas de la posicion del rayo en la cuadricula.
 */
void    get_ray_dir_pos( int x, t_raycast *ray, t_player *player )
{
    //printf("RAY DIR POS\n");
    ray->camera_x = 2 * x / (double)WIDTH - 1;
    ray->ray_dir_x = player->dir_x + player->plane_x * ray->camera_x;
    ray->ray_dir_y = player->dir_y + player->plane_y * ray->camera_x;
    ray->map_x = (int)player->pos_x;
    ray->map_y = (int)player->pos_y;

}

/*
 * Calcula la distancia que el rayo tiene que viajar de una coordenada a otra dentro de la
 * cuadricula.
 */
void    get_delta_dist( t_raycast *ray )
{
    //printf("DELTA DIST\n"); 
    if (ray->ray_dir_x == 0)
        ray->delta_dist_x = exp(30);
    else
        ray->delta_dist_x = fabs(1.0 / ray->ray_dir_x);
    if (ray->ray_dir_y == 0)
        ray->delta_dist_y = exp(30);
    else
        ray->delta_dist_y = fabs(1.0 / ray->ray_dir_y);
}

/*
 * Calcula la distancia que tiene que recorrer el rayo desde la posicion inicial al siguiente
 * valor de coordenadas para ambos ejes.
 */
void    get_side_dist( t_raycast *ray, t_player *player )
{
    //printf("SIDE DIST\n");
    //printf("aaaaaaa%faaaaaa\n", ray->delta_dist_x);
    if (ray->ray_dir_x < 0)
    {
        ray->step_x = -1;
        ray->side_dist_x = (player->pos_x - ray->map_x) * ray->delta_dist_x;
    }
    else
    {
        ray->step_x = 1;
        ray->side_dist_x = (ray->map_x + 1.0 - player->pos_x) * ray->delta_dist_x;
    }
    if (ray->ray_dir_y < 0)
    {
        ray->step_y = -1;
        ray->side_dist_y = (player->pos_y - ray->map_y) * ray->delta_dist_y;
    }
    else
    {
        ray->step_y = 1;
        ray->side_dist_y = (ray->map_y + 1.0 - player->pos_y) * ray->delta_dist_y;
    }
}


void    get_hit( t_raycast *ray , t_game *game)
{
    //printf("HIT\n");
    ray->hit = 0;
    while (ray->hit == 0)
    {
        if (ray->side_dist_x < ray->side_dist_y)
        {
            ray->side_dist_x += ray->delta_dist_x;
            ray->map_x += ray->step_x;
            ray->side = 0;
        }
        else
        {
            ray->side_dist_y += ray->delta_dist_y;
            ray->map_y += ray->step_y;
            ray->side = 1;
        }
        if (game-> map[ray->map_y][ray->map_x] == '1')
            ray->hit = 1;
    }
}

void    process_DDA( t_raycast *ray, t_game *game )
{
    get_delta_dist(ray);
    get_side_dist(ray, game->player_data);
    //printf("d_x %f d_y %f s_x %f  s_y %f\n\n", ray->delta_dist_x, ray->delta_dist_y, ray->side_dist_x, ray->side_dist_y);
    get_hit(ray, game);
    //printf("s_x %f s_y %f m_x %d m_y %d s %d\n\n", ray->side_dist_x, ray->side_dist_y, ray->map_x, ray->map_y, ray->side);
}

/*
 * Calcula la distancia proyectada en la direccion de la camara, la altura de la linea y
 * el pixel mas alto y bajo a rellenar en la franja actual
 */
void    get_wall_projection( t_raycast *ray )
{
    //printf("GHET WALL\n");
    if (ray->side == 0)
        ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
    else
        ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
    ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
    ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
    if (ray->draw_start < 0)
        ray->draw_start = 0;
    ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
    if (ray->draw_end >= HEIGHT)
        ray->draw_end = HEIGHT - 1;
}

void    get_texture( t_raycast *ray, t_game *game )
{
    //printf("GET TEXTURE\n");
    if (ray->side == 0)
    {
        if (ray->ray_dir_x > 0)
            game->texture = game->textures_data->ea;
        else
            game->texture = game->textures_data->we;
    }
    else
    {
        if (ray->ray_dir_y > 0)
            game->texture = game->textures_data->so;
        else
            game->texture = game->textures_data->no;
    }
}

void    get_texture_coord( t_raycast *ray, t_game *game )
{
    //printf("TEXTURE COLOR\n");
    t_player    *player;

    player = game->player_data;
    get_texture( ray, game );
    if (ray->side == 0)
         ray->wall_x = player->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
    else
        ray->wall_x = player->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
    ray->wall_x -= floor(ray->wall_x);
    ray->tex_x = (int)(ray->wall_x * (double)game->texture->width);
    if (ray->side == 0 && ray->ray_dir_x > 0)
        ray->tex_x = game->texture->width - ray->tex_x - 1;
    else if (ray->side == 1 && ray->ray_dir_y < 0)
        ray->tex_x = game->texture->width - ray->tex_x - 1;
}

void    my_mlx_pixel_put( t_game *game, int x, int y, int color )
{
    char    *dst;

    dst = game->mlx_data->addr + (y * game->mlx_data->line_length + x * (game->mlx_data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

unsigned int    get_image_color( t_img *texture, int x, int y )
{
    char    *dst;
    unsigned int color;

    dst = texture->addr + (y * texture->line_length + x * (texture->bits_per_pixel / 8));
    //printf("%i\n", (y * texture->line_length + x * (texture->bits_per_pixel / 8))/64);
    color = *(unsigned int *)dst;
    return (color);
}

void    draw_window( int x, t_raycast *ray, t_game *game )
{
    //printf("DRAW WIDNOW\n");
    int y;
    
    y = -1;
    //printf("\n TEXTURE HEIGHT = %d\n", game->texture->height);
    ray->step = 1.0 * game->texture->height / ray->line_height;
    ray->tex_pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2) * ray->step;
    //printf("w_x %f st %f t_p %f t_x %d\n", ray->wall_x, ray->step, ray->tex_pos, ray->tex_x);
    while (++y < ray->draw_start)
        my_mlx_pixel_put(game, x, y, game->textures_data->c);
    while (y < ray->draw_end)
    {
        ray->tex_y = (int)ray->tex_pos & (game->texture->height - 1);
        ray->tex_pos += ray->step;
        my_mlx_pixel_put(game, x, y, get_image_color(game->texture, ray->tex_x, ray->tex_y));
        y++;
    } 
    while (y < HEIGHT)
    {
       my_mlx_pixel_put(game, x, y, game->textures_data->f);
       y++;    
    }
 
}

int    raycasting( t_game *game )
{
    printf("RAYCAST\n");
    t_raycast   ray;
    t_player    *player;
    int         x;

    x = 0;
    player = game->player_data;
    //mlx_clear_window(game->mlx_data->mlx, game->mlx_data->window);
    while (x < WIDTH)
    {
        get_ray_dir_pos(x, &ray, game->player_data);
        //printf("c %f r_x %f r_y %f m_x %d m_y %d\n\n", ray.camera_x, ray.ray_dir_x, ray.ray_dir_y, ray.map_x, ray.map_y);
        process_DDA(&ray, game);
        get_wall_projection(&ray);
        //printf("p_w %f H %d l_h %d d_s %d d_e %d\n", ray.perp_wall_dist, HEIGHT, ray.line_height, ray.draw_start, ray.draw_end);
        get_texture_coord(&ray, game);
        draw_window(x, &ray, game);
    
        //printf("length = %d perp_dist = %f\n\n\n", ray.line_height, ray.perp_wall_dist);
        //printf("******side = %f y delta = %f\n****", ray.side_dist_x, ray.delta_dist_x);
        ///printf("******pos x = %f y map_x = %d\n ****", player->pos_x, ray.map_x);
        x++;
    }
    return (0);
}
