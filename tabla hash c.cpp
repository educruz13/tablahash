#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class HashTable {
private:
    int size;
    std::vector<std::vector<std::pair<std::string, std::pair<int, int>>>> table;

    int hash_function(std::string key) {
        int sum = 0;
        for(char c : key) {
            sum += c;
        }
        return sum % size;
    }

public:
    HashTable(int table_size) : size(table_size), table(table_size) {}

    void insert(std::string key, int row, int col) {
        int index = hash_function(key);
        table[index].push_back(std::make_pair(key, std::make_pair(row, col)));
    }

    void display() {
        for(int i = 0; i < size; ++i) {
            for(int j = 0; j < table[i].size(); ++j) {
                std::cout << "(" << table[i][j].second.first << ", " << table[i][j].second.second << "): " << table[i][j].first << std::endl;
            }
        }
    }
};

int main() {
    // Declarando una variable con sintaxis C++
    std::string code = R"(
        int suma = 0;
        suma = 54 + 20;
    )";

    // Inicializando tabla hash
    int table_size = 10; // Elige un tamaño adecuado para la tabla hash
    HashTable hash_table(table_size);

    // Tokenizando el código e insertándolo en la tabla hash
    std::string token;
    int row = 0;
    int col = 0;
    for(char c : code) {
        if(c == ' ' || c == '\n') {
            if(!token.empty()) {
                hash_table.insert(token, row, col - token.size());
                token.clear();
            }
            if(c == '\n') {
                row++;
                col = 0;
            }
        } else {
            token += c;
        }
        col++;
    }

    // Mostrando la tabla hash
    std::cout << "Tabla Hash:" << std::endl;
    hash_table.display();

    return 0;
}
