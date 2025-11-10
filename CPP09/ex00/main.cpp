#include "BitcoinExchange.hpp"

int main(int ac, char *av[]) {

	if (ac != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange btc;
	btc.processInput(av[1]);

	return 0;
}

/*
1. main(argc, argv)
   ↓
2. Vérifier argc == 2 (un fichier passé en argument)
   ↓
3. Créer BitcoinExchange btc
   ↓
4. Constructeur charge data.csv dans _database
   ↓
5. btc.processInput(argv[1])
   ↓
6. Ouvrir input.txt
   ↓
7. Pour chaque ligne :
   - Parser "date | value"
   - Valider date
   - Valider value
   - Chercher prix dans _database
   - Calculer : value × prix
   - Afficher résultat
   ↓
8. Fermer fichier et terminer
*/