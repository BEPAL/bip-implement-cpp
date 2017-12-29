#include "pbkdf2sha512.h"

#include <math.h>
#include <algorithm>
#include <exception>

#include "hmac_sha512.h"

PBKDF2SHA512::PBKDF2SHA512()
{

}

std::vector<unsigned char> PBKDF2SHA512::derive(const std::string & P,
                                                const std::string & S,
                                                int c, int dkLen) {
    std::vector<unsigned char> baos;
    try {
        int hLen = 20;

        if (dkLen > ((pow(2, 32)) - 1) * hLen) {
            throw "derived key too long";
        }
        else {
            int l = (int)ceil((double)dkLen / (double)hLen);

            for (int i = 1; i <= l; i++) {
                std::vector<unsigned char> T = F(P, S, c, i);
                baos.insert(baos.end(), T.begin(), T.end());
            }
        }
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
        throw ex;
    }

    baos.resize(dkLen);
    return baos;
}


std::vector<unsigned char> PBKDF2SHA512::F(const std::string & P,
                                           const std::string& /*S*/,
                                           int c, int/* i*/) {
    std::vector<unsigned char> U_LAST;
    std::vector<unsigned char> U_XOR(64,0);


    for (int j = 0; j < c; j++) {
        CHMAC_SHA512 mac((unsigned char*)P.c_str(), P.length());
        if (j == 0) {
//            std::vector<unsigned char> baS(S.begin(), S.end());
//            std::vector<unsigned char> baI(sizeof(i), 0);
//            memcpy(&baI[0], &i, sizeof(i));
//            std::reverse(baI.begin(), baI.end());
//            std::vector<unsigned char> baU(baS.size() + baI.size() + 1, 0);

//            baU.insert(baU.begin(), baS.begin(), baS.end());
//            baU.insert(baU.end(), baI.begin(), baI.end());

            mac.Write(U_LAST.data(), U_LAST.size()).Finalize(&U_XOR[0]);
            U_LAST = U_XOR;
        }
        else {
            std::vector<unsigned char> baU(64,0);
            mac.Write(U_LAST.data(), U_LAST.size()).Finalize(&baU[0]);

            for (size_t k = 0; k < U_XOR.size(); k++) {
                U_XOR[k] = (unsigned char)(U_XOR[k] ^ baU[k]);
            }

            U_LAST = baU;
        }
    }

    return U_XOR;
}
