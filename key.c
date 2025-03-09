/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dqaddomi <dqaddomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 02:47:29 by daniah            #+#    #+#             */
/*   Updated: 2025/03/06 12:43:29 by dqaddomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keypress(int keycode, t_game *game)
{
	int	new_position_x;
	int	new_position_y;

	new_position_x = game->player_x;
	new_position_y = game->player_y;
	if (keycode == XK_Left || keycode == XK_A || keycode == XK_a)
		new_position_x--;
	else if (keycode == XK_Right || keycode == XK_D || keycode == XK_d)
		new_position_x++;
	else if (keycode == XK_Down || keycode == XK_S || keycode == XK_s)
		new_position_y++;
	else if (keycode == XK_Up || keycode == XK_W || keycode == XK_w)
		new_position_y--;
	else if (keycode == XK_Escape)
		exit_game(game);
	if (new_position_y < 0 || new_position_y >= game->row || new_position_x < 0
		|| new_position_x >= game->column)
		return (0);
	new_map_position(game, new_position_x, new_position_y);
	render(game);
	return (0);
}

void	new_map_position(t_game *game, int new_position_x, int new_position_y)
{
	if (game->map[new_position_y][new_position_x] != '1')
	{
		game->moves++;
		ft_printf("Player Moves:  %d\n", game->moves);
		if (game->map[new_position_y][new_position_x] == 'C')
			game->collectibles_num--;
		if (game->exit_flag)
			game->map[game->player_y][game->player_x] = 'E';
		else
			game->map[game->player_y][game->player_x] = '0';
		game->player_y = new_position_y;
		game->player_x = new_position_x;
		if (game->map[new_position_y][new_position_x] == 'E')
			game->exit_flag = 1;
		else
			game->exit_flag = 0;
		game->map[new_position_y][new_position_x] = 'P';
		if (game->exit_flag && game->collectibles_num == 0)
		{
			ft_printf("YAAAY, You Win :)\n");
			exit_game(game);
		}
	}
}

int	close_window(t_game *game)
{
	exit_game(game);
	return (0);
}

void	exit_game(t_game *game)
{
	free_game(game);
	exit(0);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->window, 2, 1L << 0, keypress, game);
	mlx_hook(game->window, 17, 0, close_window, game);
}
