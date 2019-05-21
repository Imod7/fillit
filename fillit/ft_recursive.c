/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_recursive.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/10 15:24:27 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/05/21 20:24:34 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*  if return >=  0 : tet placed
	if return == -1 : none of the available tets fit
	if return == -2 : no tets available

	things that cause next tet:
		- tet created more holes than maxholes
		- tet goes over sepparator (after every 4 bits), no two 1 bits of the tet may be seperated by only the separator
		- shifting a 1 bit out of the tet
		- tet has been placed already (first and last bit of tet are 1)

	things that cause recursion:
		- none of the tets can be placed
*/
int ft_place(unsigned short square, int offset, unsigned short *tets)
{
	int i;

	i = 0;
	while ((~square >> i & tet) != tet)
		i++;
	if (tet << i & 6144 == 6144 || tet << i & 384 == 384 || tet << i & 24 == 24)
		//tet goes over the border
	square = tet << i ^ square;
	ft_putbin(square);
}

int	ft_replace(char ***square, int offset, char ***ar, int tet)
{
	int i;

	if (ar[0][tet][0] == 0)
		return (-2);
	ar[0][tet][4] = 0;
	i = 0;
	while (i < 4)
	{
		square[0][(ar[0][tet][i] + offset) / 4][(ar[0][tet][i] + offset) % 4] = '.';
		i++;
	}
	return (ft_place(square, offset, *ar, tet + 1));
}
/* ft_recursive returns -1 whenever none of the available tets fit, if none are available: -2, otherwise the tet placed
	- offset indicates the offset where blocks will be placed
*/

//for some reason the first tet cant get placed so it returns 1 and stops the recursion
int	ft_recursive(unsigned short square, int offset, unsigned short *tets /*int maxhole*/)
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
	while (ft_recursive(square, offset + 1, tetarr/*maxhole - holes*/) == -1)
	{
		tet = ft_replace(square, offset - 1, tetarr, tet/*maxhole*/);
		if (tet < 0)
			return (tet);
		tetarr[0][tet][4] = 1;
	}
	return (0);
}
