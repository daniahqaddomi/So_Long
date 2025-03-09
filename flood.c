/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniah <daniah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 23:11:59 by daniah            #+#    #+#             */
/*   Updated: 2025/03/02 01:08:06 by daniah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	**init_track_map(t_game *game)
{
	int	**track_map;

	track_map = malloc(sizeof(int *) * game->row);
	if (!track_map)
		return (NULL);
	game->i = 0;
	while (game->i < game->row)
	{
		track_map[game->i] = malloc(sizeof(int) * game->column);
		if (!track_map[game->i])
		{
			while (game->i--)
				free(track_map[game->i]);
			free(track_map);
			return (NULL);
		}
		game->j = 0;
		while (game->j < game->column)
		{
			track_map[game->i][game->j] = 0;
			game->j++;
		}
		game->i++;
	}
	return (track_map);
}

void	flood_fill(t_game *game, int x, int y, int **track_map)
{
	if (x < 0 || x >= game->row || y < 0 || y >= game->column)
		return ;
	if (game->map[x][y] == '1' || track_map[x][y])
		return ;
	track_map[x][y] = 1;
	flood_fill(game, x + 1, y, track_map);
	flood_fill(game, x - 1, y, track_map);
	flood_fill(game, x, y + 1, track_map);
	flood_fill(game, x, y - 1, track_map);
}

int	check_reachability(t_game *game, int **track_map)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->row)
	{
		j = 0;
		while (j < game->column)
		{
			if ((game->map[i][j] == 'C' || game->map[i][j] == 'E')
				&& !track_map[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_game_access(t_game *game)
{
	int	**track_map;
	int	res;
	int	i;

	track_map = init_track_map(game);
	if (!track_map)
		return (0);
	flood_fill(game, game->player_y, game->player_x, track_map);
	res = check_reachability(game, track_map);
	i = 0;
	while (i < game->row)
	{
		free(track_map[i]);
		i++;
	}
	free(track_map);
	return (res);
}
