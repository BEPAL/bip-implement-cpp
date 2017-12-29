#include "keytreeutil.h"
#include <sstream>

namespace KeyTreeUtil {

    uchar_vector sha256Rounds(const uchar_vector& data, uint64_t rounds) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, &data[0], data.size());
        SHA256_Final(hash, &sha256);
        for (uint64_t i = 0; i < rounds - 1; i++) {
            SHA256_Init(&sha256);
            SHA256_Update(&sha256, hash, SHA256_DIGEST_LENGTH);
            SHA256_Final(hash, &sha256);
        }
        
        uchar_vector rval(hash, SHA256_DIGEST_LENGTH);
        return rval;
    }
    
    uchar_vector extKeyBase58OrHexToBytes(const std::string& extKey) {
        uchar_vector extendedKey;
        if (isBase58CheckValid(extKey))
            extendedKey = fromBase58ExtKey(extKey);
        else if (StringUtils::isHex(extKey))
            extendedKey = uchar_vector(extKey);
        else
            throw std::runtime_error("Invalid extended key. Extended key must be in base58 or hex form.");
        
        return extendedKey;
    }
    
    uchar_vector fromBase58ExtKey(const std::string& extKey) {
        static unsigned int dummy = 0;
        uchar_vector fillKey;
        fromBase58Check(extKey, fillKey, dummy);
        static const std::string VERSION_BYTE("04");
        return uchar_vector(VERSION_BYTE+fillKey.getHex()); //append VERSION_BYTE to begining
    }
    
    TreeChains parseChainString(const std::string& chainStr, bool isPrivate) {
        TreeChains treeChains;
        
        const std::string s = StringUtils::split(chainStr)[0]; //trim trailing whitespaces
        
        std::deque<std::string> splitChain = StringUtils::split(s, '/');
        
        //account for root node
        treeChains.push_back(IsPrivateNPathRange(true , Range(NODE_IDX_M_FLAG, NODE_IDX_M_FLAG)));
        
        if (splitChain.back() == "") splitChain.pop_back(); // happens if chainStr has '/' at end
        for (std::string& node : splitChain) {
            if (node.back() == '\'') {
                if (! isPrivate) throw std::runtime_error("Invalid chain "+ chainStr+ ",  not private extended key.");
                
                node = node.substr(0,node.length()-1);
                if (node.front() == '(' && node.back() == ')') {
                    IsPrivateNPathRange range = parseRange(node, true);
                    treeChains.push_back(range);
                } else {
                    uint32_t num = toPrime(std::stoi(node));
                    treeChains.push_back(IsPrivateNPathRange(true , Range(num, num)));
                }
            } else {
                if (node.front() == '(' && node.back() == ')') {
                    IsPrivateNPathRange range = parseRange(node, false);
                    treeChains.push_back(range);
                } else {
                    uint32_t num = std::stoi(node);
                    treeChains.push_back(IsPrivateNPathRange(false , Range(num, num)));
                }
            }
        }
        
        return treeChains;
    }
    
    IsPrivateNPathRange parseRange(const std::string node, bool isPrivate) {
        //node must be like (123-9345)
        const std::string minMaxString =  node.substr(1,node.length()-2);
        const std::deque<std::string> minMaxPair = StringUtils::split(minMaxString, '-');
        
        if (minMaxPair.size() != 2)
            throw std::invalid_argument("Invalid arguments.");
        
        uint32_t min = std::stoi(minMaxPair[0]);
        uint32_t max = std::stoi(minMaxPair[1]);
        
        if (isPrivate) {
            return IsPrivateNPathRange(true, Range(min, max));
        } else {
            return IsPrivateNPathRange(false, Range(min, max));
        }
    }
    
    std::string iToString(uint32_t i) {
        std::stringstream ss;
        ss << (0x7fffffff & i);
        if (isPrime(i)) { ss << "'"; }
        return ss.str();
    }

}