#include "compiler.h"

bool Compiler::validateFileExtension(std::string& filePath) {
    return filePath.substr(filePath.rfind('.')) == ".jord"; //rfind starts from right side of string 
}

void Compiler::addSource(const Source& source) {
    sources.push_back(source);
}

void Compiler::compile() {
    if (sources.empty()) {
        // error compilation terminated, no source files
        return;
    }
    Lexer lexer(sources[0]);
    lexer.tokenize();
    lexer.printTokens();
    lexer.handleErrors();
}