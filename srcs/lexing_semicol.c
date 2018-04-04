/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_semicol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:15:05 by acauchy           #+#    #+#             */
/*   Updated: 2018/04/04 14:16:42 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astest.h"

void	lex_semicol_word(char *cmdline,
		t_word **wordlist, t_lexdata *lexdata)
{
	(void)cmdline;
	lexdata->buff[lexdata->j] = '\0';
	lexdata->j = 0;
	if (ft_strlen(lexdata->buff) > 0)
		add_word(lexdata->buff, wordlist);
	add_word(";", wordlist);
}
