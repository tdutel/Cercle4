/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:37:45 by llevasse          #+#    #+#             */
/*   Updated: 2024/01/06 17:41:53 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_cub *cub)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (i < cub->mmap->nb_line)
	{
		j = 0;
		len = ft_strlen(cub->mmap->map[i]);
		while (j < len)
		{
			if (ft_is_in_str("NSEW", cub->mmap->map[i][j++]))
			{
				cub->player.pa = get_player_start_orientation(
						cub->mmap->map[i][j - 1]);
				cub->player.px = ((j - 1) * cub->mmap->block_s);
				cub->player.py = (i * cub->mmap->block_s);
			}
		}
		i++;
	}
	cub->player.px += cub->mmap->block_s / 2;
	cub->player.py += cub->mmap->block_s / 2;
	cub->field_step = ((float)(PLAYER_FOV - 1) / WINDOW_W);
}

int	get_player_start_orientation(char c)
{
	if (c == 'E')
		return (0);
	if (c == 'S')
		return (90);
	if (c == 'W')
		return (180);
	if (c == 'N')
		return (270);
	return (0);
}
