/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 22:29:27 by llevasse          #+#    #+#             */
/*   Updated: 2024/01/16 00:10:57 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_cub	*init_cub(char **argv)
{
	t_cub	*cub;

	cub = malloc(sizeof(struct s_cub));
	if (!cub)
		exit(1);
	init_null(cub);
	cub->mlx_ptr = mlx_init();
	if (!cub->mlx_ptr)
		return (ft_putstr_fd(MLX_ERR, 2), close_window(cub, 1), NULL);
	ft_add_garbage(&cub->garbage, cub->mlx_ptr, cub);
	cub->mmap = malloc(sizeof(struct s_minimap));
	ft_add_garbage(&cub->garbage, cub->mmap, cub);
	if (!parse(argv[1], cub))
		close_window(cub, 1);
	init_minimap(cub);
	init_player(cub);
	cub->win_ptr = mlx_new_window(cub->mlx_ptr, WINDOW_W, WINDOW_H, "cub3D");
	if (!cub->win_ptr)
		close_window(cub, 1);
	init_images(cub);
	cub->move_offset = 0.2 * cub->mmap->block_s;
	return (cub);
}

void	init_null(t_cub *cub)
{
	cub->garbage = 0x0;
	ft_add_garbage(&cub->garbage, cub, cub);
	cub->win_ptr = NULL;
	cub->mlx_ptr = NULL;
	cub->img.mlx_img = NULL;
	cub->forward = 0;
	cub->backward = 0;
	cub->left = 0;
	cub->right = 0;
	cub->r_left = 0;
	cub->r_right = 0;
	cub->shift = 1;
	cub->h = NULL;
	cub->v = NULL;
	cub->north_img.mlx_img = NULL;
	cub->south_img.mlx_img = NULL;
	cub->east_img.mlx_img = NULL;
	cub->west_img.mlx_img = NULL;
	cub->door_img.mlx_img = NULL;
}

void	init_images(t_cub *cub)
{
	cub->img.mlx_img = mlx_new_image(cub->mlx_ptr, WINDOW_W, WINDOW_H);
	if (!cub->img.mlx_img)
		close_window(cub, 1);
	cub->img.width = WINDOW_W;
	cub->img.height = WINDOW_H;
	cub->img.addr = mlx_get_data_addr(cub->img.mlx_img,
			&cub->img.bpp, &cub->img.line_len, &cub->img.endian);
}

void	init_minimap(t_cub *cub)
{
	int	i;

	cub->mmap->nb_line = get_tab_len(cub->mmap->map);
	init_map_value(cub);
	i = 0;
	cub->mmap->map_width = 0;
	while (i < cub->mmap->nb_line)
	{
		if (cub->mmap->mapx[i++] > cub->mmap->map_width)
			cub->mmap->map_width = cub->mmap->mapx[i - 1];
	}
	cub->mmap->dof = cub->mmap->map_width;
	if (cub->mmap->map_width < cub->mmap->nb_line)
		cub->mmap->dof = cub->mmap->nb_line;
	cub->mmap->block_s = cub->north_img.width;
}

void	init_map_value(t_cub *cub)
{
	int	i;

	i = 0;
	cub->mmap->mapx = malloc(sizeof(int) * (cub->mmap->nb_line));
	ft_add_garbage(&cub->garbage, cub->mmap->mapx, cub);
	cub->mmap->maps = 0;
	while (i < cub->mmap->nb_line)
	{
		cub->mmap->mapx[i] = ft_strlen(cub->mmap->map[i]) - 1;
		cub->mmap->maps += cub->mmap->mapx[i++];
	}
}
