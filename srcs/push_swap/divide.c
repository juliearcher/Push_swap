/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   divide.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/12 07:23:51 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/12 07:23:52 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

static int	swapped_a(t_push *str, t_elem *elem, int mode, int reverse)
{
	t_elem	tmp;

	swap_a(str);
	if (elem->index < 2)
		elem->index = (elem->index + 1) % 2;
	tmp = get_smallest_index(str, elem, mode);
	swap_a(str);
	if (tmp.index != elem->index)
	{
		if (add_instruction(str, "sa", &swap_a) == -1)
			return (-1);
		*elem = tmp;
		reverse = do_reverse(str);
		return (1);
	}
	else if (elem->index < 2)
		elem->index = (elem->index + 1) % 2;
	return (0);
}

static int	rotate_list(t_push *str, t_elem *elem, int reverse)
{
	if (add_instruction(str, reverse ? "rra" : "ra",
		reverse ? &reverse_rotate_a : &rotate_a) == -1)
		return (-1);
	if (reverse)
		elem->index = elem->index == str->sizea - 1 ? 0 : ++(elem->index);
	else
		elem->index = elem->index == 0 ? str->sizea - 1 : --(elem->index);
	return (0);
}

static int	push_to_b(t_push *str, t_elem *elem, int mode, int reverse)
{
	int	res;

	while (elem->value > 0)
		if ((res = swapped_a(str, elem, mode, reverse)) != 0)
		{
			if (res == -1)
				return (-1);
			reverse = do_reverse(str);
		}
		else if (str->lista[0].push)
		{
			if (add_instruction(str, "pb", &push_b) == -1)
				return (-1);
			--(elem->value);
			--(elem->index);
		}
		else if (rotate_list(str, elem, reverse) == -1)
			return (-1);
	return (0);
}

int			divide_list(t_push *str, int mode)
{
	t_elem	smallest;

	smallest = get_smallest_index(str, NULL, mode);
	return (push_to_b(str, &smallest, mode, do_reverse(str)));
}
