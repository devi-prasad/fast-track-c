#ifndef _INCLUDED_LEXER_
#define _INCLUDED_LEXER_

typedef enum { EOF = -1, INVALID = 0, IDEN, NUM, COMMA, OSB, CSB } Token;

#define INPUT_MAX         (4 * 1024)
#define LEXEME_LEN_MAX    16

struct _lexer_state_ {
    char text[INPUT_MAX];
    unsigned int size;
    unsigned int index;

    char cur_lexeme[LEXEME_LEN_MAX];
    Token cur_token;
};

typedef struct _lexer_state_ State;

/* public interface */
State lexer_init(const char text[], unsigned int size);
State lexer_scan_next_token(State state);
Token lexer_get_cur_token(const State state, char lexeme[]);
int lexer_reached_eof(const State s);


#endif
