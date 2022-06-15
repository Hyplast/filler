/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:49:00 by severi            #+#    #+#             */
/*   Updated: 2022/06/15 21:36:39 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
 * Create an structure of height x length dimensions of '.''s
 * @params height
 * @params length
 * @return base (t_base)
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
	base->size = length * height;
	base->x = 0;
	base->y = 0;
	return (base);
}

void	update_map(t_base *map, char *row)
{
	int	j;
	int i;
	int k;
	char	*temp;

	i = 0;
	j = 0;
	k = 0;
	while (row[i] != ' ')
		i++;
	temp = ft_strsub(row, 0, (size_t)i++);
	j = ft_atoi(temp);
	ft_strdel(&temp);
	while ((size_t)i < ft_strlen(row))
	{
		map->contents[j][k++] = (int)row[i++];
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


int	check_empty_rows(t_base *piece, int fd)
{
	int	empty;
	int	i;
	int j;

	i = piece->height - 1;
	j = piece->length - 1;
	empty = 0;
//	ft_putstr_fd("\ncheck rows: [",fd);
//	ft_putnbr_fd(i, fd);
//	ft_putstr_fd("],[", fd);
//	ft_putnbr_fd(j, fd);
//	ft_putstr_fd("] = ", fd);
//	ft_putchar_fd((char)piece->contents[i][j], fd);
	ft_putchar_fd('c', fd);
	while (i > 0 && piece->contents[i][j] != '*')
	{
		while (j > 0 && piece->contents[i][j] != '*')
		{
//			ft_putstr_fd("\ninside j loop in rows: [",fd);
//			ft_putnbr_fd(i, fd);
//			ft_putstr_fd("],[", fd);
////			ft_putnbr_fd(j, fd);
	//		ft_putstr_fd("]\n", fd);
			j--;
		}
		if (piece->contents[i][j] != '*')
		{
			empty++;
			j = piece->length - 1;
			i--;
		}
	}	
//	ft_putstr_fd("surviced rows!\n", fd);
	return (empty); 
}


int	check_empty_columns(t_base *piece, int fd)
{
	int	empty;
	int	i;
	int j;

	i = 0;
	j = piece->length - 1;
	empty = 0;
//	ft_putstr_fd("\ncheck columns: [",fd);
//	ft_putnbr_fd(i, fd);
//	ft_putstr_fd("],[", fd);
//	ft_putnbr_fd(j, fd);
//	ft_putstr_fd("] = ", fd);
//	ft_putchar_fd((char)piece->contents[i][j], fd);
	ft_putchar_fd('r', fd);

	while (j > 0 && piece->contents[i][j] != '*')
	{
		while (i < piece->height - 1 && piece->contents[i][j] != '*')
		{
//			ft_putstr_fd("\ninside i loop in columns: [",fd);
//			ft_putnbr_fd(i, fd);
//			ft_putstr_fd("],[", fd);
//			ft_putnbr_fd(j, fd);
//			ft_putstr_fd("]\n", fd);
			i++;
		}
		if (piece->contents[i][j] != '*')
		{
			empty++;
			i = 0;
			j--;
		}
	}
//	ft_putstr_fd("surviced columns!\n", fd);
	return (empty); 
}

/*
 *	Check if piece placed would be outside of map.
 */
int		outside_of_map(t_base *piece, t_base *map, t_player *player, int fd)
{
//	int	i;
//	int	j;
	int	rows;
	int	columns;

//	i = 0;
//	j = 0;
	rows = check_empty_rows(piece, fd);
	columns = check_empty_columns(piece, fd);
			if (piece->height - rows  > map->height - player->x 
				|| piece->length - columns  > map->length - player->y)
			{
				ft_putstr_fd("\nBEHOLD, THIS WAS OUTSIDE oF MAP\n", fd);	
				return (1);
			}
/*
//			ft_putchar_fd('\n', fd);
//			 ft_putnbr_fd(rows, fd);
//			 ft_putstr_fd(" <-empty rows, empty columns ->", fd);
		//	 ft_putnbr_fd(i , fd);
			 ft_putchar_fd(',', fd);	
//			 ft_putnbr_fd(columns , fd);
//			ft_putchar_fd('\n', fd);
	while (i < piece->height)
	{
		while (j < piece->length)
		{
//			ft_putstr_fd("inside outside_of_map: ", fd);
//			ft_putnbr_fd(player->x , fd);
//			 ft_putchar_fd(',', fd);	
			// ft_putnbr_fd(rows, fd);
		//	 ft_putstr_fd(" <-empty rows, empty columns ->", fd);
		//	 ft_putnbr_fd(i , fd);
		//	 ft_putchar_fd(',', fd);	
		//	 ft_putnbr_fd(columns , fd);
			 ft_putstr_fd(" piece->height - rows > map->height - player->x  = [", fd);
			 ft_putnbr_fd(piece->height , fd);
			 ft_putstr_fd("] - [", fd);	
			 ft_putnbr_fd(rows , fd);
			 ft_putstr_fd("] + [", fd);	
			 ft_putnbr_fd(i , fd);
			 ft_putstr_fd("] > [", fd);	
			 ft_putnbr_fd(map->height , fd);
			 ft_putstr_fd("] - [", fd);	
			 ft_putnbr_fd(player->x, fd);
			 ft_putstr_fd("]\n", fd);
			ft_putstr_fd(" piece->length - columns  > map->lenght - player->y  = [", fd);
			 ft_putnbr_fd(piece->length , fd);
			 ft_putstr_fd("] - [", fd);	
			 ft_putnbr_fd(columns , fd);
			 ft_putstr_fd("] + [", fd);	
			 ft_putnbr_fd(j , fd);
			 ft_putstr_fd("] > [", fd);	
			 ft_putnbr_fd(map->length , fd);
			 ft_putstr_fd("] - [", fd);	
			 ft_putnbr_fd(player->y, fd);
			 ft_putstr_fd("]\n", fd);

			// ft_putstr_fd(" kolme ", fd);	
			// ft_putnbr_fd(piece->height + i, fd);
			// ft_putchar_fd('>', fd); 
			// ft_putnbr_fd(map->height - player->x, fd);
			// ft_putchar_fd('|', fd);	
			// ft_putnbr_fd(piece->length + j, fd);
			// ft_putchar_fd('>', fd); 
			// ft_putnbr_fd(map->length - player->y, fd);
			// ft_putchar_fd('\n', fd);

			if (piece->height - rows  > map->height - player->x 
				|| piece->length - columns  > map->length - player->y)
			{
				ft_putstr_fd("\nBEHOLD, THIS WAS OUTSIDE oF MAP\n", fd);	
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
*/
	return (0);
}
