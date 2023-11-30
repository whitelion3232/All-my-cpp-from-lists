#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>

int main() {
    std::string data = "2.8  3  11\n0   -6.4\n\n            5.2\n-2  10  8.";

    std::istringstream stream(data);
    std::vector<float> numbers;
    float num;

    while (stream >> std::noskipws >> num) {
        numbers.push_back(num);
    }

    float sum = 0.0;
    for (float number : numbers) {
        sum += number;
    }

    std::cout << "Sum of numbers in the data: " << sum << std::endl;

    return 0;
}
