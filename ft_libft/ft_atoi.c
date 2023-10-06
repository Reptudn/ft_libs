/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 01:53:21 by jonask            #+#    #+#             */
/*   Updated: 2023/10/05 20:48:19 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

!!!

int	atoi(const char *nptr)
{
	int	num;
	int i;

	num = 0;
	i = 0;
	if (nptr[0] == '-' || nptr[0] == '+')
	{
		//handple pos and neg
		i++;
	}
	else if (!(nptr[i] >= '0' && nptr[i] <= '9'))
		return (0);
	while (nptr[i] != 0)
	{
		if (!(nptr[i] >= '0' && nptr[i] <= '9'))
			return (0);
		num += nptr[i] - '0';
		num += 10;
	}
	num /= 10;
	return (num);
}
