/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:22:53 by llevasse          #+#    #+#             */
/*   Updated: 2024/01/07 21:51:23 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//srcs/input/input.c:
int			press_input(int keysym, t_cub *cub);
int			release_input(int keysym, t_cub *cub);
int			move(t_cub *cub);
int			close_window(t_cub *cub, int status);
int			rotate_input(int keysym, t_cub *cub);

//srcs/input/set_player_pos.c:
float		no_higher(float nb, float highest, float lowest);
void		check_collision(t_cub *cub, int angle, float offset);
void		get_player_new_pos(t_cub *cub, int angle, float dist, t_point *p);
