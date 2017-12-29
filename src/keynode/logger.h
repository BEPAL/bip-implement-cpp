#ifndef KEYTREE_LOGGER_H
#define KEYTREE_LOGGER_H

#include <iostream>
#include <string>

#define LOGLEVEL_INFO 4
#define LOGLEVEL_DEBUG 3
#define LOGLEVEL_WARNING 2
#define LOGLEVEL_ERROR 1

class Logger {
public:
    static void setLogLevelInfo() {logLevel_ = LOGLEVEL_INFO;}
    static void setLogLevelDebug() {logLevel_ = LOGLEVEL_DEBUG;}
    static void setLogLevelWarning() {logLevel_ = LOGLEVEL_WARNING;}
    static void setLogLevelError() {logLevel_ = LOGLEVEL_ERROR;}
    
    static void info(const std::string& str) {  if (logLevel_ >= LOGLEVEL_INFO) std::cout << str << std::endl;}
    static void warning(const std::string& str) { if (logLevel_ >= LOGLEVEL_DEBUG) std::cout << str << std::endl;}
    static void debug(const std::string& str) {  if (logLevel_ >= LOGLEVEL_WARNING) std::cout << str << std::endl;}
    static void error(const std::string& str) {  if (logLevel_ >= LOGLEVEL_ERROR) std::cout << str << std::endl;}
    static void log(const std::string& str) { std::cout << str << std::endl;}
private:
    static unsigned int logLevel_;
    
};

#endif /* KEYTREE_LOGGER_H */
