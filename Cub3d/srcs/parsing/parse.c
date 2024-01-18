/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:50:20 by llevasse          #+#    #+#             */
/*   Updated: 2024/01/15 22:02:18 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse(char *path, t_cub *cub)
{
	int	map_fd;

	map_fd = open(path, O_RDONLY | O_DIRECTORY);
	cub->f_rgb = 0x7fffffff;
	cub->c_rgb = 0x7fffffff;
	cub->player_rotation = -1;
	if (map_fd != -1)
	{
		close(map_fd);
		return ((void)ft_putstr_fd(CUB_OPEN_ERR, 2), 0);
	}
	map_fd = open(path, O_RDONLY);
	if (map_fd == -1)
		return ((void)ft_putstr_fd(CUB_OPEN_ERR, 2), 0);
	if (!get_map(map_fd, cub))
		return (close(map_fd));
	return (!close(map_fd));
}

int	is_line_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	close_walls(t_cub *cub)
{
	if (cub->north_img.mlx_img)
		mlx_destroy_image(cub->mlx_ptr, cub->north_img.mlx_img);
	if (cub->south_img.mlx_img)
		mlx_destroy_image(cub->mlx_ptr, cub->south_img.mlx_img);
	if (cub->east_img.mlx_img)
		mlx_destroy_image(cub->mlx_ptr, cub->east_img.mlx_img);
	if (cub->west_img.mlx_img)
		mlx_destroy_image(cub->mlx_ptr, cub->west_img.mlx_img);
	if (cub->door_img.mlx_img)
		mlx_destroy_image(cub->mlx_ptr, cub->door_img.mlx_img);
}
