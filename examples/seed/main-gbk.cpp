
#include <list>
#include <vector>

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

	printf("密语如下:\n\n");
	std::string pass;
	for (const auto& str : list_str)
		printf("%s", str.c_str());

	printf("\n\n\n对应哈希如下:\n\n");


    for (auto uc_data : vec)
        printf("0x%X ", uc_data);
    printf("\n");
    getchar();
    return 0;
}
