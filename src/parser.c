#include <stdio.h>
#include <stdlib.h>
/* The Language Parsing Library */ 
#include "mpc.h"

/* Windows preprocessor */
#ifdef _WIN32
#include <string.h>

static char buffer[2048];

/* Fake readline function, which will overide the editline function, 
 * So we can use the same main function either way
 * Instead of doing 2 main functions
 */
char* readline(char* prompt)
{
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char* cpy = malloc(strlen(buffer)+1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy)-1] = '\0';
  return cpy;
}

/* Same reason for fake function */
void add_history(char* unused) {}

/* Other wise include the editline headers, and obviously use there functions */
#else
#include <editline/readline.h>
#include <editline/history.h>
#endif

int main(int argc, char** argv)
{
  /* Create Parsers */
  mpc_parser_t* Number   = mpc_new("number");
  mpc_parser_t* Operator = mpc_new("operator");
  mpc_parser_t* Expr     = mpc_new("expr");
  mpc_parser_t* Lfp      = mpc_new("lfp");

  mpca_lang(MPCA_LANG_DEFAULT,
	    "                                                     \
      number   : /-?[0-9]+/ ;					  \
      operator : '+' | '-' | '*' | '/' | '%' | ;                  \
      expr     : <number> | '(' <operator> <expr>+ ')' ;          \
      lfp      : /^/ <operator> <expr>+ /$/ ;                     \
    ",
	    Number, Operator, Expr, Lfp);
  
  puts("LFP Version 0.0.1");
  puts("The Official LFP (Lisp For Pussies) REPL (Read Eval Print Loop)");
  puts("Press Ctrl+c to Exit\n");

  /* REPL Loop */
  while (1)
    {
      char* input = readline("lfp> ");
      add_history(input);

      mpc_result_t r;
      if (mpc_parse("<stdin>", input, Lfp, &r))
	{
	  /* On Success Print The Result */
	  mpc_ast_print(r.output);
	  mpc_ast_delete(r.output);
	}
      else
	{
	  /* Other wise print error */
	  mpc_err_print(r.error);
	  mpc_err_delete(r.error);
	}
      free(input);
    }

  mpc_cleanup(4, Number, Operator, Expr, Lfp);
  return 0;
}
