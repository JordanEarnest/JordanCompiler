#include "error.h"
#include "color.h"
#include <sstream>
#include <iostream>
#include <iomanip>


Error::Error(ErrorType type, const Source& source, int line, int col, std::string offendingLexeme) 
    : type(type), source(source), line(line), col(col), offendingLexeme(offendingLexeme) {
    createErrorMessage(type); // set member variable msg to correct error message
}

void Error::createErrorMessage(ErrorType& errorType) {
    std::stringstream errorMessage;
    switch (errorType) {
        // Lexer level errors
        case ErrorType::LEXER_UNEXPECTED_CHARACTER: {
            int length = 0;
            errorMessage << Color::BOLD << source.path << ":" << line << ":" << col << ": " << Color::RED << "error: " << Color::RESET;
            length += source.path.size() + 11 + std::to_string(line).size() + std::to_string(col).size();
            errorMessage << "unexpected character " << Color::BOLD << Color::GREEN << line << " | " << Color::RESET;
            length += 21 + std::to_string(line).size() + 3;
            // paste everything before the unexpected character in green
            errorMessage << Color::BOLD << Color::GREEN << source.lines[line - 1].substr(0, col - 1) << Color::RESET;
            length += source.lines[line - 1].substr(0, col - 1).size();
            errorMessage << Color::BOLD << Color::RED << offendingLexeme << std::endl;
            errorMessage << std::string(length, ' ') << "^" << Color::RESET << std::endl;
            break;
        }
        default: {
            errorMessage << "unknown error" << std::endl;
            break;
        }
    }
    msg = errorMessage.str();
}

void Error::print() {
    std::cout << msg;
}