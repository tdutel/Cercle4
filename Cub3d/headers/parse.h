/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:13:25 by llevasse          #+#    #+#             */
/*   Updated: 2024/01/15 21:50:54 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//srcs/parsing/get_map.c
int		get_map(int map_fd, t_cub *cub);
int		search_player_presence(t_cub *cub, char *s);
char	*pass_space(char *s);

//srcs/parsing/get_map_helper.c
int		valid_line(char *str, t_cub *cub);
char	*trim_end(char *str);
int		search_door(t_cub *cub, char *s);
int		is_texture_line(char *str);

//srcs/parsing/get_wall.c
int		get_wall(char *str, t_cub *cub);
int		do_open(char *s, t_img *img, int face, t_cub *cub);

//srcs/parsing/is_map_closed.c
int		check_closed(t_cub *cub, int x, int y);
int		fload(t_cub *cub, int x, int y);
int		get_tab_len(char **tab);

//srcs/parsing/parce.c
int		parse(char *path, t_cub *cub);
void	close_walls(t_cub *cub);
int		is_line_empty(char *str);
void	get_side_data_addrs(t_cub *cub);
