/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 23:12:14 by marvin            #+#    #+#             */
/*   Updated: 2022/10/29 23:12:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void print_list(t_list **a)
{
	t_list *temp;

	temp = *a;
	while (temp != NULL && temp -> next != NULL)
	{
		printf("%ld\n", temp -> num);
		temp = temp -> next;
	}
	if (temp != NULL)
		printf("%ld\n", temp -> num);
	printf("-------------\n");
}

void	stack_a_calc_rotate(t_list **a, int* command)
{
	rotate(a);
	if (ft_lstsize(*a) > 1)
	{
		if (command[0] == 1)
		{
			command[0] = 0;
			printf("ra\n");
		}
		else if (command[1] == 1)
		{
			command[1] = 0;
			printf("rr\n");
		}
		else
			command[0] = 1;
	}
}

void	stack_a_calc_push(t_list **a, t_list **b, int* command)
{
	push(b, a);
	printf("pb\n");
	rotate(b);
	if (ft_lstsize(*b) > 1)
	{
		if (command[1] == 1)
		{
			command[1] = 0;
			printf("rb\n");
		}
		else if (command[0] == 1)
		{
			command[0] = 0;
			printf("rr\n");
		}
		else
			command[0] = 1;
	}
}

void	stack_b_calc_rotate(t_list **b, int* command)
{
	rotate(b);
	if (ft_lstsize(*b) > 1)
	{
		if (command[1] == 1)
		{
			command[1] = 0;
			printf("rb\n");
		}
		else if (command[0] == 1)
		{
			command[0] = 0;
			printf("rr\n");
		}
		else
			command[0] = 1;
	}
}

void	stack_b_calc_push(t_list **a, t_list **b, int* command)
{
	push(a, b);
	printf("pa\n");
	rotate(a);
	if (ft_lstsize(*a) > 1)
	{
		if (command[0] == 1)
		{
			command[0] = 0;
			printf("ra\n");
		}
		else if (command[1] == 1)
		{
			command[1] = 0;
			printf("rr\n");
		}
		else
			command[0] = 1;
	}
}

void	command_init(int *command)
{
	if (command[0] == 1)
		printf("ra\n");
	else if (command[1] == 1)
		printf("rb\n");
	command[0] = 0;
	command[1] = 0;
}

void	base_calc(t_list **a, t_list **b, int *command, int base)
{
	int	i;
	int	j;

	i = ft_lstsize(*a);
	j = ft_lstsize(*b);
	while (i-- > 0)
		if ((*a) -> num % base < base / 2)
			stack_a_calc_rotate(a, command);
		else
			stack_a_calc_push(a, b, command);
	command_init(command);
	while (j-- > 0)
		if ((*b) -> num % base < base / 2)
			stack_b_calc_push(a, b, command);
		else
			stack_b_calc_rotate(b, command);
	command_init(command);
}

void	sign_calc(t_list **a, t_list **b, int *command)
{
	int	i;

	i = ft_lstsize(*a);
	while (i-- > 0)
		if ((*a) -> sign == 1)
			stack_a_calc_rotate(a, command);
		else
			stack_a_calc_push(a, b, command);
	command_init(command);
	i = ft_lstsize(*b);
	while (i-- > 0)
	{
		push(a, b);
		printf("pa\n");
	}
}

void	push_swap(t_list **a, t_list **b, int len)
{
	int	base;
	int command[2];

	base = 2;
	command[0] = 0;
	command[1] = 0;
	while (1)
	{	
		base_calc(a, b, command, base);
		base *= 2;
		if (check_sorted_len(a) == len)
			break;
	}
	sign_calc(a, b, command);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;
	t_list	*temp;
	t_list	*temp2;
	int		i;

	a = malloc(sizeof(t_list **));
	b = malloc(sizeof(t_list **));
	i = 1;
	while (i < argc)
	{
		temp = ft_lstnew(ft_atoi(argv[i]));
		if (i == 1)
			*a = temp;
		else
			temp2 -> next = temp;
		temp2 = temp;
		i++;
	}
	*b = NULL;
	push_swap(a, b, argc - 1);
	return (0);
}