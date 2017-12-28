#ifndef BPGENERATEKEY_H
#define BPGENERATEKEY_H
#include <list>
#include <string>
#include <map>
#include "keynode/keynode.h"
class BPGenerateKey
{

    typedef std::map<std::string,bool> OptionsDict;


public:

    BPGenerateKey(const std::list<std::string> & _words, int _idx, const std::string _passphrase = "");

    void printBitcoin(void);
    void printBitcoin_Testnet(void);
    void printLitecoin(void);

private:

    std::string iToString(uint32_t i);
    void visit(const KeyNode &keyNode, const std::string &chainName);
    void outputString(const std::string &str);


private:

//    KeyNode rootKey_;

    bytes_t byteSeed_;
    KeyNode rootKeyNode_;
    int idx_;
};

#endif // BPGENERATEKEY_H
