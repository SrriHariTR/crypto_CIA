#include <iostream>
#include <string>
using namespace std;

// Affine Encryption Function
string affineEncrypt(string s, int a, int b)
{
    string result = "";

    for (char c : s)
    {
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            int x = c - base;
            char enc = ((a * x + b) % 26) + base;
            result += enc;
        }
    }
    return result;
}

// XOR Hash Function
int xorHash(string s)
{
    int H = 0;

    for (char c : s)
    {
        H = H ^ (int)c;
    }

    return H;
}

// Function to find modular inverse of a under mod m
int modInverse(int a, int m)
{
    for (int x = 1; x < m; x++)
    {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

// Affine Decryption Function
string affineDecrypt(string s, int a, int b)
{
    string result = "";

    int a_inv = modInverse(a, 26);

    for (char c : s)
    {
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            int x = c - base;

            int dec = (a_inv * (x - b + 26)) % 26;
            result += (dec + base);
        }
    }
    return result;
}

int main()
{
    string text;

    cout << "Enter text: ";
    cin >> text;

    int a = 5, b = 8;

    // Step 1: Encrypt
    string cipher = affineEncrypt(text, a, b);

    // Step 2: Generate hash of cipher
    int originalHash = xorHash(cipher);

    cout << "\n--- TRANSMISSION ---\n";
    cout << "Cipher Sent : " << cipher << endl;
    cout << "Hash Sent   : " << originalHash << endl;

    // Simulate receiving side
    string receivedCipher = cipher;
    int receivedHash = originalHash;

    // Step 3: Verify hash before decryption
    int computedHash = xorHash(receivedCipher);

    cout << "\n--- VERIFICATION ---\n";
    cout << "Computed Hash : " << computedHash << endl;

    if (computedHash != receivedHash)
    {
        cout << "Data Tampered! Do NOT decrypt.\n";
        return 0;
    }

    cout << "Data Safe. Proceeding to decryption...\n";

    // Step 4: Decrypt
    string decrypted = affineDecrypt(receivedCipher, a, b);

    cout << "\n--- FINAL RESULT ---\n";
    cout << "Input Text     : " << text << endl;
    cout << "Cipher Text    : " << cipher << endl;
    cout << "Decrypted Text : " << decrypted << endl;

    return 0;
}
