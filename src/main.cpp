#include <iostream>

#include "log.h"
#include "lexer.h"
#include "compiler.h"
#include "source.h"
#include <string>
#include <fstream>
#include <sstream>


int main(int argc, char* argv[]) {
    Compiler compiler; // main object for compiling jordan

    std::string filePath = argv[1];
    std::ifstream sourceFile(filePath);

    if (!sourceFile)
        Log::error(filePath, "file does not exist");


    // read entire file and put in string
    std::stringstream buffer;

    std::string line;
    std::vector<std::string> lines;
    // extract all lines from source code
    while (std::getline(sourceFile, line)) {
        std::cout << "hello!";
        lines.push_back(line);
        buffer << line << '\n'; // new line is excluded with getline 
    }

    std::string sourceCode = buffer.str();

    Source source1{filePath, sourceCode, lines};

    compiler.addSource(source1);
    compiler.compile();

    return 0;
}