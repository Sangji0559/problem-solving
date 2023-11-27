#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <sstream>

const int TABLE_SIZE = 16;

class HashTable {
private:
    std::vector<std::list<int>> table;

public:
    HashTable() : table(TABLE_SIZE) {}

    void insert(int key) {
        int index = hashFunction(key);

        if (std::find(table[index].begin(), table[index].end(), key) == table[index].end()) {
            table[index].push_back(key);
        }
    }


    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    void printToFile(std::ofstream& outFile) {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            outFile << i << ":";
            if (table[i].empty()) {
                outFile << "-1";
            }
            else {
                for (int key : table[i]) {
                    outFile << key << ",";
                }
            }
            outFile << std::endl;
        }
    }

private:
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }
};

int main() {
    std::ifstream inFile("hash_cmd.txt");
    std::ofstream outFile("result.txt");

    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Error opening files." << std::endl;
        return 1;
    }

    HashTable hashTable;

    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        char command;
        int key;

        if (!(iss >> command >> key)) {
            std::cerr << "Error parsing command from line: " << line << std::endl;
            continue;
        }

        switch (command) {
        case 'i':
            hashTable.insert(key);
            break;
        case 'r':
            hashTable.remove(key);
            break;
        default:
            std::cerr << "Unknown command: " << command << std::endl;
        }
    }

    hashTable.printToFile(outFile);

    inFile.close();
    outFile.close();

    return 0;
}
