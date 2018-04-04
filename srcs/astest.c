/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astest.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 13:56:56 by acauchy           #+#    #+#             */
/*   Updated: 2018/04/04 13:49:56 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astest.h"

int				main(void)
{
	char	buff[4096];
	int		size_read;
	t_word	*wordlist;
	//t_ast	*ast;

	wordlist = NULL;
	//ast = NULL;
	while ((size_read = read(0, buff, 4095)))
	{
		buff[size_read] = '\0';
		if (buff[size_read - 1] == '\n')
			buff[size_read - 1] = '\0';
		if (ft_strlen(buff) == 0)
			break;
		lex_analysis(buff, &wordlist);

		//test
		t_word	*cur = wordlist;
		while (cur)
		{
			ft_fminiprint(1, "\"%l0s%\"\n", cur->str);
			cur = cur->next;
		}

		//endtest
	}
	return (0);
}
