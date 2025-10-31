#include "PmergeMe.hpp"

pmerge::pmerge() {}

pmerge::~pmerge() {}

void pmerge::addToDeque(int value) {
	_deque.push_back(value);
}

void pmerge::addToVector(int value) {
	_vector.push_back(value);
}

void pmerge::printNumber() const {
	for (size_t i = 0; i < _vector.size(); i++)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;
}

void pmerge::display_time(struct timeval& ts1, struct timeval& ts2)
{
    size_t total_micros1 = ts1.tv_sec * MIL + ts1.tv_usec;
    size_t total_micros2 = ts2.tv_sec * MIL + ts2.tv_usec;
    size_t diff_micros = total_micros2 - total_micros1;
    size_t sec = diff_micros / MIL;
    size_t msec = (diff_micros % MIL) / 1000;
    size_t usec = (diff_micros % MIL) % 1000;
    std::cout << sec << " secs, " << msec << " ms and " << usec << " us." << std::endl;
}

bool isPositiveInteger(const std::string& str) {
	if (str.empty())
		return false;
	for (size_t i = 0; i < str.size(); ++i) {
		if (!isdigit(str[i]))
			return false;
	}
	long val = std::strtol(str.c_str(), NULL, 10);
	if (val > INT_MAX || val < 0)
		return false;
	return true;
}

bool pmerge::parseInput(int argc, char** argv, std::vector<int>& vec, std::deque<int>& deq) {
	for (int i = 1; i < argc; ++i) {
		std::string arg(argv[i]);
		if (!isPositiveInteger(arg)) {
			std::cerr << "Error: invalid argument '" << arg << "' (must be a positive integer)" << std::endl;
			return false;
		}
		int value = std::atoi(arg.c_str());
		vec.push_back(value);
		deq.push_back(value);
	}
	return true;
}

void printVector(const std::vector<int>& vect) {
	for (size_t i = 0; i < vect.size(); ++i) {
		std::cout << vect[i] << ", ";
	}
	std::cout << std::endl;
}

void pmerge::printVector(const std::deque<int>& vect) {
	if (vect.size() > 20) {
			for (size_t i = 0; i < 20; ++i) {
			std::cout << vect[i] << " ";
		}
		std::cout << "[...]" << std::endl;
	}
	else {
		for (size_t i = 0; i < vect.size(); ++i) {
			std::cout << vect[i] << " ";
		}
		std::cout << std::endl;
	}
}

void pmerge::printPairs(const std::vector<Pair>& pairs) {
	for (size_t i = 0; i < pairs.size(); ++i) {
		std::cout << "(" << pairs[i].a << ", " << pairs[i].b << ")";
	}
	std::cout << std::endl;
}

std::vector<int> extractWinners(const std::vector<Pair>& pairs) {
	std::vector<int> winners;
	for (size_t i = 0; i < pairs.size(); ++i) {
		if (pairs[i].b != -1) {
			winners.push_back(pairs[i].a);
		}
	}
	return winners;
}

std::deque<int> extractWinnersDeque(const std::deque<Pair>& pairs) {
    std::deque<int> winners;
    for (size_t i = 0; i < pairs.size(); ++i) {
        if (pairs[i].b != -1) {
            winners.push_back(pairs[i].a);
        }
    }
    return winners;
}

std::vector<int> extractLosers(const std::vector<Pair>& pairs) {
    std::vector<int> losers;
    for (size_t i = 0; i < pairs.size(); ++i) {
        if (pairs[i].b != -1) {
            losers.push_back(pairs[i].b);
        }
    }
    return losers;
}

std::deque<int> extractLosersDeque(const std::deque<Pair>& pairs) {
	std::deque<int> losers;
	for (size_t i = 0; i < pairs.size(); ++i) {
		if (pairs[i].b != -1) {
			losers.push_back(pairs[i].b);
		}
	}
	return losers;
}

std::vector<Pair> makePaire(const std::vector<int>& input) {
	std::vector<Pair> pairs;

	for (size_t i = 0; i + 1 < input.size(); i += 2) {
		int x = input[i];
		int y = input[i + 1];
		Pair p;
		if (x > y) {
			p.a = x;
			p.b = y;
		}
		else {
			p.a = y;
			p.b = x;
		}	
		pairs.push_back(p);
	}
	if (input.size() % 2 != 0) {
		Pair p;
		p.a = input.back();
		p.b = -1; 
		pairs.push_back(p);
	}
	return pairs;
}

std::deque<Pair> makePaireDeque(const std::deque<int>& input) {
	std::deque<Pair> pairs;

	for (size_t i = 0; i + 1 < input.size(); i += 2) {
		int x = input[i];
		int y = input[i + 1];
		Pair p;
		if (x > y) {
			p.a = x;
			p.b = y;
		}
		else {
			p.a = y;
			p.b = x;
		}	
		pairs.push_back(p);
	}
	if (input.size() % 2 != 0) {
		Pair p;
		p.a = input.back();
		p.b = -1; 
		pairs.push_back(p);
	}
	return pairs;
}

int findUnpaired(const std::vector<Pair>& pairs) {
	if (pairs.empty())
		return -1;

	const Pair& last = pairs.back();
	if (last.b == -1)
		return last.a; // C'est l'élément non apparié
	return -1;
}

int findUnpairedDeque(const std::deque<Pair>& pairs) {
	if (pairs.empty())
		return -1;

    const Pair& last = pairs.back();
    if (last.b == -1)
        return last.a; // C'est l'élément non apparié
    return -1;
}

