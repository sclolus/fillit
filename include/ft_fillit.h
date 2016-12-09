/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:22:07 by jguyon            #+#    #+#             */
/*   Updated: 2016/11/28 23:46:47 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# define MAX_FILE_SIZE 545
# define GRID_SIZE 22

# include <sys/types.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_block
{
	size_t	x;
	size_t	y;
}				t_block;

typedef struct	s_box
{
	unsigned char	row0 : 4;
	unsigned char	row1 : 4;
	unsigned char	row2 : 4;
	unsigned char	row3 : 4;
}				t_box;

typedef struct	s_tetri
{
	t_box			box;
	size_t			x;
	size_t			y;
	struct s_tetri	*prev;
	size_t			width;
	size_t			height;
	t_block			blocks[4];
}				t_tetri;

typedef struct	s_square
{
	unsigned int	grid[GRID_SIZE];
	size_t			size;
}				t_square;

size_t			ft_read_file(char *restrict path, char **restrict content);
size_t			ft_read_content(char *restrict content, size_t size);
size_t			ft_get_tetris(char *content, size_t count, t_tetri **tetris);
void			ft_init_square(t_square *restrict square, size_t count,
								t_tetri **restrict tetris);
int				ft_claim(t_square *restrict square, t_tetri *restrict tetri);
void			ft_unclaim(t_square *restrict square, t_tetri *restrict tetri);
int				ft_move(t_square *restrict square, t_tetri *restrict tetri);
void			ft_solve(t_square *restrict square, size_t count,
							t_tetri **restrict tetris);
void			ft_print_solution(t_square *restrict square, size_t count,
									t_tetri **restrict tetris);
void			ft_destroy_tetris(size_t count, t_tetri **restrict tetris);

#endif
