/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   long_sort.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/12 07:21:55 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/12 07:21:56 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_index_of_pos(t_push *str, int elemvalue, int elemindex)
{
	int	i;

	i = 0;
	while (i < str->sizea - 1 && (str->lista[i].value > elemvalue ||
			str->lista[i + 1].value < elemvalue))
	{
		if ((str->lista[i].value > str->lista[i + 1].value &&
			elemvalue > str->lista[i].value) ||
			(str->lista[i].value > str->lista[i + 1].value &&
			elemvalue < str->lista[i + 1].value))
			break ;
		if (str->lista[i].value > elemvalue &&
			str->lista[i + 1].value < elemvalue)
			;
		else if ((str->lista[i].value > elemvalue &&
			elemindex == 0 && str->lista[i].index == str->sizelist - 1) ||
			(str->lista[i + 1].value < elemvalue &&
			elemindex == str->sizelist - 1 && str->lista[i + 1].index == 0))
			break ;
		++i;
	}
	return (i == str->sizea - 1 ? 0 : i + 1);
}

static int	get_nb_of_ins(t_push *str, t_elem *elem, int pos, int retreverse)
{
	int	nbreverse;
	int	nbnormal;
	int	nb;
	int	i;

	nb = pos > str->sizeb / 2 ? str->sizeb - pos : pos;
	i = get_index_of_pos(str, elem->value, elem->index);
	nb += i <= str->sizea / 2 ? i : str->sizea - i;
	nbnormal = str->sizeb - pos;
	if (str->sizea - i > nbnormal)
		nbnormal = str->sizea - i;
	nbreverse = pos;
	if (i > nbreverse)
		nbreverse = i;
	if (nbreverse < nb && nbreverse < nbnormal)
		return (retreverse ? 0 : nbreverse);
	else if (nbnormal < nbreverse && nbnormal < nb)
		return (retreverse ? 1 : nbnormal);
	return (retreverse ? 2 : nb);
}

static int	rotate_lists(t_push *str, int *reverse, int valuea)
{
	int	need_both;

	need_both = reverse[1] != 2 && str->lista[0].value != valuea;
	if (need_both && add_instruction(str, reverse[0] ? "rrr" : "rr",
		reverse[0] ? &reverse_rotate_ab : &rotate_ab) == -1)
		return (-1);
	else if (!need_both && add_instruction(str, reverse[0] ? "rrb" : "rb",
		reverse[0] ? &reverse_rotate_b : &rotate_b) == -1)
		return (-1);
	return (0);
}

static int	push_to_a(t_push *str, int value, int index, int pos)
{
	int	reverse[2];
	int	indexa;
	int	valuea;

	reverse[1] = get_nb_of_ins(str, &str->listb[pos], pos, 1);
	reverse[0] = reverse[1];
	if (reverse[1] == 2)
		reverse[0] = pos > str->sizeb / 2;
	indexa = get_index_of_pos(str, value, index);
	valuea = str->lista[indexa].value;
	while (str->listb[0].value != value)
	{
		if (rotate_lists(str, reverse, valuea) == -1)
			return (-1);
	}
	if (reverse[1] == 2)
		reverse[0] = indexa > str->sizea / 2;
	while (str->lista[0].value != valuea)
		if (add_instruction(str, reverse[0] ? "rra" : "ra",
			reverse[0] ? &reverse_rotate_a : &rotate_a) == -1)
			return (-1);
	return (add_instruction(str, "pa", &push_a));
}

int			long_sort(t_push *str, int mode)
{
	t_elem	smallest;
	int		res;
	int		i;

	if (divide_list(str, mode) == -1)
		return (-1);
	smallest.value = -1;
	while (str->sizeb != 0)
	{
		i = -1;
		while (++i < str->sizeb)
			if ((res = get_nb_of_ins(str, &str->listb[i], i, 0))
				< smallest.value || smallest.value == -1)
			{
				smallest.value = res;
				smallest.index = i;
			}
		if (push_to_a(str, str->listb[smallest.index].value,
			str->listb[smallest.index].index, smallest.index) == -1)
			return (-1);
		smallest.value = -1;
	}
	return (order_list(str));
}
