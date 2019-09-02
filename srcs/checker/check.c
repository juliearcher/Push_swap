/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/05 06:40:39 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/05 06:40:41 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "checker.h"

static int	execute_instruction(t_push *str, char *ins)
{
	if (ft_strcmp(ins, "sa") == 0)
		swap_a(str);
	else if (ft_strcmp(ins, "sb") == 0)
		swap_b(str);
	else if (ft_strcmp(ins, "ss") == 0)
		swap_ab(str);
	else if (ft_strcmp(ins, "pa") == 0)
		push_a(str);
	else if (ft_strcmp(ins, "pb") == 0)
		push_b(str);
	else if (ft_strcmp(ins, "ra") == 0)
		rotate_a(str);
	else if (ft_strcmp(ins, "rb") == 0)
		rotate_b(str);
	else if (ft_strcmp(ins, "rr") == 0)
		rotate_ab(str);
	else if (ft_strcmp(ins, "rra") == 0)
		reverse_rotate_a(str);
	else if (ft_strcmp(ins, "rrb") == 0)
		reverse_rotate_b(str);
	else if (ft_strcmp(ins, "rrr") == 0)
		reverse_rotate_ab(str);
	else
		return (0);
	return (1);
}

int			check_instructions(t_push *str)
{
	t_ins	*tmp;
	char	*line;
	int		err;

	while ((err = get_next_line(0, &line)) > 0)
	{
		if (create_instruction(str, line) == 0)
		{
			free(line);
			return (-2);
		}
		free(line);
	}
	if (err < 0)
		return (-2);
	tmp = str->instructions;
	while (tmp != NULL)
	{
		if (!execute_instruction(str, tmp->ins))
			return (-2);
		tmp = tmp->next;
	}
	return (str->sizeb == 0 &&
		is_list_ordered(str->lista, str->sizea, ASC) ? 0 : -1);
}
