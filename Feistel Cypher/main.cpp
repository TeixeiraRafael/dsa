#include "feistel.h"

int main(int argc, char** argv){
    cout << "Feistel says:" << endl;
    string key = "UMVAC@RA";
    string encrypted = Feistel("RAFAELRA", key);
    string decrypted = Feistel(encrypted, key);

    cout << "Encrypted to: " << toHex(encrypted) << endl;
    cout << "Decrypted to: " << decrypted << endl;
}