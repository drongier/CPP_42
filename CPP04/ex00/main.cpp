#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\033[1;32mGOOD TEST\033[0m" << std::endl;
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << std::endl;

	std::cout << "Animal type : " << animal->getType() << " " << std::endl;
	std::cout << "Animal type : " << cat->getType() << " " << std::endl;
	std::cout << "Animal type : " << dog->getType() << " " << std::endl;
	std::cout << std::endl;

    animal->makeSound();
	cat->makeSound();
    dog->makeSound();
	std::cout << std::endl;

	delete animal, delete dog, delete cat;
	std::cout << std::endl;

	std::cout << "\033[1;32mWRONG TEST\033[0m" << std::endl;

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << std::endl;

	wrongAnimal->makeSound();
	wrongCat->makeSound();
	std::cout << std::endl;

	delete wrongAnimal, delete wrongCat;
	std::cout << std::endl;

};