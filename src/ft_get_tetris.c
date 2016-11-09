/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tetris.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 19:15:09 by jguyon            #+#    #+#             */
/*   Updated: 2016/11/09 20:45:40 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

static t_tetri	*ft_get_tetri(char **content)
{
	size_t	i;
	size_t	j;
	size_t	k;
	t_tetri	*tetri;

	if (!(tetri = (t_tetri *)malloc(sizeof(*tetri))))
		return (NULL);
	k = 0;
	i = 0;
	while (i < BLOCK_COUNT)
	{
		j = 0;
		while (j < BLOCK_COUNT)
		{
			if (**content == '#')
			{
				tetri->blocks[k].x = j;
				tetri->blocks[k].y = i;
				++k;
			}
			++(*content);
			++j;
		}
		++(*content);
		++i;
	}
	++(*content);
	return (tetri);
}

static void		ft_normalize_tetri(t_tetri *tetri)
{
	size_t	xmin;
	size_t	ymin;
	size_t	xmax;
	size_t	ymax;
	size_t	i;

	xmin = BLOCK_COUNT - 1;
	ymin = BLOCK_COUNT - 1;
	xmax = 0;
	ymax = 0;
	i = 0;
	while (i < BLOCK_COUNT)
	{
		if (tetri->blocks[i].x < xmin)
			xmin = tetri->blocks[i].x;
		if (tetri->blocks[i].y < ymin)
			ymin = tetri->blocks[i].y;
		if (tetri->blocks[i].x > xmax)
			xmax = tetri->blocks[i].x;
		if (tetri->blocks[i].y > ymax)
			ymax = tetri->blocks[i].y;
		++i;
	}
	tetri->width = xmax - xmin + 1;
	tetri->height = ymax - ymin + 1;
	i = 0;
	while (i < BLOCK_COUNT)
	{
		tetri->blocks[i].x -= xmin;
		tetri->blocks[i].y -= ymin;
		++i;
	}
}

size_t			ft_get_tetris(char *content, size_t count, t_tetri **tetris)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		if (!(tetris[i] = ft_get_tetri(&content)))
			return (0);
		ft_normalize_tetri(tetris[i++]);
	}
	return (i);
}
