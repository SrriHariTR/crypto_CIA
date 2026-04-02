# Affine Cipher with XOR Hash Verification (C++)

This project demonstrates a simple secure communication system using the Affine Cipher for encryption/decryption and an XOR-based hash for integrity verification.

---

## Description

The program performs the following operations:

1. Encrypts user input using the Affine Cipher  
2. Generates a hash value from the encrypted text  
3. Simulates transmission of cipher and hash  
4. Verifies the integrity of the received data  
5. Decrypts the cipher text only if the hash matches  

---

## Algorithm

1. Start  
2. Read input text  
3. Set keys: a = 5, b = 8  
4. Encrypt text using:
   E(x) = (a * x + b) mod 26  
5. Generate XOR hash of cipher text  
6. Simulate sending cipher and hash  
7. Recompute hash at receiver side  
8. Compare hashes  
   - If not equal → Stop (data tampered)  
   - If equal → Proceed  
9. Decrypt using:
   D(x) = a⁻¹ * (x - b) mod 26  
10. Display results  
11. Stop  


## Compilation

```bash

## Example Run


Enter text: HELLO

--- TRANSMISSION ---
Cipher Sent : RCLLA
Hash Sent   : 82

--- VERIFICATION ---
Computed Hash : 82
Data Safe. Proceeding to decryption...

--- FINAL RESULT ---
Input Text     : HELLO
Cipher Text    : RCLLA
Decrypted Text : HELLO

```

## Output

<img width="638" height="737" alt="image" src="https://github.com/user-attachments/assets/3a3070ba-572d-4f63-8463-77fd8cc72f03" />
