/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_list.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/05 06:51:39 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/05 06:51:40 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "common.h"

static int		is_doublon(char **list, int position)
{
	int		i;
	int		nb;

	i = 0;
	nb = ft_atoi(list[position]);
	while (i < position)
	{
		if (ft_atoi(list[i]) == nb)
			return (1);
		++i;
	}
	return (0);
}

static int		is_list_valid(char **list)
{
	int		i;

	i = 0;
	while (list[i])
	{
		if (!ft_isnumber(list[i]) || !ft_fits_in_int(list[i]) ||
				is_doublon(list, i))
			return (0);
		++i;
	}
	return (1);
}

static void		assign_index(t_elem *list, int size)
{
	int		j;
	int		i;

	i = 0;
	j = size;
	while (i < size)
	{
		if (list[size].value < list[i].value &&
			list[i].index < j)
			j = list[i].index;
		++i;
	}
	i = 0;
	while (i < size)
	{
		if (list[i].index >= j)
			list[i].index += 1;
		++i;
	}
	list[size].index = j;
}

static t_elem	*check_list(char **list, int size)
{
	t_elem	*new_list;
	int		i;

	if (!is_list_valid(list) ||
		(new_list = (t_elem *)malloc(size * sizeof(t_elem))) == NULL)
		return (NULL);
	i = 0;
	while (list[i])
	{
		new_list[i].value = ft_atoi(list[i]);
		new_list[i].index = i;
		new_list[i].push = 0;
		assign_index(new_list, i);
		++i;
	}
	return (new_list);
}

int				create_list(t_push *str, char **list, int size)
{
	int		i;

	i = 0;
	if ((str->lista = check_list(list, size)) == NULL ||
		(str->listb = (t_elem *)malloc(size * sizeof(t_elem))) == NULL)
		return (-1);
	str->sizelist = size;
	str->sizea = size;
	return (0);
}
