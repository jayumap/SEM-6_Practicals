#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

string encryptMessage(string msg, string key) {
    string cipher = "";
    int len = key.length();
    int rows = (msg.length() + len - 1) / len;
    char matrix[rows][len];
    map<int, int> keyMap;
    for(int i = 0; i < len; i++) {
        keyMap[key[i]] = i;
    }
    for(int i = 0, k = 0; i < rows; i++) {
        for(int j = 0; j < len && k < msg.length(); j++) {
            matrix[i][j] = msg[k++];
        }
    }
    for(auto const &k: keyMap) {
        for(int i = 0; i < rows; i++) {
            char c = matrix[i][k.second];
            if(isalpha(c) || c == ' ') {
                cipher += c;
            }
        }
    }
    return cipher;
}

// Decryption
string decryptMessage(string cipher, string key)
{
    int col = key.length();
    int row = cipher.length() / col;
    char cipherMat[row][col];
    map<int, int> keyMap;
    for(int i = 0; i < col; i++) {
        keyMap[key[i]] = i;
    }
    int k = 0;
    for (int j = 0; j < col; j++)
    {
        int index = keyMap[j+49];
        for (int i = 0; i < row; i++)
        {
            cipherMat[i][index] = cipher[k++];
        }
    }
    string msg = "";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (cipherMat[i][j] != '_')
            {
                msg += cipherMat[i][j];
            }
        }
    }
    return msg;
}


int main() {
    string key, msg;
    cout << "Enter the message to encrypt: ";
    getline(cin, msg);
    cout << "Enter the key: ";
    cin >> key;
    string cipher = encryptMessage(msg, key);
    cout << "Encrypted message: " << cipher << endl;
    cout << "Decrypted message: " << decryptMessage(cipher, key) << endl;
    return 0;
}
