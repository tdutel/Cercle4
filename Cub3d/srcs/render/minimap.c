/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 00:28:00 by llevasse          #+#    #+#             */
/*   Updated: 2024/01/15 18:15:20 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square(t_cub *cub, int x, int y, int colour)
{
	int	y_b;
	int	x_b;

	y_b = 0;
	while (y_b < MMAP_BLOCK_S)
	{
		x_b = 0;
		while (x_b < MMAP_BLOCK_S)
			img_pix_put(&cub->img, x + x_b++, y + y_b, colour);
		y_b++;
	}
}

static void	init_points(t_cub *cub, t_point *p, t_point *print, t_point *tmp)
{
	int	x;
	int	max_x;
	int	y;
	int	max_y;

	y = MMAP_BLOCK_S - 1;
	max_y = y + 1 + (MMAP_BLOCK_S * ((MMAP_RANGE * 2) + 1) + 1);
	max_x = max_y;
	while (y < max_y)
	{
		x = MMAP_BLOCK_S - 1;
		while (x < max_x)
			img_pix_put(&cub->img, x++, y, MMAP_W_RGB);
		y++;
	}
	tmp->y = (int)(cub->player.py / cub->mmap->block_s) - MMAP_RANGE;
	tmp->x = (int)(cub->player.px / cub->mmap->block_s) - MMAP_RANGE;
	p->y = tmp->y;
	print->y = 1;
}

static void	draw_row(t_cub *cub, t_point *p, t_point *print, t_point *tmp)
{
	while (p->y >= 0 && p->x < cub->mmap->mapx[(int)p->y]
		&& p->x <= tmp->x + (MMAP_RANGE * 2))
	{
		if (p->x >= 0
			&& ft_is_in_str("0NSEWO", cub->mmap->map[(int)p->y][(int)p->x]))
			draw_square(cub, print->x * MMAP_BLOCK_S,
				print->y * MMAP_BLOCK_S, MMAP_RGB);
		else if (p->x >= 0)
			draw_square(cub, print->x * MMAP_BLOCK_S,
				print->y * MMAP_BLOCK_S, MMAP_W_RGB);
		if (p->x >= 0
			&& ft_is_in_str("OC", cub->mmap->map[(int)p->y][(int)p->x]))
			draw_square(cub, print->x * MMAP_BLOCK_S,
				print->y * MMAP_BLOCK_S, DOOR_RGB);
		p->x++;
		print->x++;
	}
}

void	draw_minimap(t_cub *cub)
{
	t_point	p;
	t_point	print;
	t_point	tmp;

	init_points(cub, &p, &print, &tmp);
	while (p.y <= tmp.y + (MMAP_RANGE * 2) && p.y < cub->mmap->nb_line)
	{
		print.x = 1;
		p.x = tmp.x;
		draw_row(cub, &p, &print, &tmp);
		p.y++;
		print.y++;
	}
	draw_square(cub, (MMAP_RANGE + 1) * MMAP_BLOCK_S,
		(MMAP_RANGE + 1) * MMAP_BLOCK_S, PLAYER_RGB);
}
