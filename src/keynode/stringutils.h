#ifndef KEYTREE_STRINGUTILS_H
#define KEYTREE_STRINGUTILS_H

#include <iostream>
#include <deque>

class StringUtils {
public:
    enum StringFormat {hex, base58, ascii};

    //equivalent to python text.split(seperator)
    static std::deque<std::string> split(const std::string& text, char seperator = ' ') {
        size_t pos = text.find(seperator);
        size_t initialPos = 0;
        std::deque<std::string> rtn;
        while (pos != std::string::npos)
        {
            rtn.push_back(text.substr(initialPos, pos - initialPos));
            initialPos = pos + 1;
            pos = text.find(seperator, initialPos);
        }
        rtn.push_back(text.substr(initialPos, std::min((int)pos, (int) text.size()) - initialPos));
        return rtn;
    }
    
    static bool isHex(const std::string& str) {
        return str.find_first_not_of("0123456789abcdefABCDEF") == std::string::npos;
    }
    
    static std::string string_to_hex(const std::string& input) {
        static const char* const lut = "0123456789abcdef";
        size_t len = input.length();
        
        std::string output;
        output.reserve(2 * len);
        for (const unsigned char& c : input) {
            output.push_back(lut[c >> 4]);
            output.push_back(lut[c & 15]);
        }
        return output;
    }
};

#endif /* KEYTREE_STRINGUTILS_H */
