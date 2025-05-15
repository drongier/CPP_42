#include "Animal.hpp"

int main()
{
    const Animal* animal = new Animal();
    const Dog* dog = new Dog();


    animal->makeSound();
    dog->makeSound();
};