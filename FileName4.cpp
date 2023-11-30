#include <iostream>
#include <string>

// Base class Animal
class Animal {
protected:
    std::string name;

public:
    Animal(const std::string& animalName) : name(animalName) {}

    void eat() {
        std::cout << name << " is eating." << std::endl;
    }
};

// Derived class Mammal
class Mammal : public Animal {
private:
    int numberOfLegs;

public:
    Mammal(const std::string& mammalName, int legs) : Animal(mammalName), numberOfLegs(legs) {}

    void nursing() {
        std::cout << name << " is nursing its young." << std::endl;
    }
};

// Derived class Bird
class Bird : public Animal {
private:
    bool hasWings;

public:
    Bird(const std::string& birdName, bool wings) : Animal(birdName), hasWings(wings) {}

    void fly() {
        if (hasWings) {
            std::cout << name << " is flying." << std::endl;
        }
        else {
            std::cout << name << " cannot fly because it doesn't have wings." << std::endl;
        }
    }
};

// Derived class Fish
class Fish : public Animal {
public:
    Fish(const std::string& fishName) : Animal(fishName) {}

    void swim() {
        std::cout << name << " is swimming in the water." << std::endl;
    }
};

int main() {
    Mammal elephant("Elephant", 4);
    Bird eagle("Eagle", true);
    Fish goldfish("Goldfish");

    elephant.eat();
    elephant.nursing();

    eagle.eat();
    eagle.fly();

    goldfish.eat();
    goldfish.swim();

    return 0;
}
