#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream outputFile("sentences.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open the file for writing." << std::endl;
        return 1; // Exit indicating error
    }

    std::cout << "Enter text (end each sentence with a dot '.' and press Enter twice to finish):\n";

    std::string input;
    std::getline(std::cin, input);

    while (!input.empty()) {
        outputFile << input << std::endl;
        std::getline(std::cin, input);
    }

    outputFile.close();

    std::cout << "Sentences have been written to 'sentences.txt'." << std::endl;

    return 0; // Exit indicating success
}
