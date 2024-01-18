/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 23:42:30 by llevasse          #+#    #+#             */
/*   Updated: 2024/01/15 18:09:48 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_H
# define ERR_H

# include "cub3d.h"

# define MLX_ERR "Error\nError in mlx_init().\n"
# define MEM_ERR "Error\nError while allocating memory.\n"
# define N_WALL_OPEN_ERR "Error\nError in opening north wall texture file.\n"
# define S_WALL_OPEN_ERR "Error\nError in opening south wall texture file.\n"
# define E_WALL_OPEN_ERR "Error\nError in opening east wall texture file.\n"
# define W_WALL_OPEN_ERR "Error\nError in opening west wall texture file.\n"
# define DOOR_OPEN_ERR "Error\nError in opening door texture file.\n"
# define N_WALL_MISSING "Error\nNorth wall texture file is missing.\n"
# define S_WALL_MISSING "Error\nSouth wall texture file is missing.\n"
# define E_WALL_MISSING "Error\nEast wall texture file is missing.\n"
# define W_WALL_MISSING "Error\nWest wall texture file is missing.\n"
# define F_ERR "Error\nInvalid floor colour.\n"
# define C_ERR "Error\nInvalid ceiling colour.\n"
# define CUB_OPEN_ERR "Error\nError in opening cub file.\n"
# define MISS_F "Error\n.cub file is missing.\n"
# define INVALID_CUB "Error\n.cub file is invalid.\n"
# define OPEN_MAP "Error\nThe map is not closed.\n"
# define TMP "Error\nToo many player in the map file.\n"
# define NO_PLAYER "Error\nThere is no player in the map file.\n"
# define ISLAND_MAP "Error\nThere is an unreachable section in the map file.\n"
# define INVALID_MAP_LINE "Error\nThere is an invalid character in a map.\n"
# define UNEQUAL_RESOLUTION "Error\nThe wall's textures \
resolution are not equal.\n"

#endif
