/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   list.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/05 07:50:41 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/05 07:50:42 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "common.h"

int		is_list_ordered(t_elem *list, int size, int direction)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if ((direction == ASC && list[i].value > list[i + 1].value) ||
			(direction == DESC && list[i].value < list[i + 1].value))
			return (0);
		++i;
	}
	return (1);
}
