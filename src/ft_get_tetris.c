/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tetris.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 19:15:09 by jguyon            #+#    #+#             */
/*   Updated: 2016/11/12 00:46:05 by jguyon           ###   ########.fr       */
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
	while (i < 4)
	{
		j = 0;
		while (j < 4)
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

	min.x = 4 - 1;
	min.y = 4 - 1;
	max.x = 0;
	max.y = 0;
	i = -1;
	while (++i < 4)
	{
		min.x = tetri->blocks[i].x < min.x ? tetri->blocks[i].x : min.x;
		min.y = tetri->blocks[i].y < min.y ? tetri->blocks[i].y : min.y;
		max.x = tetri->blocks[i].x > max.x ? tetri->blocks[i].x : max.x;
		max.y = tetri->blocks[i].y > max.y ? tetri->blocks[i].y : max.y;
	}
	tetri->width = max.x - min.x + 1;
	tetri->height = max.y - min.y + 1;
	i = -1;
	while (++i < 4)
	{
		tetri->blocks[i].x -= min.x;
		tetri->blocks[i].y -= min.y;
	}
}

static void		ft_init_box(t_tetri *tetri)
{
	size_t	i;

	tetri->box.row0 = 0;
	tetri->box.row1 = 0;
	tetri->box.row2 = 0;
	tetri->box.row3 = 0;
	i = 0;
	while (i < 4)
	{
		if (tetri->blocks[i].y == 0)
			tetri->box.row0 |= 0b1000 >> tetri->blocks[i].x;
		else if (tetri->blocks[i].y == 1)
			tetri->box.row1 |= 0b1000 >> tetri->blocks[i].x;
		else if (tetri->blocks[i].y == 2)
			tetri->box.row2 |= 0b1000 >> tetri->blocks[i].x;
		else if (tetri->blocks[i].y == 3)
			tetri->box.row3 |= 0b1000 >> tetri->blocks[i].x;
		++i;
	}
}

static void		ft_find_prev(t_tetri **tetris, size_t i)
{
	size_t	j;

	tetris[i]->prev = NULL;
	j = i;
	while (j-- > 0)
	{
		if (tetris[i]->box.row0 == tetris[j]->box.row0
			&& tetris[i]->box.row1 == tetris[j]->box.row1
			&& tetris[i]->box.row2 == tetris[j]->box.row2
			&& tetris[i]->box.row3 == tetris[j]->box.row3)
		{
			tetris[i]->prev = tetris[j];
			return ;
		}
	}
}

size_t			ft_get_tetris(char *content, size_t count, t_tetri **tetris)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < count)
	{
		if (!(tetris[i] = (t_tetri *)malloc(sizeof(**tetris))))
		{
			j = 0;
			while (j < i)
				free(tetris[j++]);
			return (0);
		}
		ft_read_tetri(&content, tetris[i]);
		tetris[i]->x = 0;
		tetris[i]->y = 0;
		ft_normalize_tetri(tetris[i]);
		ft_init_box(tetris[i]);
		ft_find_prev(tetris, i);
		++i;
	}
	return (i);
}
