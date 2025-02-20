/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:11:09 by oelleaum          #+#    #+#             */
/*   Updated: 2024/11/21 12:34:09 by oelleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*tmp;

	if (lst == NULL)
		return ;
	ptr = *lst;
	while (ptr != NULL)
	{
		tmp = ptr;
		ptr = ptr->next;
		del(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}
