#include <iostream>

// Function to calculate the greatest common divisor (GCD)
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num, int denom) : numerator(num), denominator(denom) {}

    // Method to simplify the fraction
    void simplify() {
        int common = gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;
    }

    // Friend function to multiply two fractions
    friend Fraction multiply(const Fraction& f1, const Fraction& f2);

    // Display method
    void display() const {
        std::cout << numerator << "/" << denominator << std::endl;
    }
};

// Friend function definition to multiply two fractions
Fraction multiply(const Fraction& f1, const Fraction& f2) {
    int num = f1.numerator * f2.numerator;
    int denom = f1.denominator * f2.denominator;
    Fraction result(num, denom);
    result.simplify();
    return result;
}

int main() {
    Fraction frac1(2, 6);
    Fraction frac2(3, 9);

    std::cout << "Fraction 1: ";
    frac1.display();

    std::cout << "Fraction 2: ";
    frac2.display();

    Fraction result = multiply(frac1, frac2);
    std::cout << "Result of multiplication: ";
    result.display();

    return 0;
}
