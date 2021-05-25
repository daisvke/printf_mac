/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 19:42:22 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/05/25 04:44:01 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_putstr_res(t_flags *arg, char *str)
{
	if (str)
	{
		while (*str)
		{
			write(1, &*str++, 1);
			arg->res++;
		}
	}
}

void	ft_putnstr(t_flags *arg, char *s, int n)
{
	while (*s && n--)
	{
		ft_putchar(*s++);
		arg->res++;
	}
}

void	ft_putnchar(t_flags *arg, int c, size_t n)
{
	arg->res += n;
	while (n--)
		ft_putchar(c);
}

void	ft_putchar_res(t_flags *arg, char c)
{
	ft_putchar(c);
	arg->res++;
}

void	ft_print_plus(t_flags *arg)
{
	if (arg->plus)
		ft_putnchar(arg, '+', 1);
}
