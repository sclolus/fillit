/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:22:07 by jguyon            #+#    #+#             */
/*   Updated: 2016/11/09 21:35:46 by jguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# define MAX_FILE_SIZE 545
# define MAX_TETRI_COUNT 26
# define BLOCK_COUNT 4
# define FILE_ERROR 0

# include <sys/types.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_block
{
	size_t	x;
	size_t	y;
}				t_block;

typedef struct	s_tetri
{
	t_block	blocks[BLOCK_COUNT];
	size_t	width;
	size_t	height;
	size_t	x;
	size_t	y;
}				t_tetri;

size_t			ft_read_file(char *path, char **content);
size_t			ft_read_content(char *content, size_t size);
size_t			ft_get_tetris(char *content, size_t count, t_tetri **tetris);
void			ft_write_solution(size_t square_size, t_tetri **tetris);

#endif
