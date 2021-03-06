/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strclr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 11:05:17 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/02 11:06:22 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_strclr(char *s)
{
	int	i;

	i = -1;
	while (s != 0 && s[++i] != 0)
		s[i] = 0;
}
