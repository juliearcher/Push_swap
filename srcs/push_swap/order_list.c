/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   order_list.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/12 06:48:59 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/12 06:49:00 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

int		order_list(t_push *str)
{
	void	(*f)(t_push *);
	char	*ins;
	int		index;

	index = 0;
	while (index < str->sizea && str->lista[index].index != 0)
		++index;
	ins = index <= str->sizelist / 2 ? "ra" : "rra";
	f = index <= str->sizelist / 2 ? &rotate_a : &reverse_rotate_a;
	while (str->lista[0].index != 0)
	{
		if (add_instruction(str, ins, f) == -1)
			return (-1);
	}
	return (1);
}
