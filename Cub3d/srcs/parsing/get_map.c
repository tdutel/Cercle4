/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:01:04 by llevasse          #+#    #+#             */
/*   Updated: 2024/01/15 21:48:23 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*pass_space(char *s)
{
	char	*str;

	str = s;
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	return (str);
}

char	*skip_empty_line(int fd, char *str, t_cub *cub)
{
	while (str && is_line_empty(str))
	{
		str = get_next_line(fd);
		if (str)
			ft_add_garbage(&cub->garbage, str, cub);
	}
	return (str);
}

int	check_textures(t_cub *cub)
{
	if (!cub->north_img.mlx_img)
		return ((void)ft_putstr_fd(N_WALL_MISSING, 2), 0);
	if (!cub->south_img.mlx_img)
		return ((void)ft_putstr_fd(S_WALL_MISSING, 2), 0);
	if (!cub->east_img.mlx_img)
		return ((void)ft_putstr_fd(E_WALL_MISSING, 2), 0);
	if (!cub->west_img.mlx_img)
		return ((void)ft_putstr_fd(W_WALL_MISSING, 2), 0);
	return (1);
}

int	valid_resolution(t_cub *cub)
{
	if (cub->north_img.width != cub->south_img.width)
		return ((void)ft_putstr_fd(UNEQUAL_RESOLUTION, 2), 0);
	if (cub->north_img.width != cub->east_img.width)
		return ((void)ft_putstr_fd(UNEQUAL_RESOLUTION, 2), 0);
	if (cub->west_img.width != cub->south_img.width)
		return ((void)ft_putstr_fd(UNEQUAL_RESOLUTION, 2), 0);
	if (cub->door_img.mlx_img && cub->north_img.width != cub->door_img.width)
		return ((void)ft_putstr_fd(UNEQUAL_RESOLUTION, 2), 0);
	if (cub->f_rgb > 0xffffff)
		return ((void)ft_putstr_fd(F_ERR, 2), 0);
	if (cub->c_rgb > 0xffffff)
		return ((void)ft_putstr_fd(C_ERR, 2), 0);
	return (1);
}

int	get_map(int map_fd, t_cub *cub)
{
	char	*str;
	char	*tmp;

	str = "";
	tmp = get_next_line(map_fd);
	while (tmp)
	{
		ft_add_garbage(&cub->garbage, tmp, cub);
		tmp = skip_empty_line(map_fd, tmp, cub);
		if (!tmp)
			break ;
		if (!is_texture_line(tmp))
		{
			str = ft_strjoin(str, trim_end(tmp));
			ft_add_garbage(&cub->garbage, str, cub);
		}
		else if (!str[0] && !get_wall(tmp, cub))
			return (0);
		tmp = get_next_line(map_fd);
	}
	if (!check_textures(cub) || !valid_resolution(cub)
		|| !search_player_presence(cub, str) || !valid_line(str, cub))
		return (0);
	return (1);
}
