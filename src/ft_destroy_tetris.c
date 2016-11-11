/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_tetris.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 23:33:12 by jguyon            #+#    #+#             */
/*   Updated: 2016/11/11 23:34:22 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void	ft_destroy_tetris(size_t count, t_tetri **tetris)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(tetris[i]);
		++i;
	}
	free(tetris);
}
