#include "keynode.h"
#include "CoinClasses/Base58Check.h"
#include "logger.h"

KeyNode::KeyNode(const bytes_t& key, const bytes_t& chain_code, uint32_t child_num, uint32_t parent_fp, uint32_t depth)
: Coin::HDKeychain(key, chain_code, child_num, parent_fp, depth) {}

KeyNode::KeyNode(const bytes_t& extkey) : Coin::HDKeychain(extkey) {}

KeyNode::KeyNode( const KeyNode& other ) : Coin::HDKeychain() {
    valid_ = other.valid_;
    if (!valid_) return;
    
    version_ = other.version_;
    depth_ = other.depth_;
    parent_fp_ = other.parent_fp_;
    child_num_ = other.child_num_;
    chain_code_ = other.chain_code_;
    key_ = other.key_;
    Coin::HDKeychain::updatePubkey();
}

KeyNode KeyNode::getChild(uint32_t i) const {
    KeyNode ret(Coin::HDKeychain::getChild(i).extkey());
    return ret;
}

KeyNode KeyNode::getPublic() const {
    KeyNode ret(Coin::HDKeychain::getPublic().extkey());
    return ret;
}

std::string KeyNode::privkey() const {
    if(this->isPrivate()) {
        uchar_vector k = this->key();
        k = k.getHex().substr(2);
        return KeyNode::secretToASecret(k, true);
    }
    return "";
}

std::string KeyNode::privkey(bool compressed) const {
    if(this->isPrivate()) {
        uchar_vector k = this->key();
        k = k.getHex().substr(2);
        return KeyNode::secretToASecret(k, compressed);
    }
    return "";
}

std::string KeyNode::address() const {
    uchar_vector K = this->pubkey();
    return KeyNode::publicKeyToAddress(K);
}

std::string KeyNode::address(bool compressed) const {
    if (compressed){
        return KeyNode::publicKeyToAddress(this->pubkey());
    } else {
        return KeyNode::publicKeyToAddress(this->pubkeyUncompressed());
    }
}

uchar_vector KeyNode::hash160(const uchar_vector& public_key) {
    return mdsha(public_key);
}

std::string KeyNode::publicKeyToAddress(const uchar_vector& public_key) {
    uchar_vector h160 = KeyNode::hash160(public_key);
    return KeyNode::hash160ToAddress(h160, address_prefix_);
}

std::string KeyNode::hash160ToAddress(const uchar_vector& h160, uint8_t addrtype) {
    uchar_vector vh160;
    vh160.push_back(addrtype);
    vh160 += h160;
    return toBase58Check(vh160);
}

std::string KeyNode::encodeBase58Check(const uchar_vector& vchIn) {
    return toBase58Check(vchIn);
}

std::string KeyNode::secretToASecret(const uchar_vector& secret, bool compressed) {
    uchar_vector vchIn;
    vchIn.push_back(private_key_prefix_);
    vchIn += secret;
    if (compressed) vchIn.push_back(0x01); // add compressed flag
    
    return encodeBase58Check(vchIn);
}

void KeyNode::setTestNet(bool enabled) {
    if (enabled) {
        Coin::HDKeychain::setVersions(0x04358394, 0x043587CF);
        address_prefix_ = 0x6F;
        private_key_prefix_ = 0xEF;
    }
    else {
       Coin::HDKeychain::setVersions(0x0488ADE4, 0x0488B21E);
        address_prefix_ = 0x00;
        private_key_prefix_ = 0x80;
    }
}

KeyNode KeyNode::operator [](uint32_t idx) const
{
    KeyNode ret = getChild(idx);
    return ret;
}

KeyNode KeyNode::operator [](KeyNode::CoinType _type) const
{
    // node locked
    const uint32_t h = 0x80000000;
    const uint32_t c = h | 44;
    uint32_t coin_type = h | _type;
    uint32_t t = h | 0;

    switch (_type) {
    case CoinType::Bitcoin:
        Coin::HDKeychain::setVersions(0x0488ADE4, 0x0488B21E);
        address_prefix_ = 0x00;
        private_key_prefix_ = 0x80;
        break;
//    case CoinType::Ether_TestNet:
//        t = h | 1;
    case CoinType::Bitcoin_Testnet:
        Coin::HDKeychain::setVersions(0x04358394, 0x043587CF);
        address_prefix_ = 0x6F;
        private_key_prefix_ = 0xEF;
        break;
    case CoinType::Litecoin:
        Coin::HDKeychain::setVersions(0x0488ADE4, 0x0488B21E);
        address_prefix_ = 0x30;
        private_key_prefix_ = 0xB0;
        break;
    }

    bytes_t key = this->key();
    key.erase(key.begin());
    KeyNode ret(key, this->chain_code());
    ret = ret[c][coin_type][t];

    return ret;
}

KeyNode::auto_uint_t KeyNode::address_prefix_(0x00);
KeyNode::auto_uint_t KeyNode::private_key_prefix_ (0x80);
