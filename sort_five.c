/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:42:06 by kasakamo          #+#    #+#             */
/*   Updated: 2025/07/13 20:12:15 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_top(t_stack *s, int idx, int f)
{
	if (idx <= s->size / 2)
		while (idx-- > 0)
		{
			if (f)
				op_rb(s, 1);
			else
				op_ra(s, 1);
		}
	else
		while (idx++ < s->size)
		{
			if (f)
				op_rrb(s, 1);
			else
				op_rra(s, 1);
		}
}

int	find_min_index(t_stack *a)
{
	t_node	*cur;
	int		min;
	int		idx;
	int		i;

	cur = a->top;
	min = cur->value;
	idx = 0;
	i = 0;
	while (cur)
	{
		if (cur->value < min)
		{
			min = cur->value;
			idx = i;
		}
		cur = cur->next;
		i++;
	}
	return (idx);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int		idx;

	while ((*a)->size > 3)
	{
		idx = find_min_index(*a);
		rotate_top(*a, idx, 0);
		op_pb(a, b);
	}
	sort_three(*a);
	while (*b && (*b)->size)
		op_pa(a, b);
}
