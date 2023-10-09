/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 07:33:07 by jonask            #+#    #+#             */
/*   Updated: 2023/10/09 10:51:59 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*last;
	t_list	*curr;

	while (last->next != 0)
	{
		curr = last;
		last = last->next;
		del(curr);
		free(curr);
		curr = 0;
	}
	free(lst);
	lst = 0;
}
