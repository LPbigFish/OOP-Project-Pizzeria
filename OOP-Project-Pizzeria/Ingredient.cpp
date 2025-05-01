#include "Ingredient.h"

Ingredient::Ingredient(string name, double add_price, int grams)
{
	this->name = name;
	this->add_price = add_price;
	this->grams = grams;
	this->nutritions = nullptr;
}

Ingredient::~Ingredient()
{
	if (this->nutritions != nullptr) {
		delete this->nutritions;
	}
}

string Ingredient::getName()
{
	return this->name;
}

double Ingredient::getPrice() const
{
	return this->add_price;
}
int Ingredient::getGrams() const
{
	return this->grams;
}

Nutritions* Ingredient::getNutritions()
{
	return this->nutritions;
}

void Ingredient::setNutritions(Nutritions* nutritions)
{
	this->nutritions = nutritions;
}

