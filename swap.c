/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 23:12:22 by marvin            #+#    #+#             */
/*   Updated: 2022/10/29 23:12:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

void	swap(t_list **num_list)
{
	t_list	*temp;
	t_list	*first;

	first = *num_list;
	if (first -> next != NULL)
	{
		temp = first -> next;
		first -> next = first -> next -> next;
		temp -> next = first;
		*num_list = temp;
	}
}

void	rotate(t_list **num_list)
{
	t_list	*temp;
	t_list	*first;

	temp = (*num_list);
	if ((*num_list) -> next == NULL)
		return ;
	first = (*num_list) -> next;
	while ((*num_list) -> next != NULL)
		(*num_list) = (*num_list) -> next;
	(*num_list) -> next = temp;
	temp -> next = NULL;
	*num_list = first;
}

void	reverse_rotate(t_list **num_list)
{
	t_list	*temp;
	t_list	*temp_first;

	temp_first = (*num_list);
	while ((*num_list) -> next != NULL)
	{
		temp = (*num_list);
		(*num_list) = (*num_list) -> next;
	}
	(*num_list) -> next = temp_first;
	temp -> next = NULL;
}

void	push(t_list **dest, t_list **src)
{
	t_list	*temp;

	if (*src == NULL)
		return ;
	temp = (*src) -> next;
	(*src) -> next = *dest;
	*dest = *src;
	*src = temp;
}

int	check_sorted_len(t_list **a)
{
	int		num;
	int		i;
	t_list	*temp;

	temp = (*a);
	if (temp == NULL)
		return (0);
	num = temp -> num;
	i = 1;
	while (temp -> next != NULL)
	{
		if (num > temp -> next -> num)
			break;
		num = temp -> next -> num;
		temp = temp -> next;
		i++;
	}
	return (i);
}
