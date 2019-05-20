/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_recursive.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/10 15:24:27 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/05/20 17:24:29 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*  if return >=  0 : tet placed
	if return == -1 : no tet placed
*/
int	ft_place(char ***square, int offset,  char **ar, int tet)
{
	int i;
	int extra;

	extra = 0;
	if (offset > 0)
		offset--;
	while (extra < 2)
	{
		i = 0;
		while (ar[tet][4] == 1)
			tet++;
		if (ar[tet][0] == '\0')
			break ;
		while (i < 4 && ar[tet][3] + offset + extra < 16)
		{
			if (square[0][(ar[tet][i] + offset + extra) / 4][(ar[tet][i] + offset + extra) % 4] == '.')
				i++;
			else
				break ;
		}
		if (i == 4)
		{
			while (i > 0)
			{
				i--;
				square[0][(ar[tet][i] + offset + extra) / 4][(ar[tet][i] + offset + extra) % 4] = (char)(tet + 65);
			}
			return (tet);
		}
		tet++;
		if (ar[tet][0] == '\0')
		{
			extra++;
			tet = 0;
		}
	}
	return (-1);
}

int	ft_replace(char ***square, int offset, char ***ar, int tet)
{
	int i;
	int extra;

	extra = 0;
	if (ar[0][tet][0] == 0)
		return (-2);
	ar[0][tet][4] = 0;
	i = 0;
	if (offset != 0)
	{
		if (square[0][(offset - 1) / 4][(offset - 1) % 4] == tet + 'A')
			extra = 1;
	}
	while (i < 4)
	{
		square[0][(ar[0][tet][i] + offset - extra) / 4][(ar[0][tet][i] + offset - extra) % 4] = '.';
		i++;
	}
	return (ft_place(square, offset, *ar, tet + 1));
}
/* ft_recursive returns -1 whenever none of the available tets fit, if none are available: -2, otherwise the tet placed
	- offset indicates the offset where blocks will be placed
*/

void ft_printsquare(char **square)
{
	int i;

	i = 0;
	while (i < 4)
	{
		ft_putendl(square[i]);
		i++;
	}
	ft_putendl("");
}
//for some reason the first tet cant get placed so it returns 1 and stops the recursion
int	ft_recursive(char ***square, int offset, char ***tetarr /*int maxhole*/)
{
	int		tet;

	tet = 0;
	while (tetarr[0][tet][4] == 1)
	{
		tet++;
		if (tetarr[0][tet][0] == 0)
			return (-2);
	}
	tet = 0;
	while (ft_isupper(square[0][offset / 4][offset % 4]) > 0)
		offset++;
	tet = ft_place(square, offset - 1, *tetarr, tet);
	if (tet < 0)
		return (tet);
	tetarr[0][tet][4] = 1;
	ft_printsquare(*square);
	while (ft_recursive(square, offset, tetarr/*maxhole - holes*/) == -1)
	{
		tet = ft_replace(square, offset - 1, tetarr, tet/*maxhole*/);
		if (tet < 0)
			return (tet);
		tetarr[0][tet][4] = 1;
		ft_printsquare(*square);
	}
	return (0);
}