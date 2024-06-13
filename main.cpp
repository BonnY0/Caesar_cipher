#include <iostream>
#include <string>
using namespace std;


string encrypt(string plaintext, int shift)
{
    string ciphertext;

    for (char& c : plaintext)
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
        ciphertext += c;
    }

    return ciphertext;
}


int main()
{
    string plaintext;
    int shift;

    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    cout << "Enter shift (key): ";
    cin >> shift;

    string encrypted = encrypt(plaintext, shift);
    cout << "Encrypted text: " << encrypted << endl;


    return 0;
}
