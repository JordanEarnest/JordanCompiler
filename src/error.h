#pragma once

#include <string>
#include "source.h"

enum class ErrorType {
    // Error during tokenization where no regex match is found
    // Compiler level errors
    COMPILER_INVALID_FILE_EXTENSION,
    // Lexer level errors 
    LEXER_UNEXPECTED_CHARACTER,
};

class Error {
private:
    ErrorType type;
    std::string msg; // later constructed based on ErrorType
    // where the error is located?
    int line;
    int col;
    // Reference to the source file that the error happened in
    const Source& source;

    std::string offendingLexeme;

    void createErrorMessage(ErrorType& type);
public:
    // TODO: question std::string reference for filepath and others
    Error(ErrorType type, const Source& source, int line, int col, std::string offendingLexeme);

    void print();
};