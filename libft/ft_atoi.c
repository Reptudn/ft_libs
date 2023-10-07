/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 01:53:21 by jonask            #+#    #+#             */
/*   Updated: 2023/10/07 16:57:34 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\v' || c == '\t')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	long	num;
	int i;
	int prefix;

	num = 0;
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
	while (nptr[i] != 0)
	{
		if (!(nptr[i] >= '0' && nptr[i] <= '9'))
			break;
		num += nptr[i] - '0';
		num *= 10;
		i++;
	}
	num /= 10;
	return ((int)num * prefix);
}
