/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:07:27 by levasse           #+#    #+#             */
/*   Updated: 2023/05/25 16:05:40 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/// @brief Print string. 
/// @param *string string to print,
/// @param *sum Pointer to int of char printed.
void	ft_putstr(char *str, int *sum)
{
	int	secure;

	secure = -1;
	if (!str && *sum != -1)
		secure = write(1, "(null)", 6);
	else if (str && *sum != -1)
		secure = write(1, str, ft_strlen(str));
	if (secure == -1)
		*sum = -1;
	else
		*sum += secure;
}

/// @brief Print char. 
/// @param c Char to print,
/// @param *sum Pointer to int of char printed.
void	ft_putchar(char c, int *sum)
{
	int	secure;

	secure = -1;
	if (*sum != -1)
		secure = (write(1, &c, 1));
	if (secure == -1)
		*sum = -1;
	else
		*sum += secure;
}

/// @brief Print number 
/// @param n long long to print,
/// @param abs 1 if print absolute value and 0 if not,
/// @param *sum Pointer to int of char printed.
void	ft_putnbr(long long n, int abs, int *sum)
{
	if (n == -2147483648)
		return (ft_putstr("-2147483648", sum));
	if (n < 0 && (abs == 0 || abs == 2))
	{
		ft_putchar('-', sum);
		ft_putnbr(n * -1, 0, sum);
	}
	else if (n < 0 && abs)
		ft_putnbr(n * -1, 0, sum);
	else
	{
		if (n < 10)
			ft_putchar(n + '0', sum);
		else
		{
			ft_putnbr(n / 10, 0, sum);
			ft_putchar(n % 10 + '0', sum);
		}
	}
}

/// @brief Print int in certain base. 
/// @param n Int to print,
/// @param *base Str containing base,
/// @param *sum Pointer to int of char printed.
void	ft_putnbr_base(int n, const char *base, int *sum)
{
	if (n < 0)
		return (ft_putnbr_base_u((unsigned) n, base, sum));
	if ((size_t)n < ft_strlen(base))
		ft_putchar(base[n], sum);
	else
	{
		ft_putnbr_base(n / ft_strlen(base), base, sum);
		ft_putchar(base[n % ft_strlen(base)], sum);
	}
}

/// @brief Print int in certain base. 
/// @param n Int to print,
/// @param *base Str containing base,
/// @param *sum Pointer to int of char printed.
void	ft_putnbr_base_u(unsigned long long n, const char *base, int *sum)
{
	if ((size_t)n < ft_strlen(base))
		ft_putchar(base[n], sum);
	else
	{
		ft_putnbr_base_u(n / ft_strlen(base), base, sum);
		ft_putchar(base[n % ft_strlen(base)], sum);
	}
}
