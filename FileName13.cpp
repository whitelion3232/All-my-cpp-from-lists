#include <iostream>
#include <cmath>

// Base class GeometricShape
class GeometricShape {
public:
    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;
};

// Derived class Circle
class Circle : public GeometricShape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getArea() override {
        return M_PI * radius * radius;
    }

    double getPerimeter() override {
        return 2 * M_PI * radius;
    }
};

// Derived class Rectangle
class Rectangle : public GeometricShape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double getArea() override {
        return length * width;
    }

    double getPerimeter() override {
        return 2 * (length + width);
    }
};

// Derived class Triangle
class Triangle : public GeometricShape {
private:
    double base;
    double height;
    double side1;
    double side2;
    double side3;

public:
    Triangle(double b, double h, double s1, double s2, double s3)
        : base(b), height(h), side1(s1), side2(s2), side3(s3) {}

    double getArea() override {
        return 0.5 * base * height;
    }

    double getPerimeter() override {
        return side1 + side2 + side3;
    }
};

int main() {
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);
    Triangle triangle(3.0, 4.0, 5.0, 4.0, 3.0);

    std::cout << "Circle - Area: " << circle.getArea() << ", Perimeter: " << circle.getPerimeter() << std::endl;
    std::cout << "Rectangle - Area: " << rectangle.getArea() << ", Perimeter: " << rectangle.getPerimeter() << std::endl;
    std::cout << "Triangle - Area: " << triangle.getArea() << ", Perimeter: " << triangle.getPerimeter() << std::endl;

    return 0;
}
