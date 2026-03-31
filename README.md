# 23011102101_Srri Hari T R -- Cryptography Concepts -- CIA

# Affine Cipher + XOR Hash

This project performs two main operations:

1. **Encrypts input text using the Affine Cipher**
2. **Generates a hash of the encrypted text using XOR**

This ensures:

* The message is **securely encrypted**
* A **hash value** is generated for verification

---

## Overall Flow

```
Input → Affine Encryption → Cipher Text → XOR Hash → Final Output
```

---

## Affine Cipher

The Affine Cipher is a substitution cipher defined as:

```
E(x) = (a × x + b) mod 26
```

### Where:

* `x` = position of the letter (A = 0, B = 1, ..., Z = 25)
* `a`, `b` = keys

---

## Example

### Input:

```
HELLO
```

### Encryption Steps:

* H → 7 → (5×7 + 8) mod 26 = 17 → R
* E → 4 → (5×4 + 8) mod 26 = 2 → C

Final Output:

```
RCLLA
```

---

## XOR Hash Function

### How it works:

1. Initialize:

```
H = 0
```

2. For each character:

```
H = H ^ ASCII(character)
```

---

## Example (RCLLA)

```
H = 0
R → 0 ^ 82 = 82  
C → 82 ^ 67 = 17  
L → 17 ^ 76 = 93  
L → 93 ^ 76 = 17  
A → 17 ^ 65 = 80  
```

### Final Hash Value:

```
80
```

---

