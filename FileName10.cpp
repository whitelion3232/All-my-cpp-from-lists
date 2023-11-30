#include <iostream>
#include <string>

// Base class Vehicle
class Vehicle {
protected:
    std::string type;

public:
    Vehicle() : type("unknown") {} // Default constructor

    Vehicle(const std::string& vehicleType) : type(vehicleType) {}

    virtual void drive() {
        std::cout << "The " << type << " is in motion." << std::endl;
    }
};

// Derived class Boat
class Boat : virtual public Vehicle {
public:
    Boat() : Vehicle("boat") {}

    void sail() {
        std::cout << "The boat is sailing." << std::endl;
    }
};

// Derived class Car
class Car : virtual public Vehicle {
public:
    Car() : Vehicle("car") {}

    void drive() {
        std::cout << "The car is driving on the road." << std::endl;
    }
};

// Derived class Amphibious (inherits from Boat and Car)
class Amphibious : public Boat, public Car {
public:
    Amphibious() {}

    void operate() {
        Boat::sail();
        Car::drive();
    }
};

int main() {
    Amphibious amphibiousVehicle;
    amphibiousVehicle.operate();

    return 0;
}
