/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 09:43:51 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/02 09:45:42 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_memdel(void **ap)
{
	if (ap != 0 && *ap != 0)
	{
		free(*ap);
		*ap = 0;
	}
}
