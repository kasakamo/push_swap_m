/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:42:58 by kasakamo          #+#    #+#             */
/*   Updated: 2025/08/13 16:11:59 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index(t_stack *b)
{
	t_node	*cur;
	int		max;
	int		idx;
	int		i;

	cur = b->top;
	max = cur->index;
	idx = 0;
	i = 0;
	while (cur)
	{
		if (cur->index > max)
		{
			max = cur->index;
			idx = i;
		}
		cur = cur->next;
		i++;
	}
	return (idx);
}

void	set_idx(t_stack *a)
{
	t_node	*cur;
	t_node	*cmp;
	int		idx;

	cur = a->top;
	while (cur)
	{
		idx = 0;
		cmp = a->top;
		while (cmp)
		{
			if (cmp->value < cur->value)
				idx++;
			cmp = cmp->next;
		}
		cur->index = idx;
		cur = cur->next;
	}
}

void	sort_large(t_stack **a, t_stack **b)
{
	int	chunk_size;
	int	chunk;
	int	pushed;
	int	size;
	int	idx;

	chunk = 0;
	pushed = 0;
	size = (*a)->size;
	set_idx(*a);
	if (size <= 100)
		chunk_size = 15;
	else
		chunk_size = 30;
	while ((*a)->size > 0)
	{
		if ((*a)->top->index >= chunk && (*a)->top->index < chunk + chunk_size)
		{
			if ((*a)->top->index < chunk + chunk_size / 2)
				op_pb(a, b);
			else
			{
				op_pb(a, b);
				op_rb(*b, 1);
			}
			pushed++;
		}
		else
			op_ra(*a, 1);
		if (pushed == chunk_size)
		{
			chunk += chunk_size;
			pushed = 0;
		}
	}
	while ((*b)->size > 0)
	{
		idx = find_max_index(*b);
		rotate_top(*b, idx, 1);
		op_pa(a, b);
	}
}
