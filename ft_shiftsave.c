/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_shiftsave.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/10 22:48:53 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/06/27 15:20:22 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetlst	*ft_newtet(uint64_t tet)
{
	t_tetlst	*elem;

	elem = (t_tetlst *)malloc(sizeof(t_tetlst));
	elem->tet = tet;
	elem->row = 0;
	elem->col = 0;
	elem->next = NULL;
	return (elem);
}

t_tetlst		*ft_addtet(t_tetlst **tetr_lst, t_tetlst *newtet)
{
	t_tetlst *temp;

	temp = *tetr_lst;
	while ((*tetr_lst)->next != NULL)
		*tetr_lst = (*tetr_lst)->next;
	(*tetr_lst)->next = newtet;
	return (temp);
}

void		save_tolist(t_tetlst **tetr_lst, uint64_t tet)
{
	t_tetlst			*newtet;

	newtet = ft_newtet(tet);
	if (*tetr_lst == NULL)
		*tetr_lst = newtet;
	else
		*tetr_lst = ft_addtet(tetr_lst, newtet);
}
/*
	-- function "shift_to_topleft" --
	Reading the 64-bit number/tetrimino  
	and shifting it to the top left
*/
void		shiftsave(t_tetlst **tetr_lst, uint64_t tet)
{
	size_t			i;
	size_t			x;
	size_t			y;
	uint64_t		temp;
	
	//printf("Tet before shifting\n");
	//print_binary(num, 4);
	//printf("\n");
	i = 0;
	x = 16;
	y = 16;
	while (i < 64)
	{
		temp = tet & ((uint64_t)1 << i);
		if (temp != 0)
		{
			//printf("temp = %llu, pos = %lu \n", temp, i);
			if (i / 4 < y)
			{
				//printf("this is executed \n");
				y = i / 4;
			}
			if ((i - (4 * (i / 4))) < x)
			{
				//printf("this is also executed \n");
				x = i - (4 * (i / 4));
			}
			//printf("i = %lu, x = %lu, y = %lu \n", i, x, y);
			//printf("\n");
		}
		//printf("i = %lu \n", i);
		i++;
	}
	tet >>= (x + (4 * y));
	//printf("num = %llu \n", num);
	//print_binary(num, 4);
	save_tolist(tetr_lst, tet);
}
