/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 19:49:41 by anmauffr          #+#    #+#             */
/*   Updated: 2019/03/08 17:18:16 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_checker.h>
#include <stdlib.h>

void	ft_sa(t_check **a, t_check **begina, int n)
{
	if (ft_lstl(a) <= 1)
		return ;
	(*a) = (*a)->next;
	(*begina)->next = (*begina)->next->next;
	(*a)->next = *begina;
	*begina = *a;
	if (n != 0)
		ft_printf("sa\n");
}

void	ft_sb(t_check **b, t_check **beginb, int n)
{
	if (ft_lstl(b) <= 1)
		return ;
	(*b) = (*b)->next;
	(*beginb)->next = (*beginb)->next->next;
	(*b)->next = *beginb;
	*beginb = *b;
	if (n != 0)
		ft_printf("sb\n");
}

void	ft_ss(t_check *a, t_check *b)
{
	ft_sa(a);
	ft_sb(b);
}

void	ft_pa(t_check **a, t_check **b, t_check **begina, t_check **beginb)
{
	t_check	*t;

	if (*b)
	{
		t = *b;
		*b = (*b)->next;
		*beginb = *b;
		t->next = (*a);
		*a = t;
		*begina = *a;
	}
}

void	ft_pb(t_check **a, t_check **b, t_check **begina, t_check **beginb)
{
	t_check	*t;

	if (*a)
	{
		t = *a;
		*a = (*a)->next;
		*begina = *a;
		t->next = (*b);
		*b = t;
		*beginb = *b;
	}
}
