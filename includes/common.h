/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   common.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/05 06:21:46 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/05 06:21:48 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <stdlib.h>
# include "libft.h"

# define DESC		0
# define ASC		1
# define NORMAL		0
# define REVERSE	1

typedef struct		s_ins
{
	char			ins[4];
	struct s_ins	*next;
}					t_ins;

typedef	struct		s_elem
{
	int		value;
	int		index;
	int		push;
}					t_elem;

typedef struct		s_push
{
	t_ins	*instructions;
	t_ins	*last_ins;
	t_elem	*lista;
	t_elem	*listb;
	int		*move;
	int		sizelist;
	int		sizea;
	int		sizeb;
	int		sizeins;
}					t_push;

/*
** create_list.c
*/
int					create_list(t_push *str, char **list, int size);

/*
** init.c
*/
void				init_push_struct(t_push *str);
int					copy_str_push(t_push *dest, t_push *src);
void				free_str(t_push *str);

/*
** instructions.c
*/
int					create_instruction(t_push *str, char *ins);
int					add_instruction(t_push *str, char *ins,
						void (*f)(t_push *));

/*
** list.c
*/
int					is_list_ordered(t_elem *list, int size, int direction);

/*
** push.c
*/
void				push_a(t_push *str);
void				push_b(t_push *str);

/*
** reverse_rotate.c
*/
void				reverse_rotate_a(t_push *str);
void				reverse_rotate_b(t_push *str);
void				reverse_rotate_ab(t_push *str);

/*
** rotate.c
*/
void				rotate_a(t_push *str);
void				rotate_b(t_push *str);
void				rotate_ab(t_push *str);

/*
** swap.c
*/
void				swap_a(t_push *str);
void				swap_b(t_push *str);
void				swap_ab(t_push *str);

#endif
