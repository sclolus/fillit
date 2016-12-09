/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 19:15:28 by sclolus           #+#    #+#             */
/*   Updated: 2016/11/28 23:41:24 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

static int		ft_check_char(char *content, size_t offset, size_t col)
{
	if ((col < 4 && content[offset] != '#' && content[offset] != '.')
		|| (col == 4 && content[offset] != '\n'))
		return (0);
	return (1);
}

static size_t	ft_count_neighbors(char *content, size_t i, size_t x, size_t y)
{
	size_t	neighbors;

	neighbors = 0;
	neighbors += (x > 0 && content[i - 1] == '#') ? 1 : 0;
	neighbors += (x < 3 && content[i + 1] == '#') ? 1 : 0;
	neighbors += (y > 0 && content[i - 5] == '#') ? 1 : 0;
	neighbors += (y < 3 && content[i + 5] == '#') ? 1 : 0;
	return (neighbors);
}

static int		ft_read_tetri(char *content, size_t offset)
{
	size_t	nbr_line;
	size_t	nbr_blocks;
	size_t	nbr_neighbors;
	size_t	u;

	u = 0;
	nbr_line = 0;
	nbr_blocks = 0;
	nbr_neighbors = 0;
	while (u < 5 && nbr_line < 4)
	{
		if (!(ft_check_char(content, offset, u)))
			return (0);
		if (content[offset] == '#' && ++nbr_blocks)
			nbr_neighbors += ft_count_neighbors(content, offset, u, nbr_line);
		offset++;
		if (++u == 5)
		{
			u = 0;
			nbr_line++;
		}
	}
	if (nbr_blocks != 4 || nbr_neighbors < 6)
		return (0);
	return (1);
}

size_t			ft_read_content(char *restrict content, size_t size)
{
	size_t	offset;

	offset = 0;
	while (offset < size)
	{
		if (!(ft_read_tetri(content, offset)))
			return (0);
		offset += 20;
		if (content[offset] != '\n' && offset != size)
			return (0);
		offset++;
	}
	return (size / 21 + 1);
}
