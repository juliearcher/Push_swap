/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/05 06:33:42 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/05 06:33:43 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "checker.h"

int		main(int ac, char **av)
{
	t_push	str;
	int		res;

	if (ac == 1)
		return (0);
	init_push_struct(&str);
	if (create_list(&str, &av[1], ac - 1) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	res = check_instructions(&str);
	free_str(&str);
	if (res == -2)
		ft_putstr_fd("Error\n", 2);
	else
		ft_putstr_fd(res == -1 ? "KO\n" : "OK\n", 1);
	return (0);
}
