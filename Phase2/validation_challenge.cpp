#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

// Custom encryption function
vector<uint8_t> encrypt_flag(const string& flag) {
    vector<uint8_t> encrypted;
    uint8_t key = 0x7B;
    
    for (size_t i = 0; i < flag.length(); i++) {
        uint8_t byte = flag[i];
        
        // Multi-stage encryption
        // Stage 1: XOR with rotating key
        byte ^= (key + i) & 0xFF;
        
        // Stage 2: Add index
        byte = (byte + i * 3) & 0xFF;
        
        // Stage 3: Bit rotation
        byte = ((byte << 3) | (byte >> 5)) & 0xFF;
        
        encrypted.push_back(byte);
    }
    
    return encrypted;
}

bool validate_flag(const string& input) {
    // Expected encrypted result
    const uint8_t expected[] = {
        0x58, 0xF7, 0x6B, 0x65, 0xF7, 0xB3, 0xEB, 0x9B, 0x07, 0x5F,
        0x67, 0xAF, 0xA7, 0xFF, 0x67, 0x07, 0x07, 0xBF, 0x37, 0x3F,
        0xB7, 0x3F, 0xF7, 0x97, 0xB7, 0xCF, 0x97, 0x17, 0xEF, 0x5F,
        0x47
    };
    
    const size_t expected_len = sizeof(expected) / sizeof(expected[0]);
    
    if (input.length() != expected_len) {
        return false;
    }
    
    vector<uint8_t> encrypted = encrypt_flag(input);
    
    for (size_t i = 0; i < expected_len; i++) {
        if (encrypted[i] != expected[i]) {
            return false;
        }
    }
    
    return true;
}

void print_banner() {
    cout << "========================================" << endl;
    cout << "   Encrypted Flag Validator v3.0       " << endl;
    cout << "========================================" << endl;
    cout << "This checker uses multi-stage encryption!" << endl;
    cout << endl;
}

int main() {
    print_banner();
    
    string input;
    cout << "Enter the flag: ";
    getline(cin, input);
    
    if (validate_flag(input)) {
        cout << "\n✓ Excellent! That's the correct flag!" << endl;
    } else {
        cout << "\n✗ Incorrect flag. Keep analyzing!" << endl;
    }
    
    return 0;
}
