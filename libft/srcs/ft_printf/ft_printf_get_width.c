/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_width.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:03:49 by anmauffr          #+#    #+#             */
/*   Updated: 2019/03/05 21:03:50 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftprintf.h>

void			ft_printf_get_champ(t_printf *p, const char *format)
{
	__int32_t	i;
	__int32_t	tmp;
	__int8_t	tmp_intmax_buffer;

	i = 0;
	tmp = ft_atoi(&format[p->index]);
	tmp_intmax_buffer = format[p->index];
	while (ft_isdigit(format[p->index + i]) && i < 11)
		++i;
	while (ft_isdigit(format[p->index]))
		++p->index;
	if (tmp < 0 || i >= 11 || (i == 10 && tmp_intmax_buffer > '2'))
		return ;
	p->champ = tmp;
}
