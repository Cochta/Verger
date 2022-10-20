#pragma once
#include <iostream>
#include <format>

inline int EnterValue(const std::string _waitedValue, int _min, int _max)
{
	int value;
	std::cout << "Enter a Value to set your " << _waitedValue << " number (max = " << _max << "): " << std::endl;
	while (std::cin >> value) {// allows the user to only input numerical values
		if (value >= _min && value <= _max)
		{
			break;
		}
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Invalid input, (it must be a number less or equal to :" << _max << ")  Try again: ";
	}
	return value;
}

inline float YearPass(Verger _verger, int _harvestMonth)
{
	int harvest = 0;
	for (int i = 1; i <= 12; ++i)
	{
		std::cout << std::format("{: >{}}", i, 2) << " : ";
		for (Tree& tree : _verger.trees)
		{
			tree.Status(i);
			std::cout << std::format("{: >{}}", tree.GetNbFruit(), 5) << " | ";
		}
		std::cout << std::endl;
		if (i == _harvestMonth)
		{
			harvest = _verger.HarvestVerger();
		}
	}
	return static_cast<float>(harvest) / 1000;
}
