/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:38:19 by severi            #+#    #+#             */
/*   Updated: 2022/06/15 22:07:05 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/*
int	chk_piece_fit(t_base *piece, t_base *map)
{
	int	x;
	int	y;
	int	i;
	int	j;
	
	x = 0;
	y = 0;
	i = 0;
	j = 0;
	if (piece->contents[x][y] == map->contents[i][j])
		return (1);
	return (0);
}
*/
/*
int		dist_between(int x1, int y1, int x2, int y2)
{
	int	x;
	int y;

	x = x2 - x1;
	y = y2 - y1;
	
	return (y + x);
}


void	find_clo(t_base *map, t_player *player)
{
	char	enemy;
	int		dist;
	int		xy[2];

	dist = 9999;
	xy[0] = 0;
	xy[1] = 0;
	while (i < map.length)
	{
		while (j < map.height)
		{
			if (map->contents[i][j] == player_char)
			{
				if ( dist < dist_between(i, j, player->x, player->y))
				{
					dist = dist_between(i, j, player->x, player->y);
					xy[0] = i;
					xy[1] = j;
				}
			}
			j++;
		}
		j = 0;
		i++
	}

void	fnd_clo_ene(t_base *map, t_player *player)
{
	char	enemy;
	int		dist;


	dist = 99999;
	enemy = 'O';
	if (player->player_num == 2)
		enemy = 'X';
	while()

	while (i < map.length)
	{
		while (j < map.height)
		{
			if (map[i][j] == enemy)
			{
				player->x = i;
				player->y = j;
				find_clo(map, player);

			}
			j++;
		}
		j = 0;
		i++
	}
}

*/

/// 012345
//0	......
//1	......
//2	..x...
//3	......
//
//	012
//0	**.
//1	.**
//

/*
void	try_piece(t_base *piece, t_base *map, t_player *player)
{
	if (outside_of_map(piece, map, player)!)
				{
					count = overlays(piece, map, player);
					if (count == 1)
						return (1);
				}
}
*/



static t_player	*set_up_player(void)
{
	t_player	*player;

	player = (t_player*)malloc(sizeof(t_player));
	player->player_num = 1;
	player->player_char = 'O';
	player->last_pos = 'o';
	player->enemy_char = 'X';
	player->enemy_last_pos = 'x';
	player->x = 0;
	player->y = 0;
	return (player);
	}

static void	exchange_player_chars(t_player *player)
{
	player->player_num = 2;
	player->player_char = 'X';
	player->last_pos = 'x';
	player->enemy_char = 'O';
	player->enemy_last_pos = 'o';
}

int	main(void)
{
	char	*buf;
	int		fd;
	int		read;
	int		row_num;
	char	*found;
	int		end;
	t_player	*player;
	t_base	*map;
	t_base	*piece;

	end = 0;
	read = 1;
	row_num = 0;
	player = set_up_player();
	fd = open("logs.txt", O_WRONLY);
	ft_putstr_fd("STARTING NEW LOGGING\n\n", fd);
	read = get_next_line(0, &buf);
	found = ft_strstr(buf, "exec p1");
	ft_putchar_fd('\n',fd);
	ft_putstr_fd(buf, fd);
	ft_putchar_fd('\n',fd);
	if (found == NULL)
		exchange_player_chars(player);
	found = NULL;
	ft_putchar_fd('P',fd);
//	ft_putstr_fd(ft_itoa(player->player_num), fd);
	ft_putchar_fd('\n',fd);
	ft_strdel(&buf);
//	free(buf);
	read = get_next_line(0, &buf);
	found = ft_strstr(buf, "Plateau");
	if (found != NULL)
	{
		map = create_empty(get_dim(buf, 1), get_dim(buf, 2));
		print_map(map, fd);
	}
	found = NULL;
	ft_strdel(&buf);
	while(1 && end == 0)
	{
		while((read = get_next_line(0, &buf)) != 0 && end == 0)
		{
			ft_putstr_fd("### ", fd);
			ft_putstr_fd(buf, fd);
			ft_putchar_fd('\n',fd);
			found = ft_strstr(buf, "Piece");
			if (ft_isdigit(buf[0]) == 1)
				update_map(map, buf);
			else if (found != NULL)
			{
				piece = create_empty(get_dim(buf, 1), get_dim(buf, 2));
				found = NULL;
			}
			else if (buf[0] == '.' || buf[0] == '*')
			{
				row_num = row_num + update_piece(piece, buf);
				if (piece->height == row_num)	
				{
					end = place_piece(piece, map, player, fd);
					row_num = 0;
					free_base(&piece);
				}
			}
			ft_strdel(&buf);
		}
		
//		ft_putstr_fd("printing map\n", fd);
//		ft_putstr_fd("player: ", fd);
//		ft_putchar_fd(player->player_char, fd);
//		ft_putstr_fd("\n", fd);
//		print_map(map, fd);
		//fd = open("logs.txt", O_WRONLY);
	}
	return (0);
}
