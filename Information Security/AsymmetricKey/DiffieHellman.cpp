#include <iostream>
#include <set>
using namespace std;

int pow_mod(int base, int exponent, int mod)
{
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent = exponent / 2;
    }
    return result;
}

// Checks if a number is prime
bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Finds a primitive root of p
int find_q(int p){
    for(int i=1;i<p;i++){
        set<int> s;
        for(int j=1;j<p;j++){
            int number = pow_mod(i,j,p);
            s.insert(number);
        }
        if(s.size()==p-1){
            return i;
        }
    }
    return 0;
}

int main()
{
    int p, X1, X2;
    while (true) {
        cout<<"Enter a prime number: ";
        cin >> p;
        if (is_prime(p)) {
            break;
        } else {
            cout << "Error: " << p << " is not a prime number." << endl;
        }
    }
    int q = find_q(p);
    cout<<"Primitive root is: "<<q<<endl;
    while (true) {
        cout<<"Enter private key of sender (less than "<<p<<"): ";
        cin >> X1;
        if (X1 >= p) {
            cout << "Error: "<<X1<<" is not less than "<<p<<"."<<endl;
        } else {
            break;
        }
    }
    while (true) {
        cout<<"Enter private key of receiver (less than "<<p<<"): ";
        cin >> X2;
        if (X2 >= p) {
            cout << "Error: "<<X2<<" is not less than "<<p<<"."<<endl;
        } else {
            break;
        }
    }
    int num = pow_mod(q, X1, p);
    int Y1 = num;
    cout <<"Public key of sender is: "<< Y1 << endl;
    num = pow_mod(q, X2, p);
    int Y2 = num;
    cout <<"Public key of receiver is: "<< Y2 << endl;
    num = pow_mod(Y2, X1, p);
    int key1 = num;
    num = pow_mod(Y1, X2, p);
    int key2 = num;
    if (key1 == key2)
    {
        cout << "Same key : " << Y1 << endl;
    }
    else
    {
        cout << "Keys do not match!" << endl;
    }
    return 0;
}





// #include <iostream>
// #include <vector>

// using namespace std;

// int modExp(int base, int exponent, int modulus) {
//     int result = 1;
//     while (exponent > 0) {
//         if (exponent % 2 == 1) // if exponent is odd
//             result = (result * base) % modulus;
//         base = (base * base) % modulus; // square the base
//         exponent /= 2; // divide the exponent by 2
//     }
//     return result;
// }

// int gcd(int a, int b) {
//     if (b == 0)
//         return a;
//     return gcd(b, a % b);
// }

// int findPrimitiveRoot(int p) {
//     int phi = p - 1;
//     vector<int> factors;

//     // Factorize phi
//     int n = phi;
//     for (int i = 2; i * i <= n; i++) {
//         while (n % i == 0) {
//             factors.push_back(i);
//             n /= i;
//         }
//     }
//     if (n > 1)
//         factors.push_back(n);

//     // Check if each number from 2 to p-1 is a primitive root
//     for (int g = 2; g <= p - 1; g++) {
//         bool isPrimitiveRoot = true;
//         for (int i = 0; i < factors.size(); i++) {
//             if (modExp(g, phi / factors[i], p) == 1) {
//                 isPrimitiveRoot = false;
//                 break;
//             }
//         }
//         if (isPrimitiveRoot)
//             return g;
//     }

//     return -1; // No primitive root found
// }

// int main() {
//     int p, g, a, b, A, B, secret_key_A, secret_key_B;

//     cout << "Enter a prime number (p): ";
//     cin >> p;

//     g = findPrimitiveRoot(p);
//     if (g == -1) {
//         cout << "No primitive root found for " << p << endl;
//         return 0;
//     }
//     cout << "Primitive root of " << p << " is " << g << endl;

//     cout << "Enter the secret key of user A (a): ";
//     cin >> a;
//     cout << "Enter the secret key of user B (b): ";
//     cin >> b;

//     // User A generates A = g^a mod p
//     A = modExp(g, a, p);

//     // User B generates B = g^b mod p
//     B = modExp(g, b, p);

//     // User A and B exchange A and B
//     secret_key_A = modExp(B, a, p);
//     secret_key_B = modExp(A, b, p);

//     cout << "User A's secret key: " << secret_key_A << endl;
//     cout << "User B's secret key: " << secret_key_B << endl;

//     return 0;
// }



// #include <iostream>
// #include <math.h>
// #include<set>
// using namespace std;
// int find_q(int p){
//     for(int i=1;i<p;i++){
//         set<int>s;
//         for(int j=1;j<p;j++){
//             int number = pow(i,j);
//             s.insert(number%p);
//         }
//         if(s.size()==p-1){
//             return i;
//         }
//         cout<<endl;
//     }
//     return 0;
// }
// int main()
// {
//     int p, X1, X2;
//     cout<<"Enter the Prime Number : ";
//     cin >> p;
//     int q = find_q(p);
//     cout<<"Value of primitive root (q) = "<<q<<endl;
//     cout<<"Enter private key of sender: ";
//     cin >> X1;
//     cout<<"Enter private key of receiver: ";
//     cin >> X2;
//     int num = pow(q, X1);
//     int Y1 = num % p;
//     cout <<"Enter the Encrypted Key for First : "<< Y1 << endl;
//     num = pow(q, X2);
//     int Y2 = num % p;
//     cout <<"Enter the Encrypted Key for second : "<< Y2 << endl;
//     num = pow(Y2, X1);
//     int key1 = num % p;
//     num = pow(Y1, X2);
//     int key2 = num % p;
//     cout<<"Shared secret key of sender: "<<key1<<endl;
//     cout<<"Shared secret key of receiver: "<<key2<<endl;
//     }
