/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_abs.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 09:34:39 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 13:44:15 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

unsigned int	ft_abs(int n)
{
	unsigned int	un;

	un = (unsigned int)n;
	if (n < 0)
		un = -n;
	return (un);
}
