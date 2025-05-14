#include "Topping.h"

Topping* Topping::clone()
{
	return new Topping(*this);
}

int Topping::getGrams() const
{
	return this->grams;
}