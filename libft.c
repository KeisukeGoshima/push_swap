/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 23:22:46 by marvin            #+#    #+#             */
/*   Updated: 2022/10/29 23:22:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_check_front_atoi(const char *str, long num, int i, int sign)
{
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9' )
			break ;
		if (num > 0 && num == LONG_MAX / 10 && (str[i] - '0') > LONG_MAX % 10)
			return (LONG_MAX);
		if (num > 0 && num > LONG_MAX / 10)
			return (LONG_MAX);
		if (num < 0 && num == LONG_MIN / 10 && -(str[i] - '0') < LONG_MIN % 10)
			return (LONG_MIN);
		if (num < 0 && num < LONG_MIN / 10)
			return (LONG_MIN);
		num = num * 10 + sign * (str[i] - '0');
		i++;
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	return (ft_check_front_atoi(str, 0, 0, 1));
}

t_list	*ft_lstnew(long num)
{
	t_list	*temp;

	temp = malloc(sizeof(t_list));
	if (temp == NULL)
		return (NULL);
	if (num < 0)
	{
		temp -> sign = -1;
		num *= -1;
	}
	else
		temp -> sign = 1;
	temp -> num = num;
	temp -> next = NULL;
	return (temp);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 1;
	if (lst == NULL)
		return (0);
	while (lst -> next != 0)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}
