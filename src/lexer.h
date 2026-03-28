#pragma once

#include "token.h"
#include "error.h"
#include <regex>
#include <vector>
#include <queue>

class Lexer {
private:
    const Source& source;

    unsigned int cursorLine = 1;
    unsigned int cursorCol = 1;


    std::queue<Error> errors;

public:
    Lexer(const Source& source);
    // Complete list of tokens from lexically analyzied source code file
    std::vector<Token> tokens;

    std::vector<Token> tokenize();

    void printTokens() const;
    void handleErrors();
};