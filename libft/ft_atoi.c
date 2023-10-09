/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 01:53:21 by jonask            #+#    #+#             */
/*   Updated: 2023/10/09 10:51:33 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\t' || c == '\a' || c == '\b')
		return (1);
	return (0);
}

static int	get_num(const char *nptr, int i)
{
	long	num;

	while (nptr[i] != 0)
	{
		if (!(nptr[i] >= '0' && nptr[i] <= '9'))
			break ;
		num += nptr[i] - '0';
		num *= 10;
		i++;
	}
	num /= 10;
	return ((int)num);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		prefix;

	i = 0;
	prefix = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			prefix = -1;
		i++;
	}
	if (!(nptr[i] >= '0' && nptr[i] <= '9'))
		return (0);
	return (get_num(nptr, i) * prefix);
}
