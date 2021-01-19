#include <string>
#include <bitset>
#include <sstream>
#include <iostream>

using namespace std;


bitset<32> F(bitset<32> R, string k){
    return R;
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
        encrypted = FeistelRound(encrypted, "a");
        cout << "Round " << i << ": " << encrypted << endl;
    }

    string result = encrypted.to_string().substr(32, 32) + encrypted.to_string().substr(0, 32);
    return bits2str(result);
}

int main(int argc, char** argv){
    cout << "Feistel says:" << endl;
    string encrypted = Feistel("rafaelra", "key");
    string decrypted = Feistel(encrypted, "key");

    cout << encrypted << endl;
    cout << decrypted << endl;
}