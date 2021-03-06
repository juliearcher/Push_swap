/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_precision.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 11:47:03 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 11:47:12 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_precision(t_printf *str, int length)
{
	int	i;

	i = 0;
	while (i < str->precision - length)
	{
		ft_putchar_printf('0', str);
		++i;
	}
	return (i);
}

int		print_width(t_printf *str, int length)
{
	int	i;

	i = 0;
	while (i + length < str->min_width)
	{
		ft_putchar_printf(str->flags_tab[ZERO]
			&& !str->flags_tab[MINUS] ? '0' : ' ', str);
		++i;
	}
	return (i);
}
