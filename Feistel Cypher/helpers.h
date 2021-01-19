#ifndef HELPERS_H
#define HELPERS_H

#include "definitions.h"

string toHex(const string& s)
{
    ostringstream ret;

    for (string::size_type i = 0; i < s.length(); ++i)
        ret << hex << setfill('0') << setw(2) << (nouppercase) << (int)s[i];

    return ret.str();
}

int FromHex(const string &s) {
    return strtoul(s.c_str(), NULL, 16); 
}

string str2bits(string input){
    string output;

    for (char& _char : input) {
        output += bitset<8>(_char).to_string();
    }
    return output;;
}

string bits2str(string input){
    string output = "";
    stringstream sstream(input);

    while (sstream.good()) {
        bitset<8> bits;
        sstream >> bits;
        output += char(bits.to_ulong());
    }

    return output;
}

pair< bitset<32>, bitset<32> > getHalfBlock(bitset<64> block){
    pair<bitset<32>, bitset<32> > halves;
    
    string string_left = block.to_string().substr(0, 32);
    string string_right = block.to_string().substr(32, 32);
    
    bitset<32> left(string_left);
    bitset<32> right(string_right);

    halves.first = left;
    halves.second = right;

    return halves;
}

#endif