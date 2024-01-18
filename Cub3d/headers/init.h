/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:13:25 by llevasse          #+#    #+#             */
/*   Updated: 2024/01/07 21:58:08 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//srcs/init/init_player.c:
void	init_player(t_cub *cub);
int		get_player_start_orientation(char c);

//srcs/init/init.c:
t_cub	*init_cub(char **argv);
void	init_null(t_cub *cub);
void	init_minimap(t_cub *cub);
void	init_images(t_cub *cub);
void	init_map_value(t_cub *cub);
