/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 02:53:41 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/05/25 03:37:42 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

t_sharp	ft_print_hex_shp(t_flags *arg, unsigned int h, char *prefix)
{
	t_sharp	shp;

	ft_bzero(&shp, sizeof(shp));
	ft_check_arg(arg, h);
	shp.zero = ft_count_zero(arg, ft_baselen(h, 16));
	if (arg->sharp && h != 0)
	{
		arg->zero = false;
		arg->wc = false;
		arg->dot = false;
		arg->max = false;
		arg->min = false;
		if (!arg->minus)
			shp.zero = 0;
		ft_putstr_res(arg, prefix);
	}
	return (shp);
}

void	ft_process_x(va_list ap, t_flags *arg)
{
	unsigned int	h;
	t_sharp			shp;

	h = va_arg(ap, unsigned int);
	shp = ft_print_hex_shp(arg, h, "0x");
	if (arg->minus)
	{
		ft_print_zero(arg, shp.zero);
		if (!(arg->dot && arg->max == 0))
			ft_print_hex(arg, h, HEX_LOWER);
		ft_print_space(arg, shp.zero + ft_baselen(h, 16));
	}
	else
	{
		ft_print_space(arg, shp.zero + ft_baselen(h, 16));
		ft_print_zero(arg, shp.zero);
		if (!(arg->dot && arg->max == 0))
			ft_print_hex(arg, h, HEX_LOWER);
	}
}

void	ft_process_x2(va_list ap, t_flags *arg)
{
	unsigned int	h;
	t_sharp			shp;

	h = va_arg(ap, unsigned int);
	shp = ft_print_hex_shp(arg, h, "0X");
	if (arg->minus)
	{
		ft_print_zero(arg, shp.zero);
		if (!(arg->dot && arg->max == 0))
			ft_print_hex(arg, h, HEX_UPPER);
		ft_print_space(arg, shp.zero + ft_baselen(h, 16));
	}
	else
	{
		ft_print_space(arg, shp.zero + ft_baselen(h, 16));
		ft_print_zero(arg, shp.zero);
		if (!(arg->dot && arg->max == 0))
			ft_print_hex(arg, h, HEX_UPPER);
	}
}

void	ft_process_per(t_flags *arg)
{
	int	zero;

	zero = ft_count_zero(arg, 1);
	if (arg->minus)
	{
		ft_print_zero(arg, zero);
		ft_putchar('%');
		ft_print_space(arg, zero + 1);
	}
	if ((!arg->minus && !arg->min) || (arg->min && !arg->minus))
	{
		ft_print_space(arg, zero + 1);
		ft_print_zero(arg, zero);
		ft_putchar('%');
	}
	arg->res++;
}
/*
void	ft_process_per(t_flags *arg)
{
	t_sharp			shp;

	shp = ft_print_hex_shp(arg, h, "0x");
	if (arg->minus)
	{
		ft_print_zero(arg, shp.zero);
		if (!(arg->dot && arg->max == 0))
			ft_print_hex(arg, h, HEX_LOWER);
		ft_print_space(arg, shp.zero + ft_baselen(h, 16));
	}
	else
	{
		ft_print_space(arg, shp.zero + ft_baselen(h, 16));
		ft_print_zero(arg, shp.zero);
		if (!(arg->dot && arg->max == 0))
			ft_print_hex(arg, h, HEX_LOWER);
	}
}*/
