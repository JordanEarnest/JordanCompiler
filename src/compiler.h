/**
 * @file compiler.h
 * @brief Compiles ".jord" files from the Jordan programming language into C, then creates a .exe
 * @author Jordan Earnest
 */
#pragma once

#include <fstream>
#include <vector>
#include "source.h"
#include "lexer.h"
#include "error.h"

class Compiler {
private:
    std::vector<Source> sources; // stores source files to be compiled

    std::queue<Error> errors;

    bool validateFileExtension(std::string& filePath);
public:
    void addSource(const Source& source); // add sources to vector for later compilation

    void compile();
};