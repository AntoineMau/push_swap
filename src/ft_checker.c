/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:44:09 by anmauffr          #+#    #+#             */
/*   Updated: 2019/02/18 18:06:06 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_checker.h>

int		ft_check_av(char **av)
{
	int		i;

	i = 1;
	while (av[i])
		if (ft_isdigit(av[i]) == 0)
			return (0);
	return (1);
}

int		main(int ac, char **av)
{
	int		ret;
	char	*buf;

	if (ft_check_av(av) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	if ((ret = read(0, buf, 4)) > 0)
	{
		buf[ret] = '\0';
	}
	return (0);
}
