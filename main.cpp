#include <iostream>
#include <string>
using namespace std;

string encrypt(string text, int shift)
{
    string result;

    for (char& c : text)
    {
        if (isupper(c))
        {
            c = char(int(c + shift - 65) % 26 + 65);
        }
        else if (islower(c))
        {
            c = char(int(c + shift - 97) % 26 + 97);
        }
        else
        {
            continue;
        }
        result += c;
    }

    return result;
}

string decrypt(string text, int shift)
{
    return encrypt(text, 26 - (shift % 26));
}

int main()
{
    string text;
    int shift;
    char choice;

    cout << "Enter 'e' for encryption or 'd' for decryption: ";
    cin >> choice;
    cin.ignore();

    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter shift (key): ";
    cin >> shift;

    if (choice == 'e')
    {
        string encrypted = encrypt(text, shift);
        cout << "Encrypted text: " << encrypted << endl;
    }
    else if (choice == 'd')
    {
        string decrypted = decrypt(text, shift);
        cout << "Decrypted text: " << decrypted << endl;
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
//dec algo added
