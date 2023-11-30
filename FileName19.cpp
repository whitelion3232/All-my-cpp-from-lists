#include <iostream>

class Rectangle {
public:
    double length;
    double width;

    void read_data() {
        std::cout << "Enter the length of the rectangle: ";
        std::cin >> length;
        std::cout << "Enter the width of the rectangle: ";
        std::cin >> width;
    }

    void process_data() {
        area = length * width;
    }
    void show_data() {
        std::cout << "The area of the rectangle is: " << area << std::endl;
    }
private:
    double area;
};
int main() {
    Rectangle myRectangle; 
    myRectangle.read_data();   // Read data from the user
    myRectangle.process_data(); // Calculate the area
    myRectangle.show_data();    // Display the result

    return 0;
}