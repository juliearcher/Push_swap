/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/05 06:44:34 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/05 06:44:35 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "common.h"

void	init_push_struct(t_push *str)
{
	str->instructions = NULL;
	str->last_ins = NULL;
	str->lista = NULL;
	str->listb = NULL;
	str->sizelist = 0;
	str->sizea = 0;
	str->sizeb = 0;
	str->sizeins = 0;
}

int		copy_str_push(t_push *dest, t_push *src)
{
	dest->instructions = NULL;
	dest->last_ins = NULL;
	dest->lista = (t_elem *)malloc((src->sizelist) * sizeof(t_elem));
	dest->listb = (t_elem *)malloc((src->sizelist) * sizeof(t_elem));
	if (dest->lista == NULL || dest->listb == NULL)
		return (-1);
	ft_memcpy(dest->lista, src->lista,
				src->sizea * sizeof(t_elem));
	ft_memcpy(dest->listb, src->listb,
				src->sizeb * sizeof(t_elem));
	dest->sizelist = src->sizelist;
	dest->sizea = src->sizea;
	dest->sizeb = src->sizeb;
	dest->sizeins = 0;
	return (0);
}

void	free_str(t_push *str)
{
	t_ins	*tmp;
	t_ins	*prev;

	if (str->lista != NULL)
		free(str->lista);
	if (str->listb != NULL)
		free(str->listb);
	tmp = str->instructions;
	while (tmp != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
		free(prev);
	}
	str->lista = NULL;
	str->listb = NULL;
	tmp = NULL;
}
