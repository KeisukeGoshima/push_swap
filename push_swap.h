/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 23:12:38 by marvin            #+#    #+#             */
/*   Updated: 2022/10/29 23:12:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
// # include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	long			num;
	int				sign;
	struct s_list	*next;
}	t_list;

int		ft_atoi(const char *str);
t_list	*ft_lstnew(long num);
void	push(t_list **dest, t_list **src);
void	reverse_rotate(t_list **num_list);
void	rotate(t_list **num_list);
void	swap(t_list **num_list);
int		check_sorted_len(t_list **a);
int		ft_lstsize(t_list *lst);

void print_list(t_list **a);

#endif