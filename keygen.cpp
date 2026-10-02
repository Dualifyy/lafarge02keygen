#include <iostream>
#include <string>

int main() {
    const std::string seed = "_r <()<1-Z2[l5,^";   // constant at 0x406BA4

    std::cout << "Username: ";
    std::string name;
    std::getline(std::cin, name);

    if (name.size() < 4) {
        std::cerr << "Username must have at least 4 chars.\n";
        return 1;
    }

    std::string key = seed;
    const size_t keyLen  = seed.size();             // 16
    const size_t nameLen = name.size();
    const size_t count   = std::max(nameLen, keyLen);

    for (size_t i = 0; i < count; i++) {
        unsigned char n = static_cast<unsigned char>(name[i % nameLen]);
        unsigned char k = static_cast<unsigned char>(key[i % keyLen]);
        key[i % keyLen] = static_cast<char>((n ^ k) % 25 + 'A');
    }

    std::cout << "Serial: "
              << key.substr(0, 4)  << '-' << key.substr(4, 4)  << '-'
              << key.substr(8, 4)  << '-' << key.substr(12, 4) << "\n";
}