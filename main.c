/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:51:24 by kasakamo          #+#    #+#             */
/*   Updated: 2025/08/14 18:00:10 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	p_err(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*st_a;
	t_stack	*st_b;
	// t_stack *tmp;

	if (ac < 2)
		return (0);
	if (!is_valid(ac, av))
		return (p_err());
	st_a = in_stack(ac, av);
	if (!st_a)
		return (p_err());
	// tmp->top = st_a->top;
	// while (tmp->top)
	// {
	// 	printf("%d, ", tmp->top->value);
	// 	tmp->top = tmp->top->next;
	// }
	// printf("\n");
	st_b = malloc(sizeof(t_stack));
	if (!st_b)
	{
		free_stack(st_a);
		return (p_err());
	}
	st_b->top = NULL;
	st_b->size = 0;
	if (!is_sorted(st_a))
		sort_stack(&st_a, &st_b);
	// while (st_a->top)
	// {
	// 	printf("%d, ", st_a->top->value);
	// 	st_a->top = st_a->top->next;
	// }
	// printf("\n");
	free_stack(st_a);
	free_stack(st_b);
}
