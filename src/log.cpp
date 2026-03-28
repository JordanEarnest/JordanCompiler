#include "log.h"

void Log::info(const std::string& msg) {
    std::cout << Color::BOLD << Color::BRIGHT_CYAN << "note: " << Color::RESET << msg << std::endl;
}
void Log::info(const std::string& filePath, const std::string& msg) {
    std::cout << Color::BOLD << filePath << ": " << Color::BRIGHT_CYAN << "note: " << Color::RESET << msg << std::endl;
}
void Log::info(const std::string& filePath, int line, int col, const std::string& msg) {
    std::cout << Color::BOLD << filePath << ":" << line << ":" << col << ": " << Color::RED << "note: " << Color::RESET << msg << std::endl;
}
void Log::warning(const std::string& filePath, const std::string& msg) {
    std::cout << Color::BOLD << filePath << ": " << Color::YELLOW << "warning: " << Color::RESET << msg << std::endl;
}
void Log::warning(const std::string& filePath, int line, int col, const std::string& msg) {
    std::cout << Color::BOLD << filePath << ":" << line << ":" << col << ": " << Color::RED << "warning: " << Color::RESET << msg << std::endl;
}
void Log::error(const std::string& msg) {
    std::cout << Color::BOLD << Color::RED << "error: " << Color::RESET << msg << std::endl;
}
void Log::error(const std::string& filePath, const std::string& msg) {
    std::cout << Color::BOLD << filePath << ": " << Color::RED << "error: " << Color::RESET << msg << std::endl;
}
void Log::error(const std::string& filePath, int line, int col, const std::string& msg) {
    std::cout << Color::BOLD << filePath << ":" << line << ":" << col << ": " << Color::RED << "error: " << Color::RESET << msg << std::endl;
}