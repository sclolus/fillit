/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 04:54:29 by jguyon            #+#    #+#             */
/*   Updated: 2016/11/10 05:00:01 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int		ft_move(t_square *square, t_tetri *tetri)
{
	if (tetri->x + tetri->width < square->size - 1)
		++(tetri->x);
	else if (tetri->y + tetri->height < square->size - 1)
	{
		tetri->x = 0;
		++(tetri->y);
	}
	else
		return (0);
	return (1);
}
