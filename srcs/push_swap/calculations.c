/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   calculations.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/12 07:11:46 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/12 07:11:51 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

int		do_reverse(t_push *str)
{
	int	first;
	int	last;
	int	i;

	i = 1;
	first = str->sizelist;
	last = 0;
	while (i < str->sizelist)
	{
		if (str->lista[i].push && i < first)
			first = i;
		else if (str->lista[i].push && i > last)
			last = i;
		++i;
	}
	first = str->sizelist - first;
	return (first > last);
}

int		get_listb_size(t_push *str, int index, int mode)
{
	t_elem	last;
	int		nb;
	int		i;

	nb = 0;
	i = index == str->sizea - 1 ? 0 : index + 1;
	last = str->lista[index];
	while (i != index)
	{
		if ((mode == NORMAL && last.value > str->lista[i].value) ||
			(mode == INDEX && last.index != str->lista[i].index - 1))
			++nb;
		else
			last = str->lista[i];
		i = i == str->sizea - 1 ? 0 : i + 1;
	}
	return (nb);
}

void	get_moved_elems(t_push *str, int index, int mode)
{
	t_elem	last;
	int		i;

	i = index == str->sizea - 1 ? 0 : index + 1;
	last = str->lista[index];
	while (i != index)
	{
		if ((mode == NORMAL && last.value > str->lista[i].value) ||
			(mode == INDEX && last.index != str->lista[i].index - 1))
			str->lista[i].push = 1;
		else
		{
			last = str->lista[i];
			str->lista[i].push = 0;
		}
		i = i == str->sizea - 1 ? 0 : i + 1;
	}
	str->lista[i].push = 0;
}

t_elem	get_smallest_index(t_push *str, t_elem *prev, int mode)
{
	t_elem	smallest;
	int		res;
	int		i;

	i = 0;
	smallest.value = prev == NULL ? str->sizea : prev->value;
	smallest.index = prev == NULL ? 0 : prev->index;
	while (i < str->sizea)
	{
		if ((res = get_listb_size(str, i, mode)) < smallest.value ||
			(res == smallest.value &&
			str->lista[i].index < str->lista[smallest.index].index &&
			(prev == NULL || smallest.index != prev->index)))
		{
			smallest.value = res;
			smallest.index = i;
		}
		++i;
	}
	if (prev == NULL || smallest.index != prev->index)
		get_moved_elems(str, smallest.index, mode);
	return (smallest);
}

int		continue_swapping(t_push *str)
{
	int	i;

	i = 0;
	while (i < str->sizea - 1)
	{
		if (str->lista[i].value > str->lista[i + 1].value &&
			(str->lista[i].index != str->sizelist - 1 ||
			str->lista[i + 1].index != 0))
			return (1);
		++i;
	}
	return (str->lista[i].value > str->lista[0].value &&
			(str->lista[i].index != str->sizelist - 1 ||
			str->lista[0].index != 0));
}
