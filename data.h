/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imane <imane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:13:44 by irhesri           #+#    #+#             */
/*   Updated: 2023/01/28 18:39:16 by imane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

typedef struct s_image
{
	int		bit;
	int		size;
	int		endian;
	char	*address;
	void	*img;
} t_image;

typedef struct s_window
{
	void		*mlx;
	void		*win;
	t_image		*image;
} t_window;

typedef struct s_map
{
	char			*line;
	long long		llen;
	struct s_map	*next;
	struct s_map	*prev;
} t_map;

typedef struct s_data
{
	char	*textures[4];
	int		colors[2];
	int		player[3];
	size_t	max;
	size_t	lines;
	t_map	*map;
	double	teta;
	t_window *win;
	long long p[2];
	// int	**map_arr;
} t_data;

typedef struct s_segment
{
	short			b;
	short			add[2];
	long			color;
	long long		xi;
	long long		yi;
	long long		xf;
	long long		yf;
} t_segment;

#endif