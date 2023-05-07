#include <iostream>
#include <string>

using namespace std;

int main()
{
    string text;
    int key;

    do {
        cout << "Enter text: ";
        getline(cin, text);

        // Check if input string contains only letters
        bool validInput = true;
        for (char c : text)
        {
            if (!isalpha(c) && !isspace(c))
            {
                cout << "Error: input should only contain letters." << endl;
                validInput = false;
                break;
            }
        }
        
        if (validInput) {                       
            break;
        }
    } while (true);

    cout << "Enter key value: ";
    cin >> key;

    // Encryption
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = 'A' + ((text[i] - 'A' + key) % 26);
        }
        else if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = 'a' + ((text[i] - 'a' + key) % 26);
        }
    }

    cout << "Encrypted text: " << text << endl;

    // Decryption
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = 'A' + ((text[i] - 'A' - key + 26) % 26);
        }
        else if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = 'a' + ((text[i] - 'a' - key + 26) % 26);
        }
    }

    cout << "Decrypted text: " << text << endl;

    return 0;
}
