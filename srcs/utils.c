/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 13:55:26 by acauchy           #+#    #+#             */
/*   Updated: 2018/04/02 13:55:30 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astest.h"

void	exit_error(char *errmsg)
{
	if (errmsg)
	{
		ft_putendl_fd(errmsg, 2);
	}
	else
		ft_putendl_fd("Error.", 2);
	exit(1);
}
