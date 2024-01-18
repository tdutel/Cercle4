/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 22:02:47 by llevasse          #+#    #+#             */
/*   Updated: 2024/01/15 19:34:28 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	*cub;

	if (argc == 1)
		return ((void)ft_putstr_fd(MISS_F, 2), 1);
	if (ft_strcmp(argv[1] + (ft_strlen(argv[1]) - 4), ".cub"))
		return ((void)ft_putstr_fd(MISS_F, 2), 1);
	if (ft_strlen(argv[1]) < 5)
		return ((void)ft_putstr_fd(MISS_F, 2), 1);
	cub = init_cub(argv);
	mlx_loop_hook(cub->mlx_ptr, &render, cub);
	mlx_hook(cub->win_ptr, KeyPress, KeyPressMask, &press_input, cub);
	mlx_hook(cub->win_ptr, KeyRelease, KeyReleaseMask, &release_input, cub);
	mlx_hook(cub->win_ptr, 17, 0, &close_window, cub);
	mlx_loop(cub->mlx_ptr);
}
