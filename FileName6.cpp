#include <iostream>
#include <fstream>
#include <cctype> // for std::toupper

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error: Unable to open the files." << std::endl;
        return 1; // Exit indicating error
    }

    std::string word;
    while (inputFile >> word) {
        if (!word.empty()) {
            word[0] = std::toupper(word[0]);
        }
        outputFile << word << " ";
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Text with first letters capitalized has been written to 'output.txt'." << std::endl;

    return 0; // Exit indicating success
}
