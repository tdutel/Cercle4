/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:05:18 by llevasse          #+#    #+#             */
/*   Updated: 2023/12/23 22:55:31 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_door	cross_door(t_cub cub, float r_x, float r_y, int hit_door)
{
	t_door	door;
	float	d_x;
	float	d_y;

	door.cross_door = 1;
	door.hit_door = 0;
	if (hit_door)
		door.hit_door = 1;
	door.x = r_x / cub.mmap->block_s;
	door.y = r_y / cub.mmap->block_s;
	door.r_x = r_x;
	door.r_y = r_y;
	d_x = r_x - cub.player.px;
	d_y = r_y - cub.player.py;
	door.dist = sqrt(pow(d_y, 2) + pow(d_x, 2));
	return (door);
}

t_door	init_door(void)
{
	t_door	door;

	door.cross_door = 0;
	door.hit_door = 0;
	door.dist = 0;
	return (door);
}
