/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wboutzou <wboutzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:16:20 by wboutzou          #+#    #+#             */
/*   Updated: 2022/06/26 00:34:58 by wboutzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw(t_game	*game, int i, int j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx \
		, game->mlx_win, game->wall, j * 50, i * 50);
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx \
		, game->mlx_win, game->o, j * 50, i * 50);
	else if (game->map[i][j] == 'P')
	{
		mlx_put_image_to_window(game->mlx \
		, game->mlx_win, game->p, j * 50, i * 50);
		game->pos.player_y = i;
		game->pos.player_x = j;
	}
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx \
		, game->mlx_win, game->e, j * 50, i * 50);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx \
		, game->mlx_win, game->c, j * 50, i * 50);
}

void	render(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			draw(game, i, j);
			j++;
		}
		i++;
	}
}

void	move(t_game *game, int step_y, int step_x)
{
	if (game->map[game->pos.player_y + step_y] \
	[game->pos.player_x + step_x] != '1')
	{
		check_move(game, step_y, step_x);
		game->pos.player_x = game->pos.player_x + step_x;
		game->pos.player_y = game->pos.player_y + step_y;
	}
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53 || keycode < 0)
		exit(1);
	else if (keycode == 13)
		move(game, -1, 0);
	else if (keycode == 1)
		move(game, 1, 0);
	else if (keycode == 0)
		move(game, 0, -1);
	else if (keycode == 2)
		move(game, 0, 1);
	render(game);
	return (0);
}

void	window(t_game *game)
{
	int	size;

	size = 50;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx \
	, 50 * game->width, 50 * game->height, "so long");
	game->e = mlx_xpm_file_to_image(game->mlx \
	, "./assets/E/1.xpm", &size, &size);
	game->p = mlx_xpm_file_to_image(game->mlx \
	, "./assets/player/2.xpm", &size, &size);
	game->c = mlx_xpm_file_to_image(game->mlx \
	, "./assets/P/1.xpm", &size, &size);
	game->o = mlx_xpm_file_to_image(game->mlx \
	, "./assets/O/1.xpm", &size, &size);
	game->wall = mlx_xpm_file_to_image(game->mlx \
	, "./assets/wall/1.xpm", &size, &size);
}