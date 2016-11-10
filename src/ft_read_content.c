/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 19:15:28 by sclolus           #+#    #+#             */
/*   Updated: 2016/11/11 00:44:01 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

static size_t	ft_read_tetri(char *content, size_t offset)
{
	size_t	nbr_line;
	size_t	nbr_blocks;
	size_t	u;

	u = 0;
	nbr_line = 0;
	nbr_blocks = 0;
	while (u < 5 && nbr_line < 4)
	{
		if (!(((content[offset] == '#' || content[offset] == '.')
			   && u < 4)
			  || (content[offset] == '\n' && u == 4)))
			return (FILE_ERROR);
		if (content[offset] == '#')
		{
			if ((u > 0 && content[offset - 1] == '#')
					|| (u < 3 && content[offset + 1] == '#')
					|| (nbr_line > 0 && content[offset - 5] == '#')
					|| (nbr_line < 3 && content[offset + 5] == '#'))
				nbr_blocks++;
			else
				return (0);
		}
		offset++;
		if (++u == 5)
		{
			u = 0;
			nbr_line++;
		}
	}
	if (nbr_blocks != BLOCK_COUNT)
		return (0);
	return (1);
}

size_t			ft_read_content(char *content, size_t size)
{
	size_t	offset;

	offset = 0;
	while (offset < size)
	{
		if (!(ft_read_tetri(content, offset)))
			return (0);
		offset += 20;
		if (content[offset] != '\n' && offset != size)
			return (FILE_ERROR);
		offset++;
	}
	return (size / 21 + 1);
}
