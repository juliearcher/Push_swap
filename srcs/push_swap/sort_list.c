/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort_list.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/12 06:37:42 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/12 06:37:43 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

static int		free_all_str(t_push *str2, t_push *str3, t_push *str4, int ret)
{
	free_str(str2);
	free_str(str3);
	free_str(str4);
	return (ret);
}

static t_ins	*get_smallest_ins(t_push *str, t_push *str2,
					t_push *str3, t_push *str4)
{
	if (str->sizeins <= str2->sizeins && str->sizeins <= str3->sizeins &&
		str->sizeins <= str4->sizeins)
		return (str->instructions);
	else if (str2->sizeins <= str->sizeins && str2->sizeins <= str3->sizeins &&
		str2->sizeins <= str4->sizeins)
		return (str2->instructions);
	else if (str3->sizeins <= str->sizeins && str3->sizeins <= str2->sizeins &&
		str3->sizeins <= str4->sizeins)
		return (str3->instructions);
	return (str4->instructions);
}

static int		simple_sort(t_push *str, int reverse)
{
	char	*ins;
	void	(*f)(t_push *);

	ins = reverse ? "rra" : "ra";
	f = reverse ? &reverse_rotate_a : &rotate_a;
	while (continue_swapping(str))
	{
		if (str->lista[0].value > str->lista[1].value &&
			(str->lista[0].index != str->sizelist - 1 ||
			str->lista[1].index != 0))
		{
			if (add_instruction(str, "sa", &swap_a))
				return (-1);
		}
		else if (add_instruction(str, ins, f) == -1)
			return (-1);
	}
	return (order_list(str));
}

int				sort_list(t_push *str)
{
	t_push	str2;
	t_push	str3;
	t_push	str4;

	if (copy_str_push(&str2, str) == -1 ||
		copy_str_push(&str3, str) == -1 || copy_str_push(&str4, str) == -1)
		return (free_all_str(&str2, &str3, &str4, -1));
	if (str->sizelist <= 5 && ((simple_sort(str, 0) == -1 ||
		simple_sort(&str2, 1) == -1)))
		return (free_all_str(&str2, &str3, &str4, -1));
	else if ((long_sort(&str3, 0) == -1 ||
		long_sort(&str4, 1) == -1))
		return (free_all_str(&str2, &str3, &str4, -1));
	if (str->sizelist > 5)
		print_instructions(str3.sizeins < str4.sizeins ?
			str3.instructions : str4.instructions);
	else
		print_instructions(get_smallest_ins(str, &str2, &str3, &str4));
	return (free_all_str(&str2, &str3, &str4, 0));
}
