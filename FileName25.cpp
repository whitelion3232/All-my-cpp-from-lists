#include <iostream>
#include <string>

class Student {
public:
    int indexNumber;
    std::string name;
    int age;

    void input() {
        std::cout << "Enter the index number: ";
        std::cin >> indexNumber;

        std::cout << "Enter the name: ";
        std::cin >> name;

        std::cout << "Enter the age: ";
        std::cin >> age;
    }
    void display() {
        std::cout << "Index Number: " << indexNumber << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
    }
};

int main() {
    Student student;

    std::cout << "Enter student details:" << std::endl;
    student.input();

    std::cout << "\nStudent information:" << std::endl;
    student.display();

    return 0;
}