/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 07:33:07 by jonask            #+#    #+#             */
/*   Updated: 2023/10/12 10:19:35 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*last;
	t_list	*curr;

	last = *lst;
	while (last->next != 0)
	{
		curr = last;
		last = last->next;
		ft_lstdelone(curr, del);
	}
	free(lst);
	lst = 0;
}
