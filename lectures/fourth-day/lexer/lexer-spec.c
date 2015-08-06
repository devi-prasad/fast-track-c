#include <assert.h>
#include <string.h>
#include "lexer.h"

int main()
{
	{
	  char program[] = "";
	  char lexeme[LEXEME_LEN_MAX] = "";
	  State st = lexer_init(program, strlen(program));
	  assert(lexer_reached_eof(st));
	  st = lexer_scan_next_token(st);
	  assert(lexer_get_cur_token(st, lexeme) == EOF);
	}

	{
	  char program[] = "   \t\n\n\n ";
	  char lexeme[LEXEME_LEN_MAX] = "";
	  State st = lexer_init(program, strlen(program));
	  st = lexer_scan_next_token(st);
	  assert(lexer_get_cur_token(st, lexeme) == EOF);
	  assert(lexer_reached_eof(st));
	}
	
	{
	  char program[] = " mov eax , 10234 ";
	  char lexeme[LEXEME_LEN_MAX] = "";
	  State st = lexer_init(program, strlen(program));
	  st = lexer_scan_next_token(st);
	  assert(!lexer_reached_eof(st));
      
      assert(lexer_get_cur_token(st, lexeme) == IDEN);
      assert(!strcmp(lexeme, "mov"));

      st = lexer_scan_next_token(st);
      assert(lexer_get_cur_token(st, lexeme) == IDEN);
      assert(!strcmp(lexeme, "eax"));

      st = lexer_scan_next_token(st);
      assert(lexer_get_cur_token(st, lexeme) == COMMA);
      assert(!strcmp(lexeme, ","));

      st = lexer_scan_next_token(st);
      assert(lexer_get_cur_token(st, lexeme) == NUM);
      assert(!strcmp(lexeme, "10234"));

	}
	
    {
	    char program[] = " mov eax , 10234\n\n\t push esi\npop ebx\nret\n\n";
		char lexeme[LEXEME_LEN_MAX] = "";
		State st = lexer_init(program, strlen(program));
		
		st = lexer_scan_next_token(st);    /* mov */
		st = lexer_scan_next_token(st);    /* eax */
		st = lexer_scan_next_token(st);    /* , */
		st = lexer_scan_next_token(st);    /* 10234 */
		st = lexer_scan_next_token(st);    /* push */
		st = lexer_scan_next_token(st);    /* esi */
		
		st = lexer_scan_next_token(st);    /* pop */
		lexer_get_cur_token(st, lexeme);
		assert(!strcmp(lexeme, "pop"));

		st = lexer_scan_next_token(st);    /* ebx */
		
		st = lexer_scan_next_token(st);    /* ret */
		lexer_get_cur_token(st, lexeme);
		assert(!strcmp(lexeme, "ret"));

		st = lexer_scan_next_token(st);
		assert(lexer_reached_eof(st));
		st = lexer_scan_next_token(st);
		assert(lexer_get_cur_token(st, lexeme) == EOF);
		st = lexer_scan_next_token(st);
		assert(lexer_get_cur_token(st, lexeme) == EOF);
    }

    return 0;
}