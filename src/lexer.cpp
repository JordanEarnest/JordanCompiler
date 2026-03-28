#include "lexer.h"
#include "error.h"

Lexer::Lexer(const Source& source) : source(source) {}

std::vector<Token> Lexer::tokenize() {
    // tokenize and read through file
    size_t lengthFile = source.text.length();

    std::regex keywordPattern(R"(\b(use|let|int|float|if|else)\b)");
    std::regex identifierPattern(R"(\b[a-zA-Z][a-zA-Z0-9]*\b)");
    std::regex operatorPattern(R"(\+{1,2}|\-{1,2}|\*{1,2}|\/|\={1,2}|(<=)|(>=)|\>|\<)");
    std::regex separatorPattern(R"([(){};])");
    std::regex floatLiteralPattern(R"(\d+\.\d+)"); 
    std::regex intLiteralPattern(R"(\b\d+\b)");
    std::regex commentPattern(R"(//[^\n]*)"); // excludes new lines

    // absolute index correlated with string of source
    size_t pos = 0;

    std::smatch match;

    auto start = source.text.cbegin() + pos;
    
    while (pos < lengthFile) {
        start = source.text.cbegin() + pos;

        //Log::info(std::to_string(source[pos]));
        
        // NEW LINES, before whitespace since whitespace consumes new lines
        if (source.text[pos] == '\n') {
            cursorLine++;
            cursorCol = 1;
            pos++;
        } 
        // WHITESPACES
        else if(isspace(source.text[pos])) {
            cursorCol++;
            pos++;
        }
        // COMMENTS
        else if (std::regex_search(start, source.text.cend(), match, commentPattern) && match.position() == 0) {
            std::string lexeme = match.str();
            // skip past and ignore
            cursorCol += lexeme.length();
            pos += lexeme.length();
        }
        // KEYWORDS
        else if (std::regex_search(start, source.text.cend(), match, keywordPattern) && match.position() == 0) {
            std::string lexeme = match.str();

            // Go through all types of keywords
            if (lexeme == "let") {
                tokens.push_back(Token(TokenType::LET, lexeme, cursorLine, cursorCol));
            } 
            else if (lexeme == "int") {
                tokens.push_back(Token(TokenType::INT, lexeme, cursorLine, cursorCol));
            }
            else if (lexeme == "float") {
                tokens.push_back(Token(TokenType::FLOAT, lexeme, cursorLine, cursorCol));
            }
            else if (lexeme == "if") {
                tokens.push_back(Token(TokenType::IF, lexeme, cursorLine, cursorCol));
            }
            else if (lexeme == "else") {
                tokens.push_back(Token(TokenType::ELSE, lexeme, cursorLine, cursorCol));
            }
            cursorCol += lexeme.length();
            pos += lexeme.length();
        }
        // SEPARATORS
        else if (std::regex_search(start, source.text.cend(), match, separatorPattern) && match.position() == 0) {
            std::string lexeme = match.str();
            // Go through all types of keywords
            if (lexeme == "(") {
                tokens.push_back(Token(TokenType::OPEN_PARANTHESES, lexeme, cursorLine, cursorCol));
            } 
            else if (lexeme == ")") {
                tokens.push_back(Token(TokenType::CLOSING_PARANTHESES, lexeme, cursorLine, cursorCol));
            }
            else if (lexeme == "{") {
                tokens.push_back(Token(TokenType::OPEN_BRACE, lexeme, cursorLine, cursorCol));
            }
            else if (lexeme == "}") {
                tokens.push_back(Token(TokenType::CLOSING_BRACE, lexeme, cursorLine, cursorCol));
            }
            else if (lexeme == ";") {
                tokens.push_back(Token(TokenType::SEMICOLON, lexeme, cursorLine, cursorCol));
            }
            cursorCol += lexeme.length();
            pos += lexeme.length();
        }
        // IDENTIFIERS
        else if (std::regex_search(start, source.text.cend(), match, identifierPattern) && match.position() == 0) {
            std::string lexeme = match.str();
            tokens.push_back(Token(TokenType::IDENTIFIER, lexeme, cursorLine, cursorCol));

            cursorCol += lexeme.length();
            pos += lexeme.length();
        }
        // OPERATORS
        else if (std::regex_search(start, source.text.cend(), match, operatorPattern) && match.position() == 0) {
            std::string lexeme = match.str();
            // Go through all types of keywords
            if (lexeme == "+") {
                tokens.push_back(Token(TokenType::PLUS, lexeme, cursorLine, cursorCol));
            } 
            else if (lexeme == "++") {
                tokens.push_back(Token(TokenType::INCREMENT, lexeme, cursorLine, cursorCol));
            }
            else if (lexeme == "-") {
                tokens.push_back(Token(TokenType::MINUS, lexeme, cursorLine, cursorCol));
            }
            else if (lexeme == "--") {
                tokens.push_back(Token(TokenType::DECREMENT, lexeme, cursorLine, cursorCol));
            }
            else if (lexeme == "*") {
                tokens.push_back(Token(TokenType::MULTIPLY, lexeme, cursorLine, cursorCol));
            }
            else if (lexeme == "**") {
                tokens.push_back(Token(TokenType::POWER, lexeme, cursorLine, cursorCol));
            }
            else if (lexeme == "/") {
                tokens.push_back(Token(TokenType::DIVIDE, lexeme, cursorLine, cursorCol));
            }
            else if (lexeme == "=") {
                tokens.push_back(Token(TokenType::ASSIGNMENT, lexeme, cursorLine, cursorCol));
            }
            else if (lexeme == "==") {
                tokens.push_back(Token(TokenType::EQUALS, lexeme, cursorLine, cursorCol));
            }
            else if (lexeme == "<") {
                tokens.push_back(Token(TokenType::LESS_THAN, lexeme, cursorLine, cursorCol));
            }
            else if (lexeme == ">") {
                tokens.push_back(Token(TokenType::GREATER_THAN, lexeme, cursorLine, cursorCol));
            }
            else if (lexeme == "<=") {
                tokens.push_back(Token(TokenType::LESS_THAN_EQUAL, lexeme, cursorLine, cursorCol));
            }
            else if (lexeme == ">=") {
                tokens.push_back(Token(TokenType::GREATER_THAN_EQUAL, lexeme, cursorLine, cursorCol));
            }
            cursorCol += lexeme.length();
            pos += lexeme.length();
        }
        // LITERALS
        // FLOAT LITERAL
        else if (std::regex_search(start, source.text.cend(), match, floatLiteralPattern) && match.position() == 0) {
            std::string lexeme = match.str();
            tokens.push_back(Token(TokenType::FLOAT_LITERAL, lexeme, cursorLine, cursorCol));

            cursorCol += lexeme.length();
            pos += lexeme.length();
        }
        // INT LITERAL
        else if (std::regex_search(start, source.text.cend(), match, intLiteralPattern) && match.position() == 0) {
            std::string lexeme = match.str();
            tokens.push_back(Token(TokenType::INT_LITERAL, lexeme, cursorLine, cursorCol));

            cursorCol += lexeme.length();
            pos += lexeme.length();
        }
        else {
            // ERROR MANAGING, could not find token, probably not recognized character
            //std::string errorLine = source.text.substr((cursorLine - 1));
            errors.push(Error(ErrorType::LEXER_UNEXPECTED_CHARACTER, source, cursorLine, cursorCol, std::string(1, source.text[pos])));
            cursorCol += 1;
            pos += 1;
        }
    }
    return tokens;
}

void Lexer::printTokens() const {
    // for (int i = 0; i < tokens.size(); i++) {
    //     Log::info("Token " + std::to_string(i) + ": " + tokens[i].toString());
    // }
}

void Lexer::handleErrors() {
    while (!errors.empty()) {
        errors.front().print();
        errors.pop();
    }
}