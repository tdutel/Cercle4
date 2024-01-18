/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 23:04:28 by llevasse          #+#    #+#             */
/*   Updated: 2024/01/16 00:10:36 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_door(t_cub *cub);

int	press_input(int keysym, t_cub *cub)
{
	if (keysym == XK_Shift_L || keysym == XK_Shift_R)
		cub->shift = 2;
	if (keysym == XK_w || keysym == XK_Up)
		cub->forward = 1;
	if (keysym == XK_d)
		cub->right = 1;
	if (keysym == XK_s || keysym == XK_Down)
		cub->backward = 1;
	if (keysym == XK_a)
		cub->left = 1;
	if (keysym == XK_e)
		check_door(cub);
	if (keysym == XK_Escape)
		return (close_window(cub, 0), 0);
	if (keysym == XK_Left)
		cub->r_left = 1;
	if (keysym == XK_Right)
		cub->r_right = 1;
	return (0);
}

int	release_input(int keysym, t_cub *cub)
{
	if (keysym == XK_Shift_L || keysym == XK_Shift_R)
		cub->shift = 1;
	if (keysym == XK_w || keysym == XK_Up)
		cub->forward = 0;
	if (keysym == XK_d)
		cub->right = 0;
	if (keysym == XK_s || keysym == XK_Down)
		cub->backward = 0;
	if (keysym == XK_a)
		cub->left = 0;
	if (keysym == XK_Left)
		cub->r_left = 0;
	if (keysym == XK_Right)
		cub->r_right = 0;
	return (0);
}

int	move(t_cub *cub)
{
	if (cub->forward)
		check_collision(cub, 0, cub->move_offset * cub->shift);
	if (cub->right)
		check_collision(cub, 90, cub->move_offset * cub->shift);
	if (cub->backward)
		check_collision(cub, 0, -cub->move_offset * cub->shift);
	if (cub->left)
		check_collision(cub, 90, -cub->move_offset * cub->shift);
	if (cub->r_left)
		cub->player.pa -= PLAYER_R_OFFSET * cub->shift;
	if (cub->r_right)
		cub->player.pa += PLAYER_R_OFFSET * cub->shift;
	return (0);
}

void	check_door(t_cub *cub)
{
	if (cub->door && (cub->door->cross_door || cub->door->hit_door))
	{
		if (cub->mmap->map[cub->door->y][cub->door->x] == 'C')
			cub->mmap->map[cub->door->y][cub->door->x] = 'O';
		else if (cub->mmap->map[cub->door->y][cub->door->x] == 'O')
			cub->mmap->map[cub->door->y][cub->door->x] = 'C';
		free_one_addr(&cub->garbage, cub->door);
		cub->door = NULL;
	}
}

int	close_window(t_cub *cub, int status)
{
	if (cub->win_ptr)
		mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
	close_walls(cub);
	if (cub->img.mlx_img)
		mlx_destroy_image(cub->mlx_ptr, cub->img.mlx_img);
	if (cub->mlx_ptr)
		mlx_destroy_display(cub->mlx_ptr);
	if (cub->h)
		free(cub->h);
	if (cub->v)
		free(cub->v);
	free_garbage(cub->garbage);
	exit(status);
}
