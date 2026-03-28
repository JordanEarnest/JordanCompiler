#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "color.h"


class Log {
public:
    static void info(const std::string& msg);
    static void info(const std::string& filePath, const std::string& msg);
    static void info(const std::string& filePath, int line, int col, const std::string& msg);
    static void warning(const std::string& filePath, const std::string& msg);
    static void warning(const std::string& filePath, int line, int col, const std::string& msg);
    static void error(const std::string& msg);
    static void error(const std::string& filePath, const std::string& msg);
    static void error(const std::string& filePath, int line, int col, const std::string& msg);
};