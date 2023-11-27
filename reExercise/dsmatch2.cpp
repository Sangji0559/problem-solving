#include <iostream>
#include <string>
#include <vector>
#include <random>

std::string generate_key(size_t len) {
    static const std::string char_set = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> dist(0, char_set.length() - 1);
    std::string key;

    for (size_t i = 0; i < len; ++i) {
        key.push_back(char_set[dist(gen)]);
    }

    return key;
}

std::string decode(const std::string& encoded, size_t n) {
    std::string key = generate_key(n);
    std::vector<uint8_t> key_bytes(key.begin(), key.end());

    std::string decoded = encoded;
    for (size_t i = 0; i < decoded.length(); ++i) {
        decoded[i] ^= key_bytes[i % n];
    }

    for (size_t i = 0; i < n; ++i) {
        char c = decoded.front();
        decoded.erase(decoded.begin());
        decoded.push_back(c);
    }

    return decoded;
}

int main() {
    std::string encoded_flag = "5067491628217439052E156D2B160A2E0D272A61355C27700A150B4C060A0E4B36";
    size_t KEY_LEN = 5;

    std::string decoded_flag = decode(encoded_flag, KEY_LEN);
    std::cout << "decoded_flag: " << decoded_flag << std::endl;

    return 0;
}
