#pragma once

#include <vector>
#include <string>

// Data structure for source code files ".jord"
struct Source {
    std::string path; // includes data like file name and where it is located
    std::string text; // complete text of file in one string
    std::vector<std::string> lines; // separates individual lines in vector for error displaying
};