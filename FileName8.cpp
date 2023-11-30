#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <iomanip>

struct Gallery {
    std::string city;
    int area;
    int numPremises;
};

int main() {
    std::ifstream input("galerie.txt");
    std::unordered_map<std::string, std::unordered_map<std::string, int>> citiesPerCountry;
    std::unordered_map<std::string, Gallery> cityDetails;

    if (input.is_open()) {
        std::string line;
        while (std::getline(input, line)) {
            std::istringstream iss(line);
            std::string country, city;
            iss >> country >> city;

            // Count the number of cities per country
            citiesPerCountry[country][city]++;

            // Calculate total retail area and number of premises
            int totalArea = 0, numPremises = 0;
            for (int i = 0; i < 70; ++i) {
                int length, width;
                iss >> length >> width;
                if (length != 0 && width != 0) {
                    totalArea += length * width;
                    numPremises++;
                }
            }

            // Store city details
            cityDetails[city] = { city, totalArea, numPremises };
        }
        input.close();

        // Write the results to kontakt4_2a.txt
        std::ofstream output("kontakt4_2a.txt");
        if (output.is_open()) {
            for (const auto& city : cityDetails) {
                output << city.second.city << " " << city.second.area << " " << city.second.numPremises << std::endl;
            }
            output.close();
        }
        else {
            std::cerr << "Unable to create output file.";
            return 1;
        }
    }
    else {
        std::cerr << "Unable to open input file.";
        return 1;
    }

    return 0;
}
