#include <iostream>
#include <string>

// Base class Person
class Person {
protected:
    std::string firstName;
    std::string lastName;

public:
    Person(const std::string& first, const std::string& last) : firstName(first), lastName(last) {}

    void introduceYourself() {
        std::cout << "I am " << firstName << " " << lastName << "." << std::endl;
    }
};

// Derived class Staff
class Staff : public Person {
private:
    std::string jobTitle;
    double salary;

public:
    Staff(const std::string& first, const std::string& last, const std::string& title, double sal)
        : Person(first, last), jobTitle(title), salary(sal) {}

    void staffInformation() {
        introduceYourself(); // Call the introduceYourself method from the base class
        std::cout << "Job Title: " << jobTitle << std::endl;
        std::cout << "Salary: $" << salary << std::endl;
    }
};

int main() {
    // Create a Person object
    Person person("Henry", "Smith");
    person.introduceYourself();

    // Create a Staff object
    Staff staff("Jenifer", "White", "Engineer", 300000.0);
    staff.staffInformation();

    return 0;
}
