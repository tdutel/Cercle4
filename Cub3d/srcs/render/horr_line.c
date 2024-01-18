/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horr_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:58:31 by llevasse          #+#    #+#             */
/*   Updated: 2024/01/16 00:09:04 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// ray facing up pa > 180 && pa < 360
// ray facing down pa > 0 || pa < 180
//if ray is facing string up or down (pa == 90 || pa == 360 || pa == 0)
t_ray	init_horr(t_cub cub, float pa)
{
	t_ray	r;

	r.tan_v = 1.0 / tan(pa * RADIAN);
	r.width = cub.mmap->block_s;
	r.dof = cub.mmap->dof;
	if (pa > 180 && pa < 360)
	{
		r.line.y_step = r.width;
		r.line.p_a.y = (((int)cub.player.py / r.width) * r.width) - 0.0001;
	}
	else if (pa > 0 && pa < 180)
	{
		r.line.y_step = -r.width;
		r.line.p_a.y = (((int)cub.player.py / r.width) * r.width) + r.width;
	}
	else
	{
		r.line.p_a.x = cub.player.px;
		r.line.p_a.y = cub.player.py;
		r.dof = -42;
	}
	r.line.p_a.x = ((cub.player.py - r.line.p_a.y)
			* -r.tan_v) + cub.player.px;
	r.line.x_step = -r.line.y_step * r.tan_v;
	return (r);
}

static void	get_wall_percent(t_cub *cub, t_line *line, float pa, int dof)
{
	*line = get_line(get_player_point(cub->player.px, cub->player.py),
			line->p_a, cub, pa);
	if (dof <= -42)
		line->dist = 0x7fffffff + 0.0;
	line->wall = &cub->south_img;
	if (pa > 180 && pa < 360)
		line->wall = &cub->north_img;
	line->wall_percent = ((int)line->p_b.x % line->wall->width);
	if (pa > 0 && pa < 180)
		line->wall_percent = ((line->wall->width - 1) - line->wall_percent);
	line->height = WINDOW_H;
	if (line->dist >= 1)
		line->height = ((cub->mmap->block_s * WINDOW_H) / line->dist);
	line->start = (WINDOW_H - line->height) / 2;
	line->stop = (WINDOW_H + line->height) / 2;
}

static void	get_door_percent(t_cub *cub, t_line *line, float pa, t_door *door)
{
	line->wall = &cub->door_img;
	line->wall_percent = ((int)line->p_b.x % line->wall->width);
	if (pa > 0 && pa < 180)
		line->wall_percent = ((line->wall->width - 1) - line->wall_percent);
	line->height = WINDOW_H;
	if (line->dist >= 1)
		line->height = ((cub->mmap->block_s * WINDOW_H) / line->dist);
	line->start = (WINDOW_H - line->height) / 2;
	line->stop = (WINDOW_H + line->height) / 2;
	if (!door->cross_door)
		*door = cross_door(*cub, line->p_b.x, line->p_b.y, 1);
}

void	progress_horr_line(t_cub *cub, t_ray *r)
{
	while (r->dof-- > 0)
	{
		r->p.x = (int)(r->line.p_a.x / cub->mmap->block_s);
		r->p.y = (int)(r->line.p_a.y / cub->mmap->block_s);
		if (!is_pos_valid(*cub, (int)r->p.x, (int)r->p.y)
			|| !ft_is_in_str("NSEW0O",
				cub->mmap->map[(int)r->p.y][(int)r->p.x]))
			break ;
		if (cub->mmap->map[(int)r->p.y][(int)r->p.x] == 'O' && !r->d.cross_door)
			r->d = cross_door(*cub, r->line.p_a.x, r->line.p_a.y, 0);
		r->line.p_a.x += r->line.x_step;
		r->line.p_a.y -= r->line.y_step;
	}
}

t_ray	*get_horr(t_cub *cub, float pa)
{
	t_ray	*r;

	r = malloc(sizeof(t_ray));
	cub->h = r;
	if (!r)
		close_window(cub, 12);
	*r = init_horr(*cub, pa);
	r->d = init_door();
	progress_horr_line(cub, r);
	get_wall_percent(cub, &r->line, pa, r->dof);
	if (is_pos_valid(*cub, (int)r->p.x, (int)r->p.y)
		&& cub->mmap->map[(int)r->p.y][(int)r->p.x] == 'C')
		get_door_percent(cub, &r->line, pa, &r->d);
	r->line.door = r->d;
	return (r);
}
