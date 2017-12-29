#ifndef KEYNODE_KEYNODE_H
#define KEYNODE_KEYNODE_H

#include <iostream>
#include <vector>
#if __cplusplus >= 201103L
#include <atomic>
#endif
#include "CoinClasses/hdkeys.h"
#include "logger.h"
#include "stringutils.h"

class KeyNodeSeed : public Coin::HDSeed {
public:
    KeyNodeSeed(const bytes_t& seed) : HDSeed(seed) {}
};

class KeyNode : public Coin::HDKeychain {
public:
    enum CoinType{
        Bitcoin = 0,
        Bitcoin_Testnet = 1,
        Litecoin = 2,
//        Litecoin_Testnet = 0x80000000 | Litecoin,
//        Dogecoin,
//        Reddcoin,
//        Dash,
//        Peercoin,
//        Namecoin,
//        Feathercoin,
//        Counterparty,
//        Blackcoin,
//        NuShares,
//        NuBits,
//        Mazacoin,
//        Viacoin,
//        ClearingHouse,
//        Rubycoin,
//        Groestlcoin,
//        Digitalcoin,
//        Cannacoin,
//        DigiByte,
//        Open_Assets,
//        Monacoin,
//        Clams,
//        Primecoin,
//        Neoscoin,
//        Jumbucks,
//        ziftrCOIN,
//        Vertcoin,
//        NXT,
//        Burst,
//        MonetaryUnit,
//        Zoom,
//        Vpncoin,
//        Canada_eCoin,
//        ShadowCash,
//        ParkByte,
//        Pandacoin,
//        StartCOIN,
//        MOIN,
//        Expanse,
//        Einsteinium,
//        Decred,
//        NEM,
//        Particl,
//        Argentum,
//        Libertas,
//        Posw_coin,
//        Shreeji,
//        Global_Currency_Reserve,
//        Novacoin,
//        Asiacoin,
//        Bitcoindark,
//        Dopecoin,
//        Templecoin,
//        AIB,
//        EDRCoin,
//        Syscoin,
//        Solarcoin,
//        Smileycoin,
//        Ether = 60,
//        Ether_TestNet = 0x80000000 | Ether,
//        Ether_Classic = 61,
//        Ether_Classic_TestNet = 0x80000000 | Ether_Classic,
//        Pesobit = 62,
//        Landcoin,
//        Open_Chain,
//        Bitcoinplus,
//        Internet_of_People,
//        Nexus,
//        InsaneCoin,
//        OKCash,
//        BritCoin,
//        Compcoin,
//        Crown,
//        BelaCoin,
//        Compcoin_404,
//        FujiCoin,
//        MIX,
//        Verge,
//        Electronic_Gulden,
//        ClubCoin,
//        RichCoin,
//        Potcoin,
//        Quarkcoin,
//        Terracoin,
//        Gridcoin,
//        Auroracoin,
//        IXCoin,
//        Gulden,
//        BitBean,
//        Bata,
//        Myriadcoin,
//        BitSend,
//        Unobtanium,
//        MasterTrader,
//        GoldBlocks,
//        Saham,
//        Chronos,
//        Ubiquoin,
//        Evotion,
//        SaveTheOcean,
//        BigUp,
//        GameCredits,
//        Dollarcoins,
//        Zayedcoin,
//        Dubaicoin,
//        Stratis,
//        Shilling,
//        MarsCoin,
//        Ubiq,
//        Pesetacoin,
//        Neurocoin,
//        ARK,
//        UltimateSecureCashMain,
//        Hempcoin,
//        Linx,
//        Ecoin,
//        Denarius,
//        Pinkcoin,
//        PiggyCoin,
//        Pivx,
//        Flashcoin,
//        Zencash,
//        Putincoin,
//        BitZeny,
//        Unify,
//        StealthCoin,
//        Breakout_Coin,
//        Vcash,
//        Monero,
//        Voxels,
//        NavCoin,
//        Factom_Factoids,
//        Factom_Entry_Credits,
//        Zcash,
//        Lisk,
//        Steem,
//        ZCoin,
//        Rootstock,
//        Giftblock,
//        RealPointCoin,
//        LBRY_Credits,
//        Komodo,
//        bisq_Token,
//        Riecoin,
//        Ripple,
//        Bitcoin_Cash,
//        Neblio,
//        ZClassic,
//        Stellar_Lumens,
//        NoLimitCoin2,
//        WhaleCoin,
//        EuropeCoin,
//        Diamond,
//        Bytom,
//        Biocoin,
//        Whitecoin,
//        Bitcoin_Gold,
//        Bitcoin_2x,
//        SuperSkynet,
//        TOACoin,
//        Bitcore,
//        Adcoin,
//        Bridgecoin,
//        Ellaism,
//        Pirl,
//        RaiBlocks,
//        Vivo,
//        Firstcoin,
//        Helleniccoin,
//        BUZZ,
//        Ember,
//        Hcash,
//        HTMLCOIN,
//        Obsidian,
//        OnixCoin
    };



#ifdef _GLIBCXX_ATOMIC
    typedef std::atomic<uint8_t> auto_uint_t;
#else
    typedef uint8_t auto_uint_t;
#endif
public:
    KeyNode() {}
    KeyNode(const bytes_t& key, const bytes_t& chain_code, uint32_t child_num = 0, uint32_t parent_fp = 0, uint32_t depth = 0);
    KeyNode(const bytes_t& extkey);
    KeyNode(const KeyNode& other);
    KeyNode getChild(uint32_t i) const;
    KeyNode getPublic() const;
    std::string address() const;
    std::string address(bool compressed) const;
    std::string privkey() const;
    std::string privkey(bool compressed) const;
    static void setTestNet(bool enabled);
    KeyNode operator [](uint32_t idx) const;
    KeyNode operator [](CoinType _type) const;
private:
    static std::string secretToASecret(const uchar_vector& secret, bool compressed = false);
    static std::string publicKeyToAddress(const uchar_vector& public_key);
    static uchar_vector hash160(const uchar_vector& public_key);
    static std::string hash160ToAddress(const uchar_vector& h160, uint8_t addrtype);
    static std::string encodeBase58Check(const uchar_vector& vchIn);

    static auto_uint_t address_prefix_;
    static auto_uint_t private_key_prefix_;
//    static uint8_t address_prefix_;
//    static uint8_t private_key_prefix_;
};

#endif /* KEYNODE_KEYNODE_H */
