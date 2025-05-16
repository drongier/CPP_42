#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	size_t	size = 4;
	const AAnimal* array[size];

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

	// {
	// 	std::cout << "\033[1;32mChecking that an A_Animal cannot be instanciated\033[0m" << std::endl;

	// 	const AAnimal* a = new AAnimal(); 
	// }

	{
		std::cout << "\033[1;32mChecking that copies are deep copies\033[0m" << std::endl;

		Dog basic;
		std::cout << std::endl;

		basic.setBrainIdea(0, "HELLO");
		std::cout << "BASIC idea[0] before copy: " << basic.getBrainIdea(0) << std::endl;

		Dog copy = basic;
		std::cout << std::endl;

		std::cout << "COPY idea[0] after copy: " << copy.getBrainIdea(0) << std::endl;

		basic.setBrainIdea(0, "BONJOUR");

		std::cout << "\nAfter modifying MAIN with bonjour:\n";
		std::cout << "BASIC idea[0]: " << basic.getBrainIdea(0) << std::endl;
		std::cout << "COPY idea[0]: " << copy.getBrainIdea(0) << std::endl;
		std::cout << std::endl;
	}

	std::cout << std::endl;

	std::cout << "\033[1;32mChecking destructor\033[0m" << std::endl;
    for (size_t i = 0; i < size; i++)
    {
        delete array[i];
		std::cout << std::endl;
    }
}
		