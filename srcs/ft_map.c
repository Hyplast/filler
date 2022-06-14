/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:49:00 by severi            #+#    #+#             */
/*   Updated: 2022/06/09 12:49:12 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
 * Create an structure of height x length dimensions of '.''s
 * @params height
 * @params length
 */
t_base	*create_empty(int height, int length)
{
	int 	i;
	int 	j;
	t_base	*base;

	i = 0;
	j = 0;
	base = (t_base*)malloc(sizeof(t_base));
	base->contents = (int **)malloc(sizeof(int*) * (long unsigned int)height);
	while (i < height)
		base->contents[i++] = (int *)malloc(sizeof(int) * (long unsigned int)length);
	i = 0;
	while (i < height)
	{
		while (j < length)
			base->contents[i][j++] = 46;
		j = 0;
		i++;
	}
	base->height = height;
	base->length = length;
	return (base);
}

void	update_map(t_base **map, char *row)
{
	int	j;
	int i;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (row[i] != ' ')
		i++;
	j = ft_atoi(ft_strsub(row, 0, (size_t)i++));
	while ((size_t)i < ft_strlen(row))
	{
		(*map)->contents[j][k++] = (int)row[i++];
	}
}

void print_map(t_base *map, int fd)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < map->height) // height
	{
		while (j < map->length) // length
		{
			ft_putchar_fd((char)(map->contents[i][j]), fd);
			//printf("%c", map[i][j]);
			j++;
		}
		j = 0;
		//printf("\n");
		ft_putchar_fd('\n', fd);
		i++;
	}
}

int		outside_of_map(t_base *piece, t_base *map, t_player *player, int fd)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (i < piece->height)
	{
		while (j < piece->length)
		{
			ft_putstr_fd("inside outside_of_map: ", fd);
			ft_putnbr_fd(player->x , fd);
			// ft_putchar_fd(',', fd);	
			// ft_putnbr_fd(player->y , fd);
			// ft_putstr_fd(" i,j :", fd);
			// ft_putnbr_fd(i , fd);
			// ft_putchar_fd(',', fd);	
			// ft_putnbr_fd(j , fd);
			// ft_putstr_fd(" length, height :", fd);

			// ft_putnbr_fd(piece->length , fd);
			// ft_putchar_fd(',', fd);	
			// ft_putnbr_fd(piece->height , fd);
			// ft_putstr_fd(" kolme ", fd);	
			// ft_putnbr_fd(piece->height + i, fd);
			// ft_putchar_fd('>', fd); 
			// ft_putnbr_fd(map->height - player->x, fd);
			// ft_putchar_fd('|', fd);	
			// ft_putnbr_fd(piece->length + j, fd);
			// ft_putchar_fd('>', fd); 
			// ft_putnbr_fd(map->length - player->y, fd);
			// ft_putchar_fd('\n', fd);

			if (piece->height + i > map->height - player->x 
				|| piece->length + j > map->length - player->y)
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
