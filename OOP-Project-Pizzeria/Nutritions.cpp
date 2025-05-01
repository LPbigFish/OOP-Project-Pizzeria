#include "Nutritions.h"

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

void Nutritions::addAllergy(ALLERGY allergy)
{
	this->allergies.insert(allergy);
}

std::set<ALLERGY> Nutritions::getAllergies()
{
	return this->allergies;
}

