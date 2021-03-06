/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 09:19:13 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/02 13:49:09 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

const char	*ft_strrchr(const char *s, int c)
{
	const char	*ret;
	int			i;

	ret = 0;
	i = -1;
	while (s != 0 && s[++i] != 0)
		if (s[i] == c)
			ret = &s[i];
	if (s[i] == c)
		ret = &s[i];
	return (ret);
}
