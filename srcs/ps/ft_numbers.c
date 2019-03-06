/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 19:49:01 by anmauffr          #+#    #+#             */
/*   Updated: 2019/03/05 19:49:02 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

void	ft_1(t_checke **a, t_checke **begina)
{
	ft_sa(a, begina, 1);
	ft_ra(a, begina, 1);
	ft_sa(a, begina, 1);
	ft_rra(a, begina, 1);
	ft_sa(a, begina, 1);
}

void	ft_2(t_checke **a, t_checke **begina)
{
	ft_sa(a, begina, 1);
	ft_ra(a, begina, 1);
	ft_sa(a, begina, 1);
	ft_rra(a, begina, 1);
}

void	ft_3(t_checke **a, t_checke **begina)
{
	ft_ra(a, begina, 1);
	ft_sa(a, begina, 1);
	ft_rra(a, begina, 1);
	ft_sa(a, begina, 1);
}

void	ft_4(t_checke **a, t_checke **begina)
{
	ft_ra(a, begina, 1);
	ft_sa(a, begina, 1);
	ft_rra(a, begina, 1);
}
