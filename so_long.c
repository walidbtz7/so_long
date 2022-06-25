/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wboutzou <wboutzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:14:08 by wboutzou          #+#    #+#             */
/*   Updated: 2022/06/25 21:15:54 by wboutzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	t_game	game;

	i = 0;
	fd = checkarg(argc, argv[1]);
	if (fd == 0)
		return (0);
	matrix(fd, &game);
	if (game.map == NULL || !checker_map(&game))
	{
		ft_printf("Error\n");
		return (0);
	}
	window(&game);
	mlx_key_hook (game.mlx_win, key_hook, &game);
	mlx_hook(game.mlx_win, 17, 0, key_hook, &game);
	render(&game);
	mlx_loop(game.mlx);
	return (0);
}