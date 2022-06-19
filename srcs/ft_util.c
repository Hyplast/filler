/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:49:39 by severi            #+#    #+#             */
/*   Updated: 2022/06/15 22:58:33 by severi           ###   ########.fr       */
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
	int		i;
	int		j;
	t_base	*base;

	i = 0;
	j = 0;
	base = (t_base *) malloc(sizeof(t_base));
	base->contents = (int **) malloc(sizeof(int *) * (long unsigned int)height);
	while (i < height)
		base->contents[i++] = (int *)malloc(sizeof(int)
				* (long unsigned int)length);
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

void	free_player(t_player **player)
{	
	if (player == NULL)
		return ;
	free((*player));
	(*player) = NULL;
}

void	free_base(t_base **base)
{
	int	i;

	i = 0;
	if (base == NULL)
		return ;
	while (i < (*base)->height)
	{
		free((*base)->contents[i++]);
	}
	free((*base)->contents);
	free((*base));
	(*base) = NULL;
}

int	get_dim(char *str, int d)
{
	int		i;
	int		j;
	int		result;
	char	*temp;

	j = 0;
	i = 0;
	while (j != d)
	{
		while (str[i] != ' ')
			i++;
		i++;
		j++;
	}
	j = 0;
	while (ft_isdigit(str[i + j]) == 1)
		j++;
	temp = ft_strsub(str, (unsigned int)i, (unsigned int)j);
	result = ft_atoi(temp);
	ft_strdel(&temp);
	return (result);
}
