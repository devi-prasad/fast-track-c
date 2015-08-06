#include <string.h>
#include <ctype.h>
#include "lexer.h"

/*
 * creates a new lexer state object.
 * 'text' is the input and 'size' is the number of characters in the input.
 *
 */
State lexer_init(const char text[], unsigned int size)
{
    State st;

    memset(&st, 0, sizeof(st));
    strncpy(st.text, text, size);
    st.size = size;
    st.index = 0;
    st.cur_token = INVALID;

    return st;
}


/*
 * a simple check to see if we have reached the end of the input.
 *
 */
int lexer_reached_eof(const State st)
{
    return st.size == st.index;
}


/*
 * skips white spaces. Doesn't keep a running count of newlines.
 * moves 'index' past all white spaces from the current offset. 
 *
 * NOTE: this is an internal function. Therefore, is declared 'static'.
 *
 */
static State _lexer_eat_white_spaces_(State st)
{
    unsigned int i = st.index;
    unsigned int size = st.size;

    while (i < size) {
        char c = st.text[i];
        if (c == ' ' || c == '\n' || c == '\t') {
        	++i;
        	continue;
        }
        break;
    }

    st.index = i;

    return st;
}

/*
 * precondition: on entry s.index < s.size
 * scans either a positive number or an identifier.
 *
 * NOTE: an internal function. Therefore, declared 'static'.
 */
static State _lex_scan_iden_or_number_(State st)
{
	unsigned int i = st.index;
	unsigned int j = 0;
    unsigned int size = st.size;
    Token tok = INVALID;
    
    if (isdigit(st.text[i])) {
        while (i < size && isdigit(st.text[i])) {
        	st.cur_lexeme[j] = st.text[i];
        	++i, ++j;
        }
        tok = NUM;
    } else if (isalpha(st.text[i])) {
        while (i < size && isalnum(st.text[i])) {
            st.cur_lexeme[j] = st.text[i];
            ++i, ++j;
        }
        tok = IDEN;
    }

    st.cur_lexeme[j] = '\0';
    st.index = i;
    st.cur_token = tok;

    return st;
}

/*
 * scans a COMMA, OSB, CSB, IDEN or a NUM.
 * recognizes EOF condition and records it in the lexer state.
 * stores the lexeme too in the state object.
 *
 */
State lexer_scan_next_token(State st)
{
    st = _lexer_eat_white_spaces_(st);
    
    if (lexer_reached_eof(st)) {
        st.cur_token = EOF;
        st.cur_lexeme[0] = '\0'; /* TODO: clear the entire string */
    } else {
    	unsigned int i = st.index;
        switch (st.text[i]) {
            case '[' :
              st.cur_token = OSB;
              st.cur_lexeme[0] = '['; st.cur_lexeme[1] = '\0';
              ++st.index;
              break;
            case ']' :
              st.cur_token = CSB; 
              st.cur_lexeme[0] = ']'; st.cur_lexeme[1] = '\0';
              ++st.index;
              break;
            case ',' :
              st.cur_token = COMMA;
              st.cur_lexeme[0] = ','; st.cur_lexeme[1] = '\0';
              ++st.index;
              break;
            default:
              st = _lex_scan_iden_or_number_(st);
              break;
        }
    }

    return st;
}

/*
 * precondition: 'lexeme' has room for LEXEME_LEN_MAX characters
 * a simple getter function. copies current lexeme into 'lexeme'.
 * returns the current token.
 *
 */
Token lexer_get_cur_token(const State st, char lexeme[])
{
    if (st.cur_token != EOF && st.cur_token != INVALID) {
        strncpy(lexeme, st.cur_lexeme, LEXEME_LEN_MAX - 1);
        lexeme[LEXEME_LEN_MAX - 1] = '\0';
    }

    return st.cur_token;
}
