
#include <list>
#include <vector>

#include "crypto/mnemoniccode.h"

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
    auto vec = MnemonicCode::toSeed(list_str, std::string(""));

	printf("��������:\n\n");
	std::string pass;
	for (const auto& str : list_str)
		printf("%s", str.c_str());

	printf("\n\n\n��Ӧ��ϣ����:\n\n");


    for (auto uc_data : vec)
        printf("0x%X ", uc_data);
    printf("\n");
    getchar();
    return 0;
}
