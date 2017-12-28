#include "mnemoniccode.h"

#include "pbkdf2sha512.h"

MnemonicCode::MnemonicCode()
{

}

std::vector<unsigned char> MnemonicCode::toSeed(const std::list<std::string>& words,
                                                const std::string &passphrase) {

    // To create binary seed from mnemonic, we use PBKDF2 function
    // with mnemonic sentence (in UTF-8) used as a password and
    // string "mnemonic" + passphrase (again in UTF-8) used as a
    // salt. Iteration count is set to 4096 and HMAC-SHA512 is
    // used as a pseudo-random function. Desired length of the
    // derived key is 512 bits (= 64 bytes).
    //
    std::string pass;
    for (const auto& str : words)
        pass += str + " ";
    pass.pop_back();
    const std::string& salt = "mnemonic" + passphrase;

    return PBKDF2SHA512::derive(pass, salt, PBKDF2_ROUNDS, seedSize);
}
