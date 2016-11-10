/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:23:38 by jguyon            #+#    #+#             */
/*   Updated: 2016/11/11 00:51:57 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_fillit.h"

void	ft_puttetri(t_tetri *tetri)
{
	size_t	i;
	size_t	len;
	char	str[21];

	i = 0;
	while (i < (tetri->width + 1) * tetri->height)
	{
		if ((i + 1) % (tetri->width + 1) == 0)
			str[i] = '\n';
		else
			str[i] = '.';
		++i;
	}
	str[i] = '\n';
	len = i;
	i = 0;
	while (i < BLOCK_COUNT)
	{
		str[tetri->blocks[i].y * (tetri->width + 1) + tetri->blocks[i].x] = '#';
		++i;
	}
	write(1, str, len);
}

#include <stdio.h>

int		main(int argc, char **argv)
{
	char	*str;
	size_t	nbr_tetris;
	size_t	size;
	t_tetri	**tetris;
	size_t	i;
	t_square	square;

	str = NULL;
	tetris = NULL;
	if (argc != 2
		|| !(str = (char*)malloc(sizeof(char) * MAX_FILE_SIZE + 1))
		|| !(size = ft_read_file(argv[1], &str))
		|| !(nbr_tetris = ft_read_content(str, size))
		|| !(tetris = (t_tetri**)malloc (sizeof(t_tetri*) * nbr_tetris))
		|| !(ft_get_tetris(str, nbr_tetris, tetris)))
	{
		free(str);
		free(tetris);
		write(1, "error\n", 6);
		return (0);
	}
	ft_init_square(&square, nbr_tetris, tetris);
	ft_solve(&square, nbr_tetris, tetris);
	i = 0;
/*	while (i < nbr_tetris)
	{
		ft_puttetri(tetris[i]);
		printf("%zu,%zu\n\n", tetris[i]->x, tetris[i]->y);
		write(1, "\n", 1);
		++i;
	}
	printf("%zu\n", square.size);*/
	ft_print_solution(&square, nbr_tetris, tetris);
	return (0);
}
