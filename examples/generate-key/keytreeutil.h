#ifndef KEYTREE_KEYTREEUTIL_H
#define KEYTREE_KEYTREEUTIL_H

#include <deque>
#include <map>
#include "keynode/keynode.h"
#include "keynode/logger.h"
#include "keynode/CoinClasses/Base58Check.h"

typedef std::pair<uint64_t,uint64_t> Range;
typedef std::pair<bool,Range> IsPrivateNPathRange; // < isPrivate, <min,max> >
typedef std::deque<IsPrivateNPathRange> TreeChains;
typedef std::map<std::string,bool> OptionsDict;

namespace TreeTraversal {
    enum Type {
        preorder,
        postorder,
        levelorder
    };
}

namespace KeyTreeUtil
{
    const uint64_t NODE_IDX_M_FLAG = uint64_t(std::numeric_limits<uint64_t>::max());
    const std::string MASTER_NODE_LOWERCASE_M = "m";
    const std::string LEAD_CHAIN_PATH = "___";
    
    uchar_vector sha256Rounds(const uchar_vector& data, uint64_t rounds);
    TreeChains parseChainString(const std::string& chainStr, bool isPrivate = true);
    std::string iToString(uint32_t i);
    uchar_vector extKeyBase58OrHexToBytes(const std::string& extKey);
    uchar_vector fromBase58ExtKey(const std::string& extKey);
    inline uint32_t toPrime(uint32_t i) { return 0x80000000 | i; }
    inline uint32_t removePrime(uint32_t i) { return 0x7fffffff & i; }
    inline bool isPrime(uint32_t i) { return 0x80000000 & i; }
    IsPrivateNPathRange parseRange(const std::string node, bool isPrivate);
}


#endif /* KEYTREE_KEYTREEUTIL_H */
