#include <iostream>
#include <cmath>

class QuadraticEquation {
public:
    void input_data() {
        std::cout << "Enter the coefficients a, b, and c: ";
        std::cin >> a >> b >> c;
    }

    void process_data() {
        discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
            // Two real and distinct roots
            root1 = (-b + sqrt(discriminant)) / (2 * a);
            root2 = (-b - sqrt(discriminant)) / (2 * a);
            rootType = "Real and Distinct Roots";
        }
        else if (discriminant == 0) {
            // One real root (repeated)
            root1 = -b / (2 * a);
            rootType = "Real and Repeated Root";
        }
        else {
            // Complex roots
            realPart = -b / (2 * a);
            imaginaryPart = sqrt(-discriminant) / (2 * a);
            rootType = "Complex Roots";
        }
    }

    void display_result() {
        std::cout << "Root Type: " << rootType << std::endl;

        if (rootType == "Real and Distinct Roots") {
            std::cout << "Root 1: " << root1 << std::endl;
            std::cout << "Root 2: " << root2 << std::endl;
        }
        else if (rootType == "Real and Repeated Root") {
            std::cout << "Root: " << root1 << std::endl;
        }
        else {
            std::cout << "Root 1: " << realPart << " + " << imaginaryPart << "i" << std::endl;
            std::cout << "Root 2: " << realPart << " - " << imaginaryPart << "i" << std::endl;
        }
    }

private:
    double a, b, c;
    double discriminant;
    double root1, root2;
    double realPart, imaginaryPart;
    std::string rootType;
};

int main() {
    QuadraticEquation equation;

    equation.input_data();
    equation.process_data();
    equation.display_result();

    return 0;
}
