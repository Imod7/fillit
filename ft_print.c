/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/09 12:46:58 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/06/11 18:02:01 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void				print_board(uint16_t *board)
{
	int				bit;
	int				row;
	uint16_t		mask;

	bit = 0;
	row = 0;
	while (row < 16)
	{
		bit = 0;
		while (bit < 16)
		{
			mask = board[row] >> bit;
			//printf("bit = %d , mask = %d , -- %d \n", bit, mask, mask & 1);
			if (mask & 1)
				printf("1 ");
			else
				printf("0 ");
			bit++;
		}
		row++;
		printf("\n");
		if (row % 4 == 0)
		{
			printf("\n");
			//printf("row = %d \n", row );
		}
	}
}

void				print_binary(uint64_t num, int size)
{
	int				bit;
	int				row;
	int 			col;
	uint64_t		mask;

	bit = 0;
	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < (size * size))
		{
			mask = num >> bit;
			//printf("\n mask = %llu \n", mask);
			if (mask & 1)
				printf("1 ");
			else
				printf("0 ");
			bit++;
			col++;
		}
		row++;
		printf("\n");
	}
}

void				print_binary_orig(unsigned short num, int size)
{
	int				bit;
	int				row;
	int 			col;
	unsigned short	mask;

	bit = 0;
	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			mask = num >> bit;
			if (mask & 1)
				printf("1 ");
			else
				printf("0 ");
			bit++;
			col++;
		}
		row++;
		printf("\n");
	}
}

void				print_binary_d(uint64_t num, int size)
{
	int				bit;
	int				row;
	int 			col;
	unsigned short	mask;

	bit = 0;
	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			mask = num >> bit;
			if (mask & 1)
				printf("1 ");
			else
				printf("0 ");
			bit++;
			col++;
		}
		row++;
		printf("\n");
	}
}

void				print_list(t_list **tetr_lst)
{
	t_list			*temp;
	size_t			i;

	i = 1;
	printf(ANSI_COLOR_CYAN "\n=== Printing Linked List of Tetriminos ===\n" ANSI_COLOR_RESET);
	temp = *tetr_lst;
	while (temp != NULL)
	{
		printf(" tetr/node %lu -> %llu \n", i, *(uint64_t *)(temp->content));
		temp = temp->next;
		i++;
	}
}
