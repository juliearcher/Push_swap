/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/05 07:20:33 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/05 07:20:34 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "common.h"

static void	add_space_list(t_elem *list, int size)
{
	while (size > 0)
	{
		list[size] = list[size - 1];
		--size;
	}
}

static void	remove_space_list(t_elem *list, int size)
{
	int		i;

	i = 0;
	while (i < size - 1)
	{
		list[i] = list[i + 1];
		++i;
	}
}

void		push_a(t_push *str)
{
	if (str->sizeb == 0)
		return ;
	add_space_list(str->lista, str->sizea);
	str->lista[0] = str->listb[0];
	remove_space_list(str->listb, str->sizeb);
	++str->sizea;
	--str->sizeb;
}

void		push_b(t_push *str)
{
	if (str->sizea == 0)
		return ;
	add_space_list(str->listb, str->sizeb);
	str->listb[0] = str->lista[0];
	remove_space_list(str->lista, str->sizea);
	++str->sizeb;
	--str->sizea;
}
