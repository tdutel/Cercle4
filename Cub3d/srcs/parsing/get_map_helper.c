/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:18:35 by llevasse          #+#    #+#             */
/*   Updated: 2024/01/15 21:33:53 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valid_line(char *str, t_cub *cub)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!cub->door_img.mlx_img && !ft_is_in_str("NSEW01\n \r", str[i]))
			return ((ft_putstr_fd(INVALID_MAP_LINE, 2)), 0);
		else if (cub->door_img.mlx_img
			&& !ft_is_in_str("NSEW01CO\n \r", str[i]))
			return ((ft_putstr_fd(INVALID_MAP_LINE, 2)), 0);
		i++;
	}
	return (1);
}

char	*trim_end(char *str)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] != '\t' && str[i] != ' ' && str[i])
			break ;
		str[i] = 0;
		i--;
	}
	return (str);
}

int	is_texture_line(char *str)
{
	char	*id;

	id = pass_space(str);
	if (!ft_strncmp("NO", id, 2))
		return (1);
	if (!ft_strncmp("SO", id, 2))
		return (1);
	if (!ft_strncmp("WE", id, 2))
		return (1);
	if (!ft_strncmp("EA", id, 2))
		return (1);
	if (!ft_strncmp("DOOR", id, 4))
		return (1);
	if (!ft_strncmp("F", id, 1))
		return (1);
	if (!ft_strncmp("C", id, 1))
		return (1);
	return (0);
}

int	check_player_in_string(t_point *p, int y, int x, char *str)
{
	if (ft_is_in_str("NSEW", str[x]))
	{
		p->x = x;
		p->y = y;
		return (1);
	}
	return (0);
}

int	search_player_presence(t_cub *cub, char *s)
{
	t_point	p;
	int		y;
	int		x;
	int		nb;
	char	**split;

	split = ft_split(s, '\n');
	ft_add_garbage(&cub->garbage, split, cub);
	y = 0;
	nb = 0;
	while (y < get_tab_len(split))
	{
		ft_add_garbage(&cub->garbage, split[y], cub);
		x = 0;
		while (split[y][x])
			nb += check_player_in_string(&p, y, x++, split[y]);
		y++;
	}
	if (nb > 1)
		return ((ft_putstr_fd(TMP, 2)), 0);
	if (nb == 0)
		return ((ft_putstr_fd(NO_PLAYER, 2)), 0);
	cub->mmap->map = split;
	return (check_closed(cub, p.x, p.y));
}
