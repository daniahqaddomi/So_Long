/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dqaddomi <dqaddomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:40:12 by daniah            #+#    #+#             */
/*   Updated: 2025/03/09 14:10:19 by dqaddomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <libft.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 500
# define HEIGHT 500

typedef struct s_data
{
	int		position_x;
	int		position_y;

}			t_data;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	int		player_x;
	int		player_y;
	int		moves;
	int		exit_num;
	int		start_pos;
	int		collectibles_num;
	int		img_width;
	int		img_height;
	void	*img_wall;
	void	*img_player;
	void	*img_exit;
	void	*img_collectible;
	void	*img_empty;
	char	**map;
	int		row;
	int		column;
	int		i;
	int		j;
	int		x;
	int		y;
	int		exit_flag;
	t_data	data;
}			t_game;

// so_long.c
int			main(int argc, char *argv[]);
void		initialize(t_game *game, t_data *data);
void		initialize_game(t_game *game, char *map_path);
// read_map.c
char		*read_line(int fd, t_game *game, char *tmp);
char		**read_map(t_game *game, char *file_path);
int			empty_map(t_game *game);
int			validate_map_elements(t_game *game);
int			validate_map(t_game *game);
// checks.c
int			check_map_elements(t_game *game);
int			check_walls(t_game *game);
void		free_map(char **map);
// map.c
int			img(t_game *game);
void		render(t_game *game);
void		initialize_window(t_game *game);
// key.c
int			keypress(int keycode, t_game *game);
void		new_map_position(t_game *game, int new_position_x,
				int new_position_y);
void		exit_game(t_game *game);
void		setup_hooks(t_game *game);
void		free_game(t_game *game);
// flood.c
int			**init_track_map(t_game *game);
void		flood_fill(t_game *game, int x, int y, int **track_map);
int			check_reachability(t_game *game, int **track_map);
int			check_game_access(t_game *game);

#endif
