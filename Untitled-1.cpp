#include <iostream>
#include <string>
#include <cctype>

// Function to encrypt a message using the Vigenère cipher
std::string encryptVigenere(const std::string& plaintext, const std::string& keyword) {
    std::string ciphertext = "";
    int keywordLength = keyword.length();
    
    for (size_t i = 0; i < plaintext.length(); ++i) {
        char c = plaintext[i];
        char keyChar = keyword[i % keywordLength]; // Repeating the keyword if necessary
        
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            int shift = keyChar - base; // Convert key character to a shift value
            
            c = (c - base + shift) % 26 + base; // Apply shift
        }
        
        ciphertext += c;
    }
    
    return ciphertext;
}

// Function to decrypt a message encrypted with the Vigenère cipher
std::string decryptVigenere(const std::string& ciphertext, const std::string& keyword) {
    std::string decryptedText = "";
    int keywordLength = keyword.length();
    
    for (size_t i = 0; i < ciphertext.length(); ++i) {
        char c = ciphertext[i];
        char keyChar = keyword[i % keywordLength];
        
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            int shift = keyChar - base;
            
            // Reverse the shift to decrypt
            c = (c - base - shift + 26) % 26 + base;
        }
        
        decryptedText += c;
    }
    
    return decryptedText;
}

int main() {
    std::string message;
    std::string keyword;

    std::cout << "Enter a message: ";
    std::getline(std::cin, message);

    std::cout << "Enter the keyword: ";
    std::cin >> keyword;

    std::string encryptedMessage = encryptVigenere(message, keyword);
    std::string decryptedMessage = decryptVigenere(encryptedMessage, keyword);

    std::cout << "Encrypted message: " << encryptedMessage << std::endl;
    std::cout << "Decrypted message: " << decryptedMessage << std::endl;

    return 0;
}