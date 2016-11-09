/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tetris.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 19:15:09 by jguyon            #+#    #+#             */
/*   Updated: 2016/11/09 21:29:28 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

static void		ft_read_tetri(char **content, t_tetri *tetri)
{
	size_t	i;
	size_t	j;
	size_t	k;

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
}

static void		ft_normalize_tetri(t_tetri *tetri)
{
	t_block	min;
	t_block	max;
	int		i;

	min.x = BLOCK_COUNT - 1;
	min.y = BLOCK_COUNT - 1;
	max.x = 0;
	max.y = 0;
	i = -1;
	while (++i < BLOCK_COUNT)
	{
		min.x = tetri->blocks[i].x < min.x ? tetri->blocks[i].x : min.x;
		min.y = tetri->blocks[i].y < min.y ? tetri->blocks[i].y : min.y;
		max.x = tetri->blocks[i].x > max.x ? tetri->blocks[i].x : max.x;
		max.y = tetri->blocks[i].y > max.y ? tetri->blocks[i].y : max.y;
	}
	tetri->width = max.x - min.x + 1;
	tetri->height = max.y - min.y + 1;
	i = -1;
	while (++i < BLOCK_COUNT)
	{
		tetri->blocks[i].x -= min.x;
		tetri->blocks[i].y -= min.y;
	}
}

size_t			ft_get_tetris(char *content, size_t count, t_tetri **tetris)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		if (!(tetris[i] = (t_tetri *)malloc(sizeof(**tetris))))
			return (0);
		ft_read_tetri(&content, tetris[i]);
		ft_normalize_tetri(tetris[i++]);
	}
	return (i);
}
