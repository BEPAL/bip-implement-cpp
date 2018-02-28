#include "bpgeneratekey.h"

#include <iostream>
#include <sstream>

#include "crypto/mnemoniccode.h"
#include "keynode/CoinClasses/Base58Check.h"

BPGenerateKey::BPGenerateKey(const std::list<std::string> &words, int _idx,
                             const std::string _passphrase)
    :idx_(_idx)
{
    byteSeed_ = MnemonicCode::toSeed(words, _passphrase);

    KeyNodeSeed keyNodeSeed(byteSeed_);
    bytes_t k = keyNodeSeed.getMasterKey();
    bytes_t c = keyNodeSeed.getMasterChainCode();
    rootKeyNode_ = KeyNode(k, c);
}


void BPGenerateKey::printBitcoin(void) {
    // get bitcoin node
    KeyNode key_node = rootKeyNode_[KeyNode::CoinType::Bitcoin];

    // print node information
    outputString("------------------------------------");
    outputString("* Bitcoin ");
    visit(key_node[idx_],iToString(idx_));
}

void BPGenerateKey::printBitcoin_Testnet(void) {
    // get bitcoin node
    KeyNode key_node = rootKeyNode_[KeyNode::CoinType::Bitcoin_Testnet];

    // print node information
    outputString("------------------------------------");
    outputString("* Bitcoin Testnet ");
    visit(key_node[idx_],iToString(idx_));
}

void BPGenerateKey::printLitecoin(void) {
    // get bitcoin node
    KeyNode key_node = rootKeyNode_[KeyNode::CoinType::Litecoin];

    // print node information
    outputString("------------------------------------");
    outputString("* Litecoin ");
    visit(key_node[idx_],iToString(idx_));
}


std::string BPGenerateKey::iToString(uint32_t i) {
    std::stringstream ss;
    ss << (0x7fffffff & i);
    if (i&0x80000000) { ss << "'"; }
    return ss.str();
}
void BPGenerateKey::visit(const KeyNode& keyNode, const std::string& chainName) {

    outputString("* KeyNode [Chain " + chainName + "]");
    if (keyNode.isPrivate()) {
        KeyNode keyNodePub= keyNode.getPublic();
        outputString("  * ext pub:  " + toBase58Check(keyNodePub.extkey()));
        outputString("  * ext prv:  " + toBase58Check(keyNode.extkey()));
        outputString("  * priv key: " + keyNode.privkey());
        outputString("  * address:  " + keyNode.address());

    } else {
        outputString("  * ext pub:  " + toBase58Check(keyNode.extkey()));
        outputString("  * address:  " + keyNode.address());
    }
}

void BPGenerateKey::outputString(const std::string& str) {
    Logger::log(str);
}
