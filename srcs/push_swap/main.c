/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/05 09:02:01 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/05 09:02:02 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void	print_instructions(t_ins *instruction)
{
	while (instruction != NULL)
	{
		ft_putstr(instruction->ins);
		ft_putchar('\n');
		instruction = instruction->next;
	}
}

int		main(int ac, char **av)
{
	t_push	str;

	if (ac == 1)
		return (0);
	init_push_struct(&str);
	if (create_list(&str, &av[1], ac - 1) == -1 || sort_list(&str) == -1)
	{
		free_str(&str);
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	free_str(&str);
	return (0);
}
