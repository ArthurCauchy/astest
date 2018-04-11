/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter_and.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 11:36:50 by acauchy           #+#    #+#             */
/*   Updated: 2018/04/11 11:39:02 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astest.h"

int	exec_ast_and(t_ast *node)
{
	int	ret1;
	int	ret2;

	ret1 = exec_ast(node->left);
	if (ret1 == 0)
	{
		ret2 = exec_ast(node->right);
		return (ret2);
	}
	return (ret1);
}
