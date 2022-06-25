/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wboutzou <wboutzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:33:07 by wboutzou          #+#    #+#             */
/*   Updated: 2022/06/25 22:06:49 by wboutzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkarg(int argc, char *argv)
{
	char	*ft;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv, O_RDONLY);
		if (fd < 0)
		{
			printf("the map file not found :)");
			return (0);
		}
		ft = strrchr(argv, '.');
		if (ft != NULL)
		{
			if (!strcmp(ft, ".ber"))
				return (fd);
			else
				printf("the map format is .ber :)");
		}
		else
			ft_printf("Error \n");
	}
	else
		printf("you missing something (map) :) ");
	return (0);
}

int	checker_map(t_game *game)
{
	if (!check_size(game) || !check_wall(game))
		return (0);
	if (!checkalpha(game))
		return (0);
	return (1);
}

void	matrix(int fd, t_game *game)
{
	char	*read;
	int		i;

	i = 0;
	read = get_next_line(fd);
	if (read == NULL)
		return ;
	if (!check_read(read))
		return ;
	game->map = ft_split(read, '\n');
	if (game->map == NULL)
		return ;
}
