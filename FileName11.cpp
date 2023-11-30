#include <iostream>
#include <cmath>

class Vector {
private:
    double x;
    double y;

public:
    // Constructor to initialize vector coordinates
    Vector(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

    // Method to display vector coordinates
    void display() const {
        std::cout << "[" << x << " ; " << y << "]" << std::endl;
    }

    // Method to calculate the length of the vector
    double length() const {
        return sqrt(x * x + y * y);
    }

    // Friend function to sum two vectors
    friend Vector sum(const Vector& v1, const Vector& v2);

    // Friend function to calculate the product of a vector by a scalar
    friend Vector product(const Vector& v, double scalar);
};

// Friend function definition to sum two vectors
Vector sum(const Vector& v1, const Vector& v2) {
    return Vector(v1.x + v2.x, v1.y + v2.y);
}

// Friend function definition to calculate the product of a vector by a scalar
Vector product(const Vector& v, double scalar) {
    return Vector(v.x * scalar, v.y * scalar);
}

int main() {
    Vector vec1(5.0, 4.0);
    Vector vec2(1.0, -8.0);

    std::cout << "Vector 1: ";
    vec1.display();

    std::cout << "Vector 2: ";
    vec2.display();

    std::cout << "Length of Vector 1: " << vec1.length() << std::endl;
    std::cout << "Length of Vector 2: " << vec2.length() << std::endl;

    Vector sumResult = sum(vec1, vec2);
    std::cout << "Sum of vectors: ";
    sumResult.display();

    double scalar = 2.5;
    Vector productResult = product(vec1, scalar);
    std::cout << "Product of Vector 1 by scalar " << scalar << ": ";
    productResult.display();

    return 0;
}
