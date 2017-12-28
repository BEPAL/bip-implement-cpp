////////////////////////////////////////////////////////////////////////////////
//
// logger.h
//
// Copyright (c) 2013-2014 Tim Lee
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

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
