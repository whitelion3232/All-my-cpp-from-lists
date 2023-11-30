#include <iostream>
#include <string>

class Student {
public:
    // Member variables
    std::string name;
    std::string surname;
    int index_number;
    std::string country_of_origin;

    // Member function to read data
    void read_data() {
        std::cout << "Enter student name: ";
        std::cin >> name;

        std::cout << "Enter student surname: ";
        std::cin >> surname;

        std::cout << "Enter student index number: ";
        std::cin >> index_number;

        std::cout << "Enter country of origin: ";
        std::cin >> country_of_origin;
    }

    // Member function to display data
    void display_data() {
        std::cout << "Student Name: " << name << std::endl;
        std::cout << "Student Surname: " << surname << std::endl;
        std::cout << "Index Number: " << index_number << std::endl;
        std::cout << "Country of Origin: " << country_of_origin << std::endl;
    }
};

int main() {
    const int max_students = 3; // Define the maximum number of students
    Student students[max_students]; // Create an array of Student objects

    // Input data for multiple students
    for (int i = 0; i < max_students; i++) {
        std::cout << "Enter data for Student " << (i + 1) << std::endl;
        students[i].read_data();
    }

    // Display data for all students
    for (int i = 0; i < max_students; i++) {
        std::cout << "Data for Student " << (i + 1) << std::endl;
        students[i].display_data();
        std::cout << std::endl;
    }

    return 0;
}
