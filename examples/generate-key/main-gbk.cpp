
#include "bpgeneratekey.h"

int main(void) {

    std::list<std::string> list_str;
    list_str.push_back("一");
    list_str.push_back("二");
    list_str.push_back("三");
    list_str.push_back("四");
    list_str.push_back("五");
    list_str.push_back("六");
    list_str.push_back("七");
    list_str.push_back("八");
    list_str.push_back("九");
    list_str.push_back("十");
    list_str.push_back("一");
    list_str.push_back("一");
    BPGenerateKey gk(list_str,0);
    gk.printBitcoin();
    gk.printBitcoin_Testnet();
    gk.printLitecoin();

    getchar();

    return 0;
}
