////////////////////////////////////////////////////////////////////////////////
//
// keytreeutil.h
//
// Copyright (c) 2013-2014 Tim Lee
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

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
