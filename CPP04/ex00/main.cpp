#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* animal = new Animal();
    const Dog* dog = new Dog();
	const Cat* cat = new Cat();

	std::cout << "Animal type : " << animal->getType() << " " << std::endl;
	std::cout << "Animal type : " << cat->getType() << " " << std::endl;
	std::cout << "Animal type : " << dog->getType() << " " << std::endl;

    animal->makeSound();
    dog->makeSound();
	cat->makeSound();

};