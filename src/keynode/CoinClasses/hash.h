#ifndef __HASH_H___
#define __HASH_H___

#include "uchar_vector.h"
#include <openssl/sha.h>
#include <openssl/ripemd.h>
#include <openssl/hmac.h>

// All inputs and outputs are big endian

inline uchar_vector sha256(const uchar_vector& data)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, &data[0], data.size());
    SHA256_Final(hash, &sha256);
    uchar_vector rval(hash, SHA256_DIGEST_LENGTH);
    return rval;
}

inline uchar_vector sha256_2(const uchar_vector& data)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, &data[0], data.size());
    SHA256_Final(hash, &sha256);
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, hash, SHA256_DIGEST_LENGTH);
    SHA256_Final(hash, &sha256);
    uchar_vector rval(hash, SHA256_DIGEST_LENGTH);
    return rval;
}

inline uchar_vector ripemd160(const uchar_vector& data)
{
    unsigned char hash[RIPEMD160_DIGEST_LENGTH];
    RIPEMD160_CTX ripemd160;
    RIPEMD160_Init(&ripemd160);
    RIPEMD160_Update(&ripemd160, &data[0], data.size());
    RIPEMD160_Final(hash, &ripemd160);
    uchar_vector rval(hash, RIPEMD160_DIGEST_LENGTH);
    return rval;
}

inline uchar_vector mdsha(const uchar_vector& data)
{
    return ripemd160(sha256(data));
}

inline uchar_vector sha1(const uchar_vector& data)
{
    unsigned char hash[SHA_DIGEST_LENGTH];
    SHA_CTX sha1;
    SHA1_Init(&sha1);
    SHA1_Update(&sha1, &data[0], data.size());
    SHA1_Final(hash, &sha1);
    uchar_vector rval(hash, SHA_DIGEST_LENGTH);
    return rval;
}

inline uchar_vector hmac_sha512(const uchar_vector& key, const uchar_vector& data)
{
    unsigned char* digest = HMAC(EVP_sha512(), (unsigned char*)&key[0], key.size(), (unsigned char*)&data[0], data.size(), NULL, NULL);
    return uchar_vector(digest, 64);
}

#endif
