/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   instructions.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/12 06:09:00 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/12 06:09:01 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "checker.h"

int		create_instruction(t_push *str, char *ins)
{
	t_ins	*elem;

	if ((elem = (t_ins *)malloc(sizeof(t_ins))) == NULL ||
		ft_strlen(ins) > 3)
		return (0);
	ft_strcpy(elem->ins, ins);
	elem->next = NULL;
	if (str->last_ins == NULL)
		str->instructions = elem;
	else
		str->last_ins->next = elem;
	str->last_ins = elem;
	str->sizeins += 1;
	return (1);
}

int		add_instruction(t_push *str, char *ins, void (*f)(t_push *))
{
	if (create_instruction(str, ins) == 0)
		return (-1);
	f(str);
	return (0);
}
