/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 06:58:58 by llevasse          #+#    #+#             */
/*   Updated: 2023/07/02 20:30:50 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Check if char is a space (commun separation between words).
/// @param c Char to check.
/// @return Return 1 if char is a space.
int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || \
			c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

/// @brief Parse *str as an integer.
/// @param *str *Str to pass as integer.
/// @return Return *str integer value if one is present in *str, 0 if none.
int	ft_atoi(const char *str)
{
	size_t	i;
	int		res;
	int		is_neg;

	is_neg = 1;
	i = 0;
	if (!str)
		return (0);
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-')
		is_neg *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] >= '0' && str[i] <= '9')
		res = str[i] - '0';
	else
		return (0);
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
			res = res * 10 + str[i + 1] - '0';
		i++;
	}
	return (res * is_neg);
}
