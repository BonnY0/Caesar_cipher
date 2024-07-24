#include <iostream>
#include <string>

std::string encrypt(std::string text, int shift)
{
    std::string result;

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

std::string decrypt(std::string text, int shift)
{
    return encrypt(text, 26 - (shift % 26));
}

int main()
{
    std::string text;
    int shift;
    char choice;

    std::cout << "Enter 'e' for encryption or 'd' for decryption: ";
    std::cin >> choice;
    std::cin.ignore();

    std::cout << "Enter text: ";
    std::getline(std::cin, text);

    std::cout << "Enter shift (key): ";
    std::cin >> shift;

    if (choice == 'e')
    {
        std::string encrypted = encrypt(text, shift);
        std::cout << "Encrypted text: " << encrypted << std::endl;
    }
    else if (choice == 'd')
    {
        std::string decrypted = decrypt(text, shift);
        std::cout << "Decrypted text: " << decrypted << std::endl;
    }
    else
    {
        std::cout << "Invalid choice!" << std::endl;
    }

    return 0;
}
