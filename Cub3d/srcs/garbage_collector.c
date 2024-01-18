/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:05:40 by llevasse          #+#    #+#             */
/*   Updated: 2024/01/05 23:15:04 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_garbage(t_garbage	*garbage)
{
	if (garbage)
	{
		free_garbage(garbage->next);
		garbage->next = NULL;
		if (garbage->addr)
		{
			free(garbage->addr);
			garbage->addr = NULL;
		}
		free(garbage);
		garbage = NULL;
	}
}

t_garbage	*ft_new_garbage(void *address)
{
	t_garbage	*new;

	new = malloc(sizeof(struct s_garbage));
	if (!new)
	{
		free(address);
		return (NULL);
	}
	new->addr = address;
	new->next = NULL;
	return (new);
}

void	malloc_failed(t_cub *cub)
{
	if (cub)
		close_window(cub, 12);
	exit(12);
}

void	free_one_addr(t_garbage **lst, void *addr)
{
	t_garbage	*tmp;
	t_garbage	*remove;

	tmp = *lst;
	if (!addr)
		return ;
	while (tmp)
	{
		if (tmp->next->addr == addr)
		{
			remove = tmp->next;
			tmp->next = tmp->next->next;
			free(addr);
			free(remove);
			return ;
		}
		tmp = tmp->next;
	}
}

void	ft_add_garbage(t_garbage **lst, void *addr, t_cub *cub)
{
	t_garbage	*temp;
	t_garbage	*new;

	if (!addr)
		malloc_failed(cub);
	new = ft_new_garbage(addr);
	if (!new)
		malloc_failed(cub);
	if (*lst)
	{
		temp = *lst;
		while (temp->next != NULL)
		{
			if (temp->addr == addr)
				return (free(new));
			temp = temp->next;
		}
		if (temp->addr == addr)
			return (free(new));
		temp->next = new;
		return ;
	}
	*lst = new;
}
