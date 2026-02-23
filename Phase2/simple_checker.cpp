#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool check_part1(const string& input) {
    return input.substr(0, 6) == "ctf4b{";
}

bool check_part2(const string& input) {
    if (input.length() < 12) return false;
    
    // Check specific characters
    return input[6] == 's' && 
           input[7] == '1' && 
           input[8] == 'm' && 
           input[9] == 'p' && 
           input[10] == 'l' && 
           input[11] == '3';
}

bool check_part3(const string& input) {
    if (input.length() < 18) return false;
    
    // Simple encoding check
    const char expected[] = {0x5f, 0x67, 0x68, 0x31, 0x64, 0x72, 0x34};
    
    for (int i = 0; i < 7; i++) {
        if (input[12 + i] != expected[i]) {
            return false;
        }
    }
    
    return true;
}

bool check_part4(const string& input) {
    return input.length() == 26 && 
           input.substr(19, 6) == "_ch3ck" &&
           input[25] == '}';
}

int main() {
    cout << "=====================================" << endl;
    cout << "     Simple Flag Checker v2.0       " << endl;
    cout << "=====================================" << endl;
    cout << endl;
    
    string input;
    cout << "Enter the flag: ";
    getline(cin, input);
    
    if (check_part1(input) && 
        check_part2(input) && 
        check_part3(input) && 
        check_part4(input)) {
        cout << "\n✓ Correct flag!" << endl;
    } else {
        cout << "\n✗ Wrong flag!" << endl;
        
        // Debug info (hidden in release)
        #ifdef DEBUG
        cout << "Part 1: " << (check_part1(input) ? "OK" : "FAIL") << endl;
        cout << "Part 2: " << (check_part2(input) ? "OK" : "FAIL") << endl;
        cout << "Part 3: " << (check_part3(input) ? "OK" : "FAIL") << endl;
        cout << "Part 4: " << (check_part4(input) ? "OK" : "FAIL") << endl;
        #endif
    }
    
    return 0;
}