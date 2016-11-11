/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 05:23:47 by jguyon            #+#    #+#             */
/*   Updated: 2016/11/12 00:00:50 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

static size_t	ft_max(size_t n1, size_t n2)
{
	return (n2 > n1 ? n2 : n1);
}

static size_t	ft_get_size(size_t size, size_t count, t_tetri **tetris)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		size = ft_max(size, tetris[i]->width);
		size = ft_max(size, tetris[i]->height);
		++i;
	}
	return (size);
}

void			ft_init_square(t_square *square, size_t count, t_tetri **tetris)
{
	size_t	size;
	size_t	i;

	if (count == 1)
		size = (ft_max(tetris[0]->width, tetris[0]->height));
	else
	{
		size = 2;
		while (size * size < 4 * count)
			++size;
	}
	if (size < 4)
		size = ft_get_size(size, count, tetris);
	square->size = size;
	i = 0;
	while (i < GRID_SIZE)
	{
		square->grid[i] = 0;
		++i;
	}
}
