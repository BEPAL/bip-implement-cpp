
#include <list>
#include <vector>

#ifdef QT_PROJECT
#include <QDebug>
#include <QString>
#endif

#include "crypto/mnemoniccode.h"

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
    auto vec = MnemonicCode::toSeed(list_str, std::string(""));

#ifdef QDEBUG_H
    QString qstr_crypto;
    for (auto crypto: list_str)
        qstr_crypto += QString::fromUtf8(crypto.c_str());
    qDebug() << qstr_crypto;
#endif


    for (auto uc_data : vec)
        printf("0x%X ", uc_data);
    printf("\n");
    getchar();
    return 0;
}
