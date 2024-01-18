/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 23:48:52 by llevasse          #+#    #+#             */
/*   Updated: 2024/01/14 18:06:55 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	in_range(int nb, int min, int max)
{
	return (nb >= min && nb <= max);
}

static int	get_rgb_value(char *s, int *value, char *err)
{
	int		r;
	int		g;
	int		b;
	char	*tmp;

	tmp = ft_strsep(&s, ", \t");
	if (!ft_isdigit(*tmp) || !in_range(ft_atoi(tmp), 0, 255))
		return ((void)ft_putstr_fd(err, 2), 0);
	r = ft_atoi(tmp);
	tmp = ft_strsep(&s, ", \t");
	if (!ft_isdigit(*tmp) || !in_range(ft_atoi(tmp), 0, 255))
		return ((void)ft_putstr_fd(err, 2), 0);
	g = ft_atoi(tmp);
	tmp = ft_strsep(&s, ", \t");
	if (!ft_isdigit(*tmp) || !in_range(ft_atoi(tmp), 0, 255))
		return ((void)ft_putstr_fd(err, 2), 0);
	b = ft_atoi(tmp);
	*value = (r * 256 * 256) + (g * 256) + b;
	return (1);
}

int	do_open(char *s, t_img *img, int face, t_cub *cub)
{
	int	w;
	int	h;

	while (*s && ft_isspace(*s))
		s++;
	img->mlx_img = mlx_xpm_file_to_image(cub->mlx_ptr,
			ft_strsep(&s, "\n\r\t "), &w, &h);
	if (img->mlx_img == NULL && face == 0)
		return ((void)ft_putstr_fd(N_WALL_OPEN_ERR, 2), 0);
	if (img->mlx_img == NULL && face == 1)
		return ((void)ft_putstr_fd(S_WALL_OPEN_ERR, 2), 0);
	if (img->mlx_img == NULL && face == 2)
		return ((void)ft_putstr_fd(W_WALL_OPEN_ERR, 2), 0);
	if (img->mlx_img == NULL && face == 3)
		return ((void)ft_putstr_fd(E_WALL_OPEN_ERR, 2), 0);
	if (img->mlx_img == NULL && face == 4)
		return ((void)ft_putstr_fd(DOOR_OPEN_ERR, 2), 0);
	img->width = w;
	img->height = h;
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp,
			&img->line_len, &img->endian);
	return (1);
}

int	get_wall(char *str, t_cub *cub)
{
	char	*id;

	str = pass_space(str);
	id = ft_strsep(&str, " \t");
	if (!ft_strcmp("NO", id) && cub->north_img.mlx_img == 0)
		return (do_open(str, &cub->north_img, 0, cub));
	if (!ft_strcmp("SO", id) && cub->south_img.mlx_img == 0)
		return (do_open(str, &cub->south_img, 1, cub));
	if (!ft_strcmp("WE", id) && cub->west_img.mlx_img == 0)
		return (do_open(str, &cub->west_img, 2, cub));
	if (!ft_strcmp("EA", id) && cub->east_img.mlx_img == 0)
		return (do_open(str, &cub->east_img, 3, cub));
	if (!ft_strcmp("F", id) && cub->f_rgb == 0x7fffffff)
		return (get_rgb_value(str, &cub->f_rgb, F_ERR));
	if (!ft_strcmp("C", id) && cub->c_rgb == 0x7fffffff)
		return (get_rgb_value(str, &cub->c_rgb, C_ERR));
	if (!ft_strcmp("DOOR", id) && cub->door_img.mlx_img == 0)
		return (do_open(str, &cub->door_img, 4, cub));
	return ((void)ft_putstr_fd(INVALID_CUB, 2), 0);
}
