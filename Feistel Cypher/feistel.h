#ifndef FEISTEL_H
#define FEISTEL_H

#include "helpers.h"

bitset<32> F(bitset<32> R, string k){
    bitset<32> bitkey(str2bits(k));
    return R & bitkey;
}

bitset<64> FeistelRound(bitset<64> block, string k){
    bitset<32> left = getHalfBlock(block).first;
    bitset<32> right = getHalfBlock(block).second;

    bitset<32> f_return = F(right, k);
    bitset<32> newRight = left ^ f_return;
    bitset<32> newLeft = right;

    bitset<64> result(newLeft.to_string() + newRight.to_string());

    return result;
}

string Feistel(string block, string key){
    bitset<64> binary_block(str2bits(block));
    bitset<64> encrypted = binary_block;

    for(int i = 0; i < 16; ++i){
        encrypted = FeistelRound(encrypted, key);
    }

    string result = encrypted.to_string().substr(32, 32) + encrypted.to_string().substr(0, 32);
    return bits2str(result);
}

#endif