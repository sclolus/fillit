/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_claimed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 04:33:16 by sclolus           #+#    #+#             */
/*   Updated: 2016/11/10 04:50:36 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int				ft_is_claimed(t_square *square, t_tetri *tetri)
{
	int	i;

	i = -1;
	while (++i < BLOCK_COUNT)
	{
		if (square->blocks[CELL(tetri, i, square->size)])
			return (1);
	}
	return (0);
}
