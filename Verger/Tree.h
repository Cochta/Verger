#pragma once
#include <string>

enum class Months
{
	Jannuary = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

class Tree
{
public:
	Tree(int _minF, int _maxF, int _fWeight, Months _gMonth, Months _hMonth);

	void Status(int _actualMonth);
	int GetNbFruit() { return nbFruit; }
	int GetFruitWeight() { return fruitWeight; }
	int Harvest();

protected:
	int maxFruit;
	int minFruit;
	int nbFruit;
	int fruitWeight;
	int rot;
	Months growMonth;
	Months harvestMonth;

};
