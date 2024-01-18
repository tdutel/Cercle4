/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:05:00 by llevasse          #+#    #+#             */
/*   Updated: 2024/01/15 23:22:18 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

//srcs/render/render.c:
int		render(t_cub *cub);
void	img_pix_put(t_img *img, int x, int y, int colour);
void	paint_bg(t_cub *cub);

//srcs/render/line.c:
t_line	get_line(t_point p_a, t_point p_b, t_cub *cub, float pa);
t_point	get_player_point(float x, float y);

//srcs/render/horr_line.c
t_ray	init_horr(t_cub cub, float pa);
t_ray	*get_horr(t_cub *cub, float pa);

//srcs/render/vert_line.c
t_ray	init_vert(t_cub cub, float pa);
t_ray	*get_vert(t_cub *cub, float pa);

//srcs/render/minimap.c:
void	draw_square(t_cub *cub, int x, int y, int colour);
void	draw_player(t_cub *cub, int x, int y, int colour);
void	draw_minimap(t_cub *cub);

//srcs/render/draw_fov.c:
void	draw_fov(t_cub *cub);

//srcs/render/casting.c
t_cast	get_cast_data(t_cub *cub, float ca, int check_door);
t_door	*cast(t_cub *cub, t_cast c, int x);
int		is_pos_valid(t_cub cub, int x, int y);

//srcs/render/door.c
t_door	cross_door(t_cub cub, float r_x, float r_y, int hit_door);
t_door	init_door(void);

#endif
