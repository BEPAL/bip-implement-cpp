
#include "bpgeneratekey.h"

int main(void) {

    std::list<std::string> list_str;
    list_str.push_back("һ");
    list_str.push_back("��");
    list_str.push_back("��");
    list_str.push_back("��");
    list_str.push_back("��");
    list_str.push_back("��");
    list_str.push_back("��");
    list_str.push_back("��");
    list_str.push_back("��");
    list_str.push_back("ʮ");
    list_str.push_back("һ");
    list_str.push_back("һ");
    BPGenerateKey gk(list_str,0);
    gk.printBitcoin();
    gk.printBitcoin_Testnet();
    gk.printLitecoin();

    getchar();

    return 0;
}
