/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:33:53 by llevasse          #+#    #+#             */
/*   Updated: 2023/05/25 16:05:52 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/// @brief Print string with options and variable. 
/// @param *string string to print,
/// @param Any variable to print.
/// @return Return number of char printed and -1 if error occured.
int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;

	if (!string)
		return (-1);
	va_start(args, string);
	i = 0;
	while (*string && i != -1)
	{
		while (*string != '%' && *string)
			ft_putchar(*string++, &i);
		if (*string == '%')
		{
			string++;
			if (*string)
				print_var_bonus(string, args, &i);
			else
				i = -1;
			while (is_specifier(*string, 1) && *string)
				string++;
		}
		if (*string)
			string++;
	}
	return (va_end(args), i);
}

/// @brief Print basic variables. 
/// @param *string string to print,
/// @param args Va_list passed to ft_printf,
/// @param *sum Pointer to int of char printed.
void	print_var(const char *str, va_list args, int *sum)
{
	unsigned long long	address;

	if (*str == '%')
		return (ft_putchar('%', sum));
	else if (*str == 'c')
		return (ft_putchar(va_arg(args, int), sum));
	else if (*str == 's')
		return (ft_putstr(va_arg(args, char *), sum));
	else if (*str == 'd' || *str == 'i')
		return (ft_putnbr(va_arg(args, int), is_neg(str, args), sum));
	else if (*str == 'u')
		return (ft_putnbr(va_arg(args, unsigned int), 0, sum));
	else if (*str == 'x')
		return (ft_putnbr_base(va_arg(args, int), "0123456789abcdef", sum));
	else if (*str == 'X')
		return (ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF", sum));
	else if (*str == 'p')
	{
		address = va_arg(args, unsigned long long);
		if (!address)
			return (ft_putstr("(nil)", sum));
		ft_putstr("0x", sum);
		return (ft_putnbr_base_u(address, "0123456789abcdef", sum));
	}
	return ((void)(ft_putchar('%', sum), ft_putchar(*str, sum)));
}

/// @brief Print variable's specifiers. 
/// @param *string string to print,
/// @param args Va_list passed to ft_printf,
/// @param *sum Pointer to int of char printed.
void	print_var_bonus(const char *str, va_list args, int *sum)
{
	if (check_priorities(str, args, sum))
		return ;
	if (*str == ' ')
		return (print_space(str, args, sum));
	if (*str == '#')
		return (print_pound(str, args, sum));
	if (*str == '-')
		return (print_minus((str + 1), args, sum));
	if (*str == '0')
		return (print_padding((str + 1), args, *str, sum));
	if (ft_isdigit(*str) || *str == '*')
		return (print_field_width(str, args, sum));
	if (*str == '.')
		return (print_prec((str + 1), args, sum));
	if (*str == '+')
		return (print_plus(str, args, sum));
	print_var(str, args, sum);
}

/// @brief Check if char c is a printf specifier.
/// @param c Char to check.
/// @param bonus 0 if checking for only "%csdiuxXp";
/// 1 if checking for only "#-0. +123456789";
/// 2 to check for both "%csdiuxXp" && "#-0. +123456789".
/// @return Return 1 if is specifier and 0 if not.
int	is_specifier(char c, int bonus)
{
	if (!bonus && ft_is_in_str("%%csdiuxXp", c))
		return (1);
	if (bonus == 1 && ft_is_in_str("#-0. +123456789", c))
		return (1);
	if (bonus == 2 && (is_specifier(c, 0) || is_specifier(c, 1)))
		return (1);
	return (0);
}
