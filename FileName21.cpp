#include <iostream>
#include <string>

class Student {
public:
    void read_data() {
        std::cout << "Enter student's name: ";
        std::cin.ignore(); // Clear the input buffer
        std::getline(std::cin, name);

        std::cout << "Enter student's surname: ";
        std::getline(std::cin, surname);

        std::cout << "Enter student's index number: ";
        std::cin >> indexNumber;

        std::cout << "Enter student's country of origin: ";
        std::cin.ignore(); // Clear the input buffer
        std::getline(std::cin, country);
    }

    void display_data() {
        std::cout << "Student's Name: " << name << std::endl;
        std::cout << "Student's Surname: " << surname << std::endl;
        std::cout << "Index Number: " << indexNumber << std::endl;
        std::cout << "Country of Origin: " << country << std::endl;
    }

private:
    std::string name;
    std::string surname;
    int indexNumber;
    std::string country;
};

int main() {
    Student student; // Create an object of the Student class

    student.read_data();    // Read personal data
    std::cout << "Student Data Entered:" << std::endl;
    student.display_data(); // Display the entered data

    return 0;
}