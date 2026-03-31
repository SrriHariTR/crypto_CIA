#include <iostream>
#include <string>
using namespace std;

// Affine Encryption Function
// This function converts plaintext into cipher text using the formula:
// E(x) = (a*x + b) mod 26
string affineEncrypt(string s, int a, int b)
{
    string result = ""; // stores the encrypted text

    // Loop through each character in the input string
    for (char c : s)
    {
        // Check if the character is an alphabet
        if (isalpha(c))
        {
            // Determine base ('A' for uppercase, 'a' for lowercase)
            char base = isupper(c) ? 'A' : 'a';

            // Convert character to number (A=0, B=1, ..., Z=25)
            int x = c - base;

            // Apply affine formula and convert back to character
            char enc = ((a * x + b) % 26) + base;

            // Add encrypted character to result
            result += enc;
        }
    }
    return result; // return final encrypted string
}

// XOR Hash Function
// This function generates a hash value using XOR operation
int xorHash(string s)
{
    int H = 0; // initialize hash value

    // Loop through each character in the string
    for (char c : s)
    {
        // XOR current hash with ASCII value of character
        H = H ^ (int)c;
    }

    return H; // return final hash value
}

int main()
{
    string text;

    // Take input from user
    cout << "Enter text: ";
    cin >> text;

    // Keys for affine cipher
    int a = 5, b = 8;

    // Step 1: Encrypt the input text
    string cipher = affineEncrypt(text, a, b);

    // Step 2: Generate hash of encrypted text
    int hashValue = xorHash(cipher);

    cout << "\n----- RESULT -----\n";
    cout << "Input Text  : " << text << endl;
    cout << "Cipher Text : " << cipher << endl;
    cout << "XOR Hash    : " << hashValue << endl;
    cout << "------------------\n";

    return 0;
}
