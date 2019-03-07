/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 19:49:50 by anmauffr          #+#    #+#             */
/*   Updated: 2019/03/07 19:13:19 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_checker.h>

static void		ft_display(t_check *begina, t_check *beginb, char *str)
{
	system("clear");
	ft_printf("/---------------\\\t");
	ft_printf("/---------------\\\n");
	ft_printf("|%8c\t|\t|%8c\t|\t", 'A', 'B');
	str[0] != '\0' ? ft_printf("Commande executee : \033[32m%s\033[37m", str)
		: ft_printf("\033[32mEND\033[37m\n");
	ft_printf("|---------------|\t");
	ft_printf("|---------------|\n");
	while (begina || beginb)
	{
		if (begina && ft_printf("| \033[34m%11d\033[37m\t|\t", begina->n))
			begina = begina->next;
		else
			ft_printf("|\t\t|\t");
		if (beginb && ft_printf("| \033[33m%11d\033[37m\t|\n", beginb->n))
			beginb = beginb->next;
		else
			ft_printf("|\t\t|\n");
	}
	ft_printf("\\---------------/\t");
	ft_printf("\\---------------/\t\n\n");
	usleep(50000);
}

static void		ft_checker_b(t_check *beginb, t_check *begina, char **str)
{
	if (beginb)
	{
		ft_free_lst(beginb);
		ft_free_lst(begina);
		ft_delstr(str, -1);
		ft_printf("KO\n");
		exit(0);
	}
}

static t_check	*ft_apply(char **str, t_check *a, t_check *begina,
	t_check *beginb)
{
	t_check		*b;
	int			i;

	b = NULL;
	i = -1;
	begina = a;
	beginb = b;
	while (str[++i][0] != 0)
	{
		!ft_strcmp(str[i], "sa\n") ? ft_sa(a) : 0;
		!ft_strcmp(str[i], "sb\n") ? ft_sb(b) : 0;
		!ft_strcmp(str[i], "ss\n") ? ft_ss(a, b) : 0;
		!ft_strcmp(str[i], "pa\n") ? ft_pa(&a, &b, &begina, &beginb) : 0;
		!ft_strcmp(str[i], "pb\n") ? ft_pb(&a, &b, &begina, &beginb) : 0;
		!ft_strcmp(str[i], "ra\n") ? ft_ra(&a, &begina) : 0;
		!ft_strcmp(str[i], "rb\n") ? ft_rb(&b, &beginb) : 0;
		!ft_strcmp(str[i], "rr\n") ? ft_rr(&a, &b, &begina, &beginb) : 0;
		!ft_strcmp(str[i], "rra\n") ? ft_rra(&a, &begina) : 0;
		!ft_strcmp(str[i], "rrb\n") ? ft_rrb(&b, &beginb) : 0;
		!ft_strcmp(str[i], "rrr\n") ? ft_rrr(&a, &b, &begina, &beginb) : 0;
	}
	ft_checker_b(beginb, begina, str);
	return (begina);
}

static t_check	*ft_apply_v(char **str, t_check *a, t_check *begina,
	t_check *beginb)
{
	t_check		*b;
	int			i;

	b = NULL;
	beginb = b;
	i = -1;
	while (str[++i][0] != 0)
	{
		ft_display(begina, beginb, str[i]);
		!ft_strcmp(str[i], "sa\n") ? ft_sa(a) : 0;
		!ft_strcmp(str[i], "sb\n") ? ft_sb(b) : 0;
		!ft_strcmp(str[i], "ss\n") ? ft_ss(a, b) : 0;
		!ft_strcmp(str[i], "pa\n") ? ft_pa(&a, &b, &begina, &beginb) : 0;
		!ft_strcmp(str[i], "pb\n") ? ft_pb(&a, &b, &begina, &beginb) : 0;
		!ft_strcmp(str[i], "ra\n") ? ft_ra(&a, &begina) : 0;
		!ft_strcmp(str[i], "rb\n") ? ft_rb(&b, &beginb) : 0;
		!ft_strcmp(str[i], "rr\n") ? ft_rr(&a, &b, &begina, &beginb) : 0;
		!ft_strcmp(str[i], "rra\n") ? ft_rra(&a, &begina) : 0;
		!ft_strcmp(str[i], "rrb\n") ? ft_rrb(&b, &beginb) : 0;
		!ft_strcmp(str[i], "rrr\n") ? ft_rrr(&a, &b, &begina, &beginb) : 0;
	}
	ft_display(begina, beginb, str[i]);
	ft_checker_b(beginb, begina, str);
	return (begina);
}

t_check			*ft_read_inst(t_check *a, char **str, int choix)
{
	t_check		*begina;
	t_check		*beginb;

	beginb = NULL;
	begina = a;
	a = (choix == 0 ? ft_apply(str, a, begina, beginb)
		: ft_apply_v(str, a, begina, beginb));
	return (a);
}
