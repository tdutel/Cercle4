/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:24:13 by llevasse          #+#    #+#             */
/*   Updated: 2023/09/18 23:13:56 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief return pointer to first word(token) in **p_str 
/// and update *p_str to past token.
/// @param **p_str Pointer to pointer of chars (Pointer to str), 
/// to get token from.
/// @param *delim Const str containing every delimiting character.
/// @return Return pointer to first token.
char	*ft_strsep(char **p_str, const char *delim)
{
	int	i;

	if (!*p_str)
		return (NULL);
	if (!delim)
		return (*p_str);
	i = 0;
	while ((*p_str)[i] && !ft_is_in_str(delim, (*p_str)[i]))
		i++;
	while ((*p_str)[i] && ft_is_in_str(delim, (*p_str)[i]))
		(*p_str)[i++] = '\0';
	*p_str += i;
	return (*p_str - i);
}
