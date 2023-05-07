#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isAlphabetic(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (!isalpha(str[i]) && str[i]!=' ') {
            cout<<"Enter valid string\n";
            return false;
        }
    }
    return true;
}

int main() {
    string msg, key, k, ct, pt;
    int lenm, lenk, i, j=0;
    
    do {
        cout << "Enter Message: ";
        getline(cin, msg);
    } while (!isAlphabetic(msg));
    
    transform(msg.begin(), msg.end(), msg.begin(), ::toupper);
    
    do {
        cout << "Enter Key: ";
        getline(cin, key);
    } while (!isAlphabetic(key));
    
    transform(key.begin(), key.end(), key.begin(), ::toupper);
    
    lenm = msg.length();
    lenk = key.length();

    //loop for iterating the key to length of the message
    for (i=0; i<lenm; i++,j++) {
        if (j == lenk) {
            j = 0;
        }
        k += key[j];
    }
    

    //loop for generating the cipher text by calculating ct of 1 character and appending it to ct
    for (i=0; i<lenm; i++) { 
        if (msg[i] == ' ') {
        ct += ' '; // append space as is
        continue; // continue to next iteration
    }
        ct += ((msg[i]+k[i])%26)+'A';
    }

    //loop to generate plaintext
    for (i=0; i<lenm; i++) {
        if (msg[i] == ' ') {
        pt += ' '; // append space as is
        continue; // continue to next iteration
    }
        pt += (((ct[i]-k[i])+26)%26)+'A';
    }
    
    cout << "\nEncrypted Message: " << ct;
    cout << "\nDecrypted Message: " << pt;
    
    return 0;
}
