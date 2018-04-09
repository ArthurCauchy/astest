/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_amp_and.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:15:05 by acauchy           #+#    #+#             */
/*   Updated: 2018/04/09 10:12:10 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astest.h"

void	lex_amp_and_word(char *cmdline,
		t_word **wordlist, t_lexdata *lexdata)
{
	lexdata->buff[lexdata->j] = '\0';
	lexdata->j = 0;
	if (ft_strlen(lexdata->buff) > 0)
		add_word(lexdata->buff, wordlist);
	if (cmdline[lexdata->i + 1] == '&')
	{
		add_word("&&", wordlist);
		++lexdata->i;
	}
	else
		add_word("&", wordlist);
}
