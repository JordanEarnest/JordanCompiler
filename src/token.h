#pragma once

#include <string>

enum class TokenType {
    IDENTIFIER,

    // KEYWORDS
    LET,
    INT,
    FLOAT,
    IF,
    ELSE,
    
    // LITERALS
    INT_LITERAL,
    FLOAT_LITERAL,

    // OPERATOR
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    POWER, // **
    INCREMENT, // ++
    DECREMENT, // --
    EQUALS, // ==
    ASSIGNMENT, // =
    GREATER_THAN,
    GREATER_THAN_EQUAL,
    LESS_THAN,
    LESS_THAN_EQUAL,

    // SEPARATOR
    OPEN_PARANTHESES, // (
    CLOSING_PARANTHESES, // )
    OPEN_BRACE, // {
    CLOSING_BRACE, // }
    SEMICOLON, // ;

    // END LINE
    END_LINE
};

struct Token {
    TokenType type;
    std::string lexeme;
    int line;
    int col;

    Token(TokenType type, std::string lexeme, int line, int col)
    : type(type), lexeme(lexeme), line(line), col(col) {}

    std::string toString() const {
        std::string typeString;

        switch (type) {
            // KEYWORDS
            case TokenType::LET: typeString = "LET"; break;
            case TokenType::INT: typeString = "INT"; break;
            case TokenType::FLOAT: typeString = "FLOAT"; break;
            case TokenType::IF: typeString = "IF"; break;
            case TokenType::ELSE: typeString = "ELSE"; break;
            case TokenType::IDENTIFIER: typeString = "IDENTIFIER"; break;
            // OPERATORS
            case TokenType::PLUS: typeString = "PLUS"; break;
            case TokenType::INCREMENT: typeString = "INCREMENT"; break;
            case TokenType::MINUS: typeString = "MINUS"; break;
            case TokenType::DECREMENT: typeString = "DECREMENT"; break;
            case TokenType::MULTIPLY: typeString = "MULTIPLY"; break;
            case TokenType::POWER: typeString = "POWER"; break;
            case TokenType::DIVIDE: typeString = "DIVIDE"; break;
            case TokenType::EQUALS: typeString = "EQUALS"; break;
            case TokenType::ASSIGNMENT: typeString = "ASSIGNMENT"; break;
            case TokenType::GREATER_THAN: typeString = "GREATER_THAN"; break;
            case TokenType::GREATER_THAN_EQUAL: typeString = "GREATER_THAN_EQUAL"; break;
            case TokenType::LESS_THAN: typeString = "LESS_THAN"; break;
            case TokenType::LESS_THAN_EQUAL: typeString = "LESS_THAN_EQUAL"; break;
            // SEPARATORS
            case TokenType::OPEN_PARANTHESES: typeString = "OPEN_PARANTHESES"; break;
            case TokenType::CLOSING_PARANTHESES: typeString = "CLOSING_PARANTHESES"; break;
            case TokenType::OPEN_BRACE: typeString = "OPEN_BRACE"; break;
            case TokenType::CLOSING_BRACE: typeString = "CLOSING_BRACE"; break;
            case TokenType::SEMICOLON: typeString = "SEMICOLON"; break;
            // LITERALS
            case TokenType::INT_LITERAL: typeString = "INT_LITERAL"; break;
            case TokenType::FLOAT_LITERAL: typeString = "FLOAT_LITERAL"; break;


            default: typeString = "UNKNOWN"; break;
        }

        return "<" + typeString + ", " + lexeme + ">";
    }
};

