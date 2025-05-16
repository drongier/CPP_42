#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	size_t	size = 4;
	const Animal* array[size];

	std::cout << "\033[1;32mChecking constructor\033[0m" << std::endl;
	{
		for (size_t i = 0; i < size / 2; i++) {
			array[i] = new Dog();
			std::cout << std::endl;
		}
		for (size_t i = size / 2; i < size ; i++) {
			array[i] = new Cat();
			std::cout << std::endl;
		}
		
		std::cout << std::endl;
	}
	{
		std::cout << "\033[1;32mChecking the array\033[0m" << std::endl;
		for (size_t i = 0; i < size; i++)
		{
			std::cout << "Animal " << i << " type: " << array[i]->getType() << std::endl;
			array[i]->makeSound();
		}

		std::cout << std::endl;
	}
	

	std::cout << "\033[1;32mChecking destructor\033[0m" << std::endl;
    for (size_t i = 0; i < size; i++)
    {
        delete array[i];
		std::cout << std::endl;
    }
}
		