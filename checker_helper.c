/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wboutzou <wboutzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 21:35:15 by wboutzou          #+#    #+#             */
/*   Updated: 2022/06/26 00:41:25 by wboutzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall(t_game	*game)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < game->height)
	{
		if (i == 0 || i == game->height - 1)
		{
			j = 0;
			while (game->map[i][j] != '\0')
			{
				if (game->map[i][j] != '1')
					return (0);
					j++;
			}
		}
		else
			if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
				return (0);
		i ++;
	}
	return (1);
}

int	checkalpha(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	while (i < game->height - 1)
	{
		j = 1;
		while (j < game->width - 2)
		{
			if (game->map[i][j] == 'C')
				game->count.coll++;
			else if (game->map[i][j] == 'E')
				game->count.exit++;
			else if (game->map[i][j] == 'P')
				game->count.start++;
			else if (game->map[i][j] != '1' && game->map[i][j] != '0')
				return (0);
			j++;
		}
		i++;
	}
	if (game->count.coll < 1 || game->count.exit < 1 || game->count.start != 1)
		return (0);
	return (1);
}

int	check_size(t_game	*game)
{
	int	i;

	i = 0;
	if (game->map[i++] == '\0')
		return (0);
	while (game->map[i] != '\0')
	{
		if (ft_strlen(game->map[i - 1]) != ft_strlen(game->map[i]))
			return (0);
		i++;
	}
	game->width = ft_strlen(game->map[i - 1]);
	game->height = i;
	return (1);
}

int	check_read(char *read)
{
	int	i;
	int	j;
	int	n;
	int	pos;

	pos = 0;
	i = 0;
	j = 0;
	n = 0;
	if (read[0] == '\n')
		return (0);
	while (read[i] != '\0')
	{
		if (read[i] == '\n' && (read[i + 1] == '\n' || read[i + 1] == '\0'))
			return (0);
		i++;
	}
	return (1);
}

void	check_move(t_game *game, int step_y, int step_x)
{
	int	x;
	int	y;

	x = game->pos.player_x;
	y = game->pos.player_y;
	if (game->map[y + step_y][x + step_x] == 'C')
	{
		game->tmp = game->map[y + step_y][x + step_x];
		game->map[y + step_y][x + step_x] = game->map[y][x];
		game->map[y][x] = '0';
		game->count.coll--;
		game->count.moves++;
		ft_printf("%d\n", game->count.moves);
	}
	else if (game->map[y + step_y][x + step_x] == 'E' && game->count.coll <= 0)
	{
		game->count.moves++;
		ft_printf("%d\n", game->count.moves);
		exit(1);
	}
	else if (game->map[y + step_y][x + step_x] == '0')
	{
		game->tmp = game->map[y + step_y][x + step_x];
		game->map[y + step_y][x + step_x] = game->map[y][x];
		game->map[y][x] = game->tmp;
		game->count.moves++;
		ft_printf("%d\n", game->count.moves);
	}
}