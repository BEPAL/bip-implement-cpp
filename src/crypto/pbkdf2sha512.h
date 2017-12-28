#ifndef PBKDF2SHA512_H
#define PBKDF2SHA512_H

#include <iostream>
#include <vector>

class PBKDF2SHA512
{
public:
    PBKDF2SHA512();

    static std::vector<unsigned char> derive(const std::string &P,
                                             const std::string &S,
                                             int c, int dkLen);

private:

    static std::vector<unsigned char> F(const std::string &P,
                                        const std::string &S,
                                        int c, int i);
};

#endif // PBKDF2SHA512_H
