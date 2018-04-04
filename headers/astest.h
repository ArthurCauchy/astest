#ifndef __ASTEST_H
# define __ASTEST_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

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

typedef enum	e_token
{
	ARG,
	AND,
	OR,
	PIPE
}				t_token;

typedef struct	s_ast
{
	t_token			token;
	t_word			*arglist;
	struct s_ast	*parent;
	struct s_ast	*right;
	struct s_ast	*left;
}				t_ast;

/*
** utils.c
*/

void	exit_error(char *errmsg);

/*
** word.c
*/

t_word	*new_word(char *str);

/*
** lexing.c, lexing_[token].c
*/

int		lex_is_separator(char c);
void	add_word(char *str, t_word **wordlist);
void	lex_analysis(char *cmdline, t_word **wordlist);
void	lex_semicol_word(char *cmdline, t_word **wordlist, t_lexdata *lexdata);
void	lex_space_word(char *cmdline, t_word **wordlist, t_lexdata *lexdata);
void	lex_amp_and_word(char *cmdline, t_word **wordlist, t_lexdata *lexdata);
void	lex_pipe_or_word(char *cmdline, t_word **wordlist, t_lexdata *lexdata);

/*
** parsing.c
*/

void	syntax_analysis(t_word *wordlist, t_ast **root);

#endif
