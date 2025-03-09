/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dqaddomi <dqaddomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 01:30:21 by daniah            #+#    #+#             */
/*   Updated: 2025/03/09 13:28:28 by dqaddomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	img(t_game *game)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "./assets/wall.xpm",
			&game->img_width, &game->img_height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "./assets/player.xpm",
			&game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "./assets/exit.xpm",
			&game->img_width, &game->img_height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"./assets/chips.xpm", &game->img_width, &game->img_height);
	game->img_empty = mlx_xpm_file_to_image(game->mlx, "./assets/green.xpm",
			&game->img_width, &game->img_height);
	if (!game->img_wall)
		ft_printf("Error: Failed to load wall image\n");
	if (!game->img_player)
		ft_printf("Error: Failed to load player image\n");
	if (!game->img_exit)
		ft_printf("Error: Failed to load exit image\n");
	if (!game->img_collectible)
		ft_printf("Error: Failed to load collectible image\n");
	if (!game->img_empty)
		ft_printf("Error: Failed to load empty image\n");
	if (!game->img_collectible || !game->img_exit || !game->img_player
		|| !game->img_wall || !game->img_empty)
		return (1);
	return (0);
}

void	render(t_game *game)
{
	game->x = 0;
	while (game->x < game->row)
	{
		game->y = 0;
		while (game->y < game->column)
		{
			if (game->map[game->x][game->y] == 'P')
				mlx_put_image_to_window(game->mlx, game->window,
					game->img_player, game->y * 32, game->x * 32);
			if (game->map[game->x][game->y] == '1')
				mlx_put_image_to_window(game->mlx, game->window, game->img_wall,
					game->y * 32, game->x * 32);
			else if (game->map[game->x][game->y] == '0')
				mlx_put_image_to_window(game->mlx, game->window,
					game->img_empty, game->y * 32, game->x * 32);
			else if (game->map[game->x][game->y] == 'C')
				mlx_put_image_to_window(game->mlx, game->window,
					game->img_collectible, game->y * 32, game->x * 32);
			else if (game->map[game->x][game->y] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, game->img_exit,
					game->y * 32, game->x * 32);
			game->y++;
		}
		game->x++;
	}
}

void	initialize_window(t_game *game)
{
	int	window_width;
	int	window_height;

	window_width = game->column * 32;
	window_height = game->row * 32;
	game->window = mlx_new_window(game->mlx, window_width, window_height,
			"I'm just a girl <3");
	if (!game->window)
	{
		ft_printf("Error: Failed to create window\n");
		exit(1);
	}
}

void	free_game(t_game *game)
{
	if (game->map != NULL)
		free_map(game->map);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->img_empty)
		mlx_destroy_image(game->mlx, game->img_empty);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}
