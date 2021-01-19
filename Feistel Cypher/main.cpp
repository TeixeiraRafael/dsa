#include "feistel.h"

int main(int argc, char** argv){
    string input = "1!2.3;4#";
    string key = "150d1400474c524100";
    
    cout << "Feistel says: " << input << endl;
    string encrypted = Feistel(input, key);
    string decrypted = Feistel(encrypted, key);

    cout << "Encrypted to: " << toHex(encrypted) << endl;
    cout << "Decrypted to: " << decrypted << endl;
}