std::vector<size_t> generateJacobsthalOrder(size_t n) {
	std::vector<size_t> jacobsthal;
	jacobsthal.push_back(1); // J(1)
	size_t j0 = 0, j1 = 1;

	// Générer la séquence Jacobsthal jusqu'à n
	while (true) {
		size_t next = j1 + 2 * j0;
		if (next >= n)
			break;
		jacobsthal.push_back(next);
		j0 = j1;
		j1 = next;
	}

	// Construire l'ordre d'insertion
	std::vector<size_t> order;
	if (n == 0)
		return order;
	order.push_back(0); // Toujours insérer le premier loser

	for (size_t i = 1; i < jacobsthal.size(); ++i) {
		size_t current = jacobsthal[i];
		size_t previous = jacobsthal[i-1];
		// Insérer de current-1 jusqu'à previous (décroissant)
		for (size_t j = current - 1; j > previous; --j) {
		if (j < n)
			order.push_back(j);
		}
		if (current < n)
			order.push_back(current);
	}
    // Compléter si tous les losers n'ont pas été insérés
    for (size_t i = 0; i < n; ++i) {
        if (std::find(order.begin(), order.end(), i) == order.end())
            order.push_back(i);
    }
    return order;
}

std::deque<size_t> generateJacobsthalOrderDeque(size_t n) {
    std::deque<size_t> jacobsthal;
    jacobsthal.push_back(1); // J(1)
    size_t j0 = 0, j1 = 1;

    // Générer la séquence Jacobsthal jusqu'à n
    while (true) {
		size_t next = j1 + 2 * j0;
        if (next >= n)
            break;
        jacobsthal.push_back(next);
        j0 = j1;
        j1 = next;
    }

    // Construire l'ordre d'insertion
    std::deque<size_t> order;
    if (n == 0)
        return order;
    order.push_back(0); // Toujours insérer le premier loser

    for (size_t i = 1; i < jacobsthal.size(); ++i) {
        size_t current = jacobsthal[i];
        size_t previous = jacobsthal[i-1];
        // Insérer de current-1 jusqu'à previous (décroissant)
        for (size_t j = current - 1; j > previous; --j) {
            if (j < n)
                order.push_back(j);
        }
        if (current < n)
            order.push_back(current);
    }
    // Compléter si tous les losers n'ont pas été insérés
    for (size_t i = 0; i < n; ++i) {
        if (std::find(order.begin(), order.end(), i) == order.end())
            order.push_back(i);
    }
    return order;
}

size_t binaryInsertPosition(const std::vector<int>& vec, int value) {
    size_t left = 0;
    size_t right = vec.size();

    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (vec[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    return left; // Position où insérer 'value'
}

size_t binaryInsertPositionDeque(const std::deque<int>& vec, int value) {
    size_t left = 0;
    size_t right = vec.size();

    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (vec[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    return left; // Position où insérer 'value'
}

std::vector<int> pmerge::fordJohnson(const std::vector<int>& input) {
	if (input.size() <= 1)
		return input;
    // 1. Créer les paires
    std::vector<Pair> pairs = makePaire(input);

    // 2. Extraire winners et losers
    std::vector<int> winners = extractWinners(pairs);
    std::vector<int> losers = extractLosers(pairs);
    int unpaired = findUnpaired(pairs); // si b == -1
    // 3. Appel récursif sur les winners
    std::vector<int> main_chain = fordJohnson(winners);
    // 4. Générer l’ordre Jacobsthal et insérer les losers
    std::vector<size_t> order = generateJacobsthalOrder(losers.size());
	for (size_t i = 0; i < order.size(); ++i) {
		size_t idx = order[i];
		int val = losers[idx];
		size_t pos = binaryInsertPosition(main_chain, val);
		main_chain.insert(main_chain.begin() + pos, val);
	}
    // 5. Insérer l’unpaired s’il existe
    if (unpaired != -1) {
        size_t pos = binaryInsertPosition(main_chain, unpaired);
        main_chain.insert(main_chain.begin() + pos, unpaired);
    }
    return (main_chain);
}

std::deque<int> pmerge::fordJohnsonDeque(const std::deque<int>& input){

	    if (input.size() <= 1)
        return input;

    // 1. Créer les paires
    std::deque<Pair> pairs = makePaireDeque(input);

    // 2. Extraire winners et losers
    std::deque<int> winners = extractWinnersDeque(pairs);
    std::deque<int> losers = extractLosersDeque(pairs);
    int unpaired = findUnpairedDeque(pairs); // si b == -1

    // 3. Appel récursif sur les winners
    std::deque<int> main_chain = fordJohnsonDeque(winners);

    // 4. Générer l’ordre Jacobsthal et insérer les losers
    std::deque<size_t> order = generateJacobsthalOrderDeque(losers.size());
	for (size_t i = 0; i < order.size(); ++i) {
		size_t idx = order[i];
		int val = losers[idx];
		size_t pos = binaryInsertPositionDeque(main_chain, val);
		main_chain.insert(main_chain.begin() + pos, val);
	}

    // 5. Insérer l’unpaired s’il existe
    if (unpaired != -1) {
        size_t pos = binaryInsertPositionDeque(main_chain, unpaired);
        main_chain.insert(main_chain.begin() + pos, unpaired);
    }
    return (main_chain);
}
