#include <iostream>
#include <string>
#include <bitset>

using namespace std;


bitset<32> F(bitset<32> R, string k){
    return R;
}

string getBString(string input){
    string output;

    for (char& _char : input) {
        output += bitset<8>(_char).to_string();
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
    bitset<64> binary_block(getBString(block));
    bitset<64> encrypted = binary_block;

    for(int i = 0; i < 16; ++i){
        encrypted = FeistelRound(encrypted, "a");
        cout << "Round " << i << ": " << encrypted << endl;
    }

    return encrypted.to_string();
}

int main(int argc, char** argv){
    cout << "Feistel says:" << endl;
    Feistel("RAFAELRA", "A");
}