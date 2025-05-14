#include "Ingredient.h"


Ingredient::Ingredient(std::string name, double add_price)
{
	this->name = name;
	this->price = add_price;
	this->nutritions = nullptr;
}

Ingredient::~Ingredient()
{
	if (this->nutritions != nullptr) {
		delete this->nutritions;
	}
}

std::string Ingredient::getName() const
{
	return this->name;
}

double Ingredient::getPrice() const
{
	return this->price;
}

Nutritions* Ingredient::getNutritions() const
{
	return this->nutritions;
}

void Ingredient::setNutritions(Nutritions* nutritions)
{
	this->nutritions = nutritions;
}

