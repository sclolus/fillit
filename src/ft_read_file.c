/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 19:18:19 by sclolus           #+#    #+#             */
/*   Updated: 2016/11/28 23:41:26 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_fillit.h"

size_t			ft_read_file(char *restrict path, char **restrict content)
{
	int		fd;
	size_t	size;

	if (!(*content = (char *)malloc(sizeof(char) * (MAX_FILE_SIZE + 1))))
		return (0);
	if (!(fd = open(path, O_RDONLY)))
		return (0);
	if (MAX_FILE_SIZE == (size = read(fd, *content, MAX_FILE_SIZE))
		&& read(fd, *content + size, 1))
		return (0);
	close(fd);
	if (size % 21 != 20)
		return (0);
	return (size);
}
