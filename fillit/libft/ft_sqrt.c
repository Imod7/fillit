/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sqrt.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 19:32:30 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/03/18 20:31:17 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int num;

	num = 1;
	while (num * num <= nb && nb <= 2147395600 && nb >= 0)
	{
		if (num * num == nb)
			return (num);
		num++;
	}
	return (0);
}