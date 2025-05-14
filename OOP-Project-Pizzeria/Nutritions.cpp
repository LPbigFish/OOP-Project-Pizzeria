#include "Nutritions.h"
#include <iostream>

Nutritions::Nutritions(double calories, double protein, double fat, double carbohydrates)
{
	this->calories = calories;
	this->protein = protein;
	this->fat = fat;
	this->carbohydrates = carbohydrates;
}

double Nutritions::getCalories() const
{
	return this->calories;
}

double Nutritions::getProtein() const
{
	return this->protein;
}

double Nutritions::getFat() const
{
	return this->fat;
}

double Nutritions::getCarbohydrates() const
{
	return this->carbohydrates;
}

void Nutritions::add(Nutritions* n)
{
	this->calories += n->getCalories();
	this->protein += n->getProtein();
	this->fat += n->getFat();
	this->carbohydrates += n->getCarbohydrates();
}

void Nutritions::info() const
{
	std::cout << "Nutrièní údaje: " << std::endl;
	std::cout << "Kalorie: " << this->getCalories() << " kcal" << std::endl;
	std::cout << "Bílkoviny: " << this->getProtein() << " g" << std::endl;
	std::cout << "Sacharidy: " << this->getCarbohydrates() << " g" << std::endl;
	std::cout << "Tuky: " << this->getFat() << " g" << std::endl;
}
