/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/05 09:03:15 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/05 09:03:17 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

# define NORMAL	0
# define INDEX	1

/*
** calculations.c
*/
int				do_reverse(t_push *str);
int				get_listb_size(t_push *str, int index, int mode);
void			get_moved_elems(t_push *str, int index, int mode);
t_elem			get_smallest_index(t_push *str, t_elem *prev, int mode);
int				continue_swapping(t_push *str);

/*
** divide.c
*/
int				divide_list(t_push *str, int mode);

/*
** long_sort.c
*/
int				long_sort(t_push *str, int mode);

/*
** main.c
*/
void			print_instructions(t_ins *ins);

/*
** order_list.c
*/
int				order_list(t_push *str);

/*
** sort_list.c
*/
int				sort_list(t_push *str);

#endif
