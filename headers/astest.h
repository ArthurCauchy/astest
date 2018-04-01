#ifndef __ASTEST_H
# define __ASTEST_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef enum	e_token
{
	ROOT,
	ARG,
	SEMICOL
}				t_token;

typedef struct	s_ast
{
	t_token			token;
	char			*arg;
	struct s_ast	*right;
	struct s_ast	*left;
}				t_ast;

typedef struct	s_lexdata
{
	char	*buff;
	size_t	i;
	size_t	j;
}				t_lexdata;

typedef struct	s_word
{
	char			*str;
	struct s_word	*next;
}				t_word;

/*
** utils.c
*/

void	exit_error(char *errmsg);

/*
** lexing.c
*/

void	lex_analysis(char *cmdline, t_word **wordlist);

#endif
