/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   reverse_rotate.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/05 07:29:15 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/05 07:29:17 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "common.h"

static void	rotate(t_elem *list, int size)
{
	t_elem	temp;
	int		i;

	if (size < 2)
		return ;
	i = size - 1;
	temp = list[size - 1];
	while (i > 0)
	{
		list[i] = list[i - 1];
		--i;
	}
	list[i] = temp;
}

void		reverse_rotate_a(t_push *str)
{
	rotate(str->lista, str->sizea);
}

void		reverse_rotate_b(t_push *str)
{
	rotate(str->listb, str->sizeb);
}

void		reverse_rotate_ab(t_push *str)
{
	reverse_rotate_a(str);
	reverse_rotate_b(str);
}
