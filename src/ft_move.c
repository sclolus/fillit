/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 04:54:29 by jguyon            #+#    #+#             */
/*   Updated: 2016/11/28 23:42:47 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int		ft_move(t_square *restrict square, t_tetri *restrict tetri)
{
	if (tetri->x + tetri->width < square->size)
		++(tetri->x);
	else if (tetri->y + tetri->height < square->size)
	{
		tetri->x = 0;
		++(tetri->y);
	}
	else
		return (0);
	return (1);
}
