#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::pair<std::string, std::vector<int>>> database = {
    {"admin", {112, 97, 115, 115, 119, 111, 114, 100, 49, 50, 51}}, 
    {"user1", {113, 119, 101, 114, 116, 121}},                     
    {"user2", {49, 50, 51, 52, 53, 54}}                           
};


std::string decodePassword(const std::vector<int>& encoded) {
    std::string password;
    for (int value : encoded) {
        password += static_cast<char>(value);
    }
    return password;
}

std::string getFlag() {
    std::vector<int> numbers = {
        77, 82, 123, 74, 117, 53, 116, 95, 52, 95, 67, 104, 49, 108, 108, 95, 71, 117, 121, 125
    };

    std::string flag;
    for (int value : numbers) {
        flag += static_cast<char>(value);
    }

    return flag;
}

bool login(const std::string& username, const std::string& password) {
    std::string query = "SELECT * FROM users WHERE username = '" + username + "' AND password = '" + password + "';";

    std::cout << "Executing query: " << query << std::endl;

    if (password.find("' OR '1'='1") != std::string::npos) {
        return true; 
    }

    for (const auto& entry : database) {
        if (entry.first == username && decodePassword(entry.second) == password) {
            return true;
        }
    }

    return false;
}

int main() {
    std::string username, password;

    std::cout << "Enter username: ";
    std::getline(std::cin, username);

    std::cout << "Enter password: ";
    std::getline(std::cin, password);

    if (login(username, password)) {
        std::cout << "Access Granted!" << std::endl;
        std::cout << "Flag: " << getFlag() << std::endl;
    } else {
        std::cout << "Access Denied!" << std::endl;
    }

    return 0;
}
