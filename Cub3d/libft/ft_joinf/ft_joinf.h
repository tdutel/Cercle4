/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:39:11 by llevasse          #+#    #+#             */
/*   Updated: 2023/07/26 18:09:58 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_JOINF_H
# define FT_JOINF_H

# include <stdarg.h>
# include "../libft.h"

char	*ft_joinf(char *string, ...);
int		pass_specifier(char specifier, va_list args, char **str, int i);
int		predict_full_str_len(char *str, va_list args);

int		predict_len(const char *str, va_list args);
int		get_size_base_u(unsigned long long n, const char *base);
int		get_size_base(int n, const char *base);
int		get_int_len(int n);
int		get_unsigned_len(unsigned int n);

void	skip_to_spec(const char **str);

#endif
