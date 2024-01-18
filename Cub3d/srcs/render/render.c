/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 00:40:14 by llevasse          #+#    #+#             */
/*   Updated: 2024/01/15 09:34:17 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_in_range(float nb, int min, int max);

int	render(t_cub *cub)
{
	int		x;
	float	ca;
	float	done;

	move(cub);
	ca = no_higher(cub->player.pa - (PLAYER_FOV / 2), 360, 0);
	x = 0;
	done = 0;
	cub->door = NULL;
	while (done < PLAYER_FOV)
	{
		if (done >= (PLAYER_FOV / 2) - 1 && done <= (PLAYER_FOV / 2) + 1
			&& !cub->door)
			cub->door = cast(cub, get_cast_data(cub, ca, 1), x++);
		else
			cast(cub, get_cast_data(cub, ca, 0), x++);
		done += cub->field_step;
		ca = no_higher(ca + cub->field_step, 360, 0);
	}
	draw_minimap(cub);
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->img.mlx_img, 0, 0);
	if (cub->door)
		mlx_string_put(cub->mlx_ptr, cub->win_ptr, WINDOW_W / 2, WINDOW_H / 2,
			0xFF0000, "Press 'E'");
	return (0);
}

void	img_pix_put(t_img *img, int x, int y, int colour)
{
	char	*pixel;
	int		i;

	if (x < 0 || x > WINDOW_W || y < 0 || y > WINDOW_H)
		return ;
	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel = (colour >> i) & 0xFF;
		else
			*pixel = (colour >> (img->bpp - 8 - i)) & 0xff;
		pixel++;
		i -= 8;
	}
}
