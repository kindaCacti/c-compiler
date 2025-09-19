#ifndef TOKENS
#define TOKENS

enum Tokens{
    //helpers
    _OPEN_PARENTHISIS,
    _CLOSE_PARENTHISIS,
    _OPEN_BRACKET,
    _CLOSE_BRACKET,
    _OPEN_SQUARE_BRACKET,
    _CLOSE_SQUARE_BRACKET,
    // datatypes
    _VOID,
    _SHORT,
    _INT,
    _LONG,
    _CHAR,
    _FLOAT,
    _DOUBLE,
    _AUTO,
    _REGISTER,
    _SIGNED,
    _UNSIGNED,
    _VOLATILE,
    _CONST,
    _EXTERN,
    _STATIC,
    // conditionals
    _IF,
    _ELSE,
    _SWITCH,
    _DEFAULT,
    _BREAK,
    _EQ_EQ_SIGN,
    _LT_SIGN,
    _GT_SIGN,
    _LT_EQ_SIGN,
    _GT_EQ_SIGN,
    _PIPE_PIPE_SIGN,
    _AND_AND_SIGN,
    // loops
    _GOTO,
    _WHILE,
    _FOR,
    _DO,
    // aritmetic
    _PLUS_SIGN,
    _MINUS_SIGN,
    _STAR_SIGN,
    _SLASH_SIGN,
    _PIPE_SIGN,
    _AND_SIGN,
    _ROOF_SIGN,
    _EXCLAM_SIGN,
    _EQ_SIGN,
    _PLUS_EQ_SIGN,
    _MINUS_EQ_SIGN,
    _STAR_EQ_SIGN,
    _SLASH_EQ_SIGN,
    _PIPE_EQ_SIGN,
    _AND_EQ_SIGN,
    _ROOF_EQ_SIGN,
    // other keywords
    _STRUCT,
    _UNION,
    _TYPEDEF,
    _ENUM,
    // identifiers
    _IDENTIFIER
};

#endif