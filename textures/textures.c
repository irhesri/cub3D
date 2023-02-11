/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-chi <sben-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:07:52 by sben-chi          #+#    #+#             */
/*   Updated: 2023/02/11 19:21:00 by sben-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

unsigned int	my_get_pixel_color(t_image *dt, long long x, long long y)
{
	return (*(unsigned int *)(dt->address
		+ (y * dt->len + x * (dt->bits / 8))));
}

t_image	*get_imgs_data(t_data *dt, long x)
{
	static t_image	*text_img;
	int				i;

	if (!text_img)
	{
		i = 0;
		text_img = malloc(4 * sizeof(t_image));
		while (i < 4)
		{
			text_img[i].img = mlx_xpm_file_to_image(dt->win->mlx,
					dt->textures[i], &text_img[i].w_img, &text_img[i].h_img);
			if (!text_img[i].img)
				exit(printf("Error: xpm_file\n"));
			text_img[i].address = mlx_get_data_addr(text_img[i].img,
					&text_img[i].bits, &text_img[i].len, &text_img[i].endian);
			i++;
		}
	}
	i = (dt->dir[x] == 'S') + (dt->dir[x] == 'E') * 2 + (dt->dir[x] == 'W') * 3;
	return (&text_img[i]);
}

void	textures(t_data *dt, long long x, long long *y, double wall_h)
{
	long	img_x;
	long	img_y;
	char	*dst;
	t_image	*win_img;
	t_image	*img_text;

	win_img = dt->win->image;
	img_text = get_imgs_data(dt, x);
	img_x = (long)(dt->diff[x] * (img_text->w_img / TILE)) % img_text->w_img;
	while ((y[0] < y[1]) && (y[0] < HEIGHT))
	{
		img_y = ((y[0] - ((HEIGHT - wall_h) / 2)) * (img_text->h_img / wall_h));
		dst = win_img->address + (y[0] * win_img->len + x * win_img->bits / 8);
		*(unsigned int *) dst = my_get_pixel_color(img_text, img_x, img_y);
		++y[0];
	}
}
