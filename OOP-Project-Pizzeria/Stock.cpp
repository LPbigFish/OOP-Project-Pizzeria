#include "Stock.h"
#include "Topping.h"

Stock::Stock(Ingredient* ingredient, int quantity)
{
	this->ingredient = ingredient;
	this->quantity = quantity;
}

Ingredient* Stock::getIngredient() const
{
	return this->ingredient;
}

int Stock::getQuantity() const
{
	return this->quantity;
}

void Stock::setQuantity(int quantity)
{
	this->quantity = quantity;
}

void Stock::addQuantity(int amount)
{
	this->quantity += amount;
}

bool Stock::removeQuantity(int amount)
{
	if (this->quantity - amount < 0) {
		return false;
	}
	this->quantity -= amount;
	return true;
}
