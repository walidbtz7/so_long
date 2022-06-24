#include "so_long.h"


void render(t_game *game)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if(game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall, j * 50, i * 50);
			else if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->o, j * 50, i * 50);
			else if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->o, j * 50, i * 50);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->e, j * 50, i * 50);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->c, j * 50, i * 50);
			j++;
		}
		i++;
	}
	
}


void move_x(t_game *game, int keycode)
{

	int x;
	int y;

	x = game->player_x;
	y = game->player_y;	
	if(keycode == 2)
	{
		ft_printf("%c",game->map[x][y]);
	}
	else if( keycode == 0)
	{
		ft_printf("%c",game->map[x][y]);
	}
}

int	key_hook(int keycode, t_game *game)
{
	if(game->height == 0)
		return (0);
	if(keycode == 13)
		ft_printf("UP\n");
	else if(keycode == 1)
		ft_printf("down\n");
	else if(keycode == 0)
	{
		move_x(game,keycode);
		ft_printf("left\n");
	}
	else if(keycode == 2)
	{
		move_x(game,keycode);
		ft_printf("Right\n");
	}
	return (0);
}


int main(int argc, char **argv)
{
	int fd;
	int i;
	t_game game;

	game.size = 50;
	i = 0;
	fd = checkarg(argc, argv[1]);
	if (fd == 0)
		return (0);
	matrix(fd,&game);
	if(game.map == NULL || !checker_map(&game))
	{
		ft_printf("Error\n");
		return (0);
	}
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, 50 * game.width, 50 * game.height, "Hello Word!");
	game.e = mlx_xpm_file_to_image(game.mlx, "./assets/E/1.xpm", &game.size, &game.size);
	game.p = mlx_xpm_file_to_image(game.mlx, "./assets/player/3.xpm", &game.size, &game.size);
	game.c = mlx_xpm_file_to_image(game.mlx, "./assets/P/1.xpm", &game.size, &game.size);
	game.o = mlx_xpm_file_to_image(game.mlx, "./assets/O/1.xpm", &game.size, &game.size);
	game.wall = mlx_xpm_file_to_image(game.mlx, "./assets/wall/1.xpm", &game.size, &game.size);
	mlx_key_hook (game.mlx_win, key_hook, &game);
	render(&game);
	mlx_loop(game.mlx);
	return (0);
}