#include <iostream>
#include <cmath>

using namespace std;

//gcd function
int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

//calculating power using repeated square algorithm
int modExp(int base, int exponent, int modulus) {
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) // if exponent is odd
            result = (result * base) % modulus;
        base = (base * base) % modulus; // square the base
        exponent /= 2; // divide the exponent by 2
    }
    return result;
}

//main
int main() {
    int p, q, n, phi, e, d, message, encrypted_message, decrypted_message;

    cout << "\nEnter the first prime number (p): ";
    cin >> p;
    cout << "Enter the second prime number (q): ";
    cin >> q;

    n = p * q;
    phi = (p - 1) * (q - 1);

    cout << "Enter the message to be encrypted (less than " << n << "): ";
    cin >> message;

    // Choose e such that 1 < e < phi and gcd(e, phi) = 1
    for (e = 2; e < phi; e++) {
        if (gcd(e, phi) == 1)
            break;
    }
    cout<<"\nValue of e (public key) is: "<<e<<endl;

    // Compute d such that d is the multiplicative inverse of e mod phi
    for (d = 1; d < phi; d++) {
        if ((e * d) % phi == 1)
            break;
    }
    cout<<"\nValue of d (private key) is: "<<d<<endl;


    // Encryption: C = M^e mod n
    encrypted_message = modExp(message, e, n);
    cout << "\nEncrypted message: " << encrypted_message << endl;

    // Decryption: M = C^d mod n
    decrypted_message = modExp(encrypted_message, d, n);
    cout << "Decrypted message: " << decrypted_message << endl;

    return 0;
}

// #include<iostream>
// #include<math.h>
// #include<cmath>
// #include <algorithm>
// #define MAX 100000
// using namespace std;
// int Select_e(int pos,int phi){
//     int i=1,count=0;
//     while(true){
//         if(__gcd(i,phi)==1){
//             count++;
//             if(count == pos ){
//                 return i;
//             }
//         }
//         i++;
//     }
// }
// int RSA(int e,int n){
//     int EncryptedTextNum;
//     cout<<"Enter Plane Text Num : ";
//     cin>>EncryptedTextNum;
//     long long num = pow(EncryptedTextNum,e);
//     int c = num %n;
//     return c;
// }
// int Find_d(int phi,int e){
//     int fix = phi;
//     int i =0;
//     while(true){
//         i++;
//         phi = fix;
//         if(((phi*i)+1)%e ==0 ){
//             return ((phi*i)+1)/e;
//         }
//     }
// }
// int Decryption(int d, int n,int c){
//     long long  num = pow(c,d);
//     //cout<<num<<endl;
//     int dec = num %n;
//     // cout<<dec<<endl;
//     return dec;
// }
// int main(){
//     int p,q,pos;
//     cin>>p>>q;
//     int n = p*q;
//     int phi=(p-1)*(q-1);
//     cout<<"Enter Which e to select : ";
//     cin>>pos;
//     int e = Select_e(pos,phi);
// // cout<<e;
//     int c = RSA(e,n);
//     cout<<"Entecrpted Text : "<<c<<endl;
//     int d = Find_d(phi,e);
//     // cout<<d<<endl;
//     int Decrypt = Decryption(d,n,c);
//     cout<<"Decrypted Text : "<<Decrypt<<endl;
// }