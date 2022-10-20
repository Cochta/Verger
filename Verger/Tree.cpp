#include "Tree.h"
#include <random>
#include <iostream>

int getRandomInt(int min, int max) {
	std::random_device os_seed;
	uint_least32_t seed = os_seed();

	std::mt19937 generator(seed);
	std::uniform_int_distribution<uint_least32_t> distribute(min, max);

	return distribute(generator);
}

Tree::Tree(int _minF, int _maxF, int _fWeight, Months _gMonth, Months _hMonth)
{
	minFruit = _minF;
	maxFruit = _maxF;
	fruitWeight = _fWeight;
	growMonth = _gMonth;
	harvestMonth = _hMonth;
}

void Tree::Status(int _actualMonth)
{
	if (_actualMonth == 1)
	{
		nbFruit = 0;
	}
	else if (_actualMonth == static_cast<int>(growMonth) - 1) // floraison
	{
		int looseHarvest = getRandomInt(1, 100); // 5% de tout perdre
		if (looseHarvest >= 1 && looseHarvest <= 5)
			nbFruit = 0;
		else
			nbFruit = getRandomInt(minFruit, maxFruit); // nombre de fruits sur l'arbre
	}
	else if (_actualMonth >= static_cast<int>(growMonth) && _actualMonth <= static_cast<int>(harvestMonth)) // pousse
	{
		int Hazard = getRandomInt(3, 10);
		nbFruit -= nbFruit * Hazard / 100;
	}
	if (_actualMonth == static_cast<int>(harvestMonth)) // mois de recolte
	{
		rot = nbFruit / (12 - static_cast<int>(harvestMonth));
	}
	else if (_actualMonth > static_cast<int>(harvestMonth))
	{
		nbFruit -= rot;
	}
}

int Tree::Harvest()
{
	int harvest = nbFruit * fruitWeight;
	nbFruit = 0;
	return harvest;
}
