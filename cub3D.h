/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imane <imane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:13:44 by irhesri           #+#    #+#             */
/*   Updated: 2023/01/28 18:43:38 by imane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <string.h>
# include <limits.h>

# include "./data.h"
# include "./macros.h"

// void	draw_lines(t_segment *seg, t_window *win, double *len);
void	draw_lines(t_segment *seg, t_window *win);
// int	**get_map_arr(t_map *lines, t_data *data);
void	draw_view_angle(t_data *data, t_window *win);
void	draw_map(t_image *img, t_data *data);

char	*get_next_line(int fd, size_t *t_len);
int		check_files(char *s1, char *s2);
int		my_strlen(char *s);
short	add_back(t_map **map, t_map **last, t_map *nnode);
t_map	*new(char *line, int len);
void	init_data(t_data *data);
void	parse_time(t_data *data, int fd);
short	element(t_data *data, char *element, int len);

#endif
