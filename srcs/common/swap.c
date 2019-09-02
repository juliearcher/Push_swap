/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   swap.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/05 07:14:26 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/05 07:14:27 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "common.h"

void	swap_a(t_push *str)
{
	t_elem	temp;

	if (str->sizea < 2)
		return ;
	temp = str->lista[0];
	str->lista[0] = str->lista[1];
	str->lista[1] = temp;
}

void	swap_b(t_push *str)
{
	t_elem	temp;

	if (str->sizeb < 2)
		return ;
	temp = str->listb[0];
	str->listb[0] = str->listb[1];
	str->listb[1] = temp;
}

void	swap_ab(t_push *str)
{
	swap_a(str);
	swap_b(str);
}
