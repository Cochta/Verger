#include <iostream>
#include "VergerCl.h"
#include"Controller.h"

int main()
{
	const Verger verger;
	const int years = EnterValue("years", 1, 10);
	for (int j = 1; j <= years; ++j)
	{
		const int harvestMonth = EnterValue("harvest month", 1, 12);
		system("cls");
		std::cout << "Year " << j << std::endl;
		const float HarvestedFruits = YearPass(verger, harvestMonth);
		std::cout << "You harvested : " << HarvestedFruits << " fruit kg." << std::endl << "You need to harvest 2000 kg of fruits.." << std::endl;
	}
}