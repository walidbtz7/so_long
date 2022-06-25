/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wboutzou <wboutzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:16:20 by wboutzou          #+#    #+#             */
/*   Updated: 2022/06/25 21:12:10 by wboutzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void render(t_game *game)
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
			j++;
		}
		i++;
	}
}

void	switch_pos(t_game *game, int step_y, int step_x)
{
	int		x;
	int		y;
	char	tmp;

	x = game->pos.player_x;
	y = game->pos.player_y;
	game->count.moves++;
	if (game->map[y + step_y][x + step_x] != '1')
	{
		if (game->map[y + step_y][x + step_x] == 'C')
		{
			tmp = game->map[y + step_y][x + step_x];
			game->map[y + step_y][x + step_x] = game->map[y][x];
			game->map[y][x] = '0';
			game->count.coll--;
			ft_printf("%d\n",game->count.moves);
		}
		else if (game->map[y + step_y][x + step_x] == 'E')
		{
			if (game->count.coll < 0)
			{
				ft_printf("%d\n", game->count.moves);
				exit(1);
			}
		}
		else
		{
			tmp = game->map[y + step_y][x + step_x];
			game->map[y + step_y][x + step_x] = game->map[y][x];
			game->map[y][x] = tmp;
			ft_printf("%d\n",game->count.moves);
		}
		game->pos.player_x = x + step_x;
		game->pos.player_y = y + step_y;
		game->count.moves++;
	}
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53 || keycode < 0)
		exit(1);
	else if (keycode == 13)
		switch_pos(game, -1, 0);
	else if (keycode == 1)
		switch_pos(game, 1, 0);
	else if (keycode == 0)
		switch_pos(game, 0, -1);
	else if (keycode == 2)
		switch_pos(game, 0, 1);
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