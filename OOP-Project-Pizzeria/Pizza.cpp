#include "Pizza.h"

const int Pizza::MAX_INGREDIENTS = 10;

Pizza::Pizza(string name, double price, int size)
{
	this->name = name;
	this->price = price;
	this->size = size;
	this->base = nullptr;
	this->ingredients = new Topping * [MAX_INGREDIENTS];
	for (int i = 0; i < MAX_INGREDIENTS; i++) {
		this->ingredients[i] = nullptr;
	}
}

Pizza::Pizza(string name, double price, int size, Base* base)
{
	this->name = name;
	this->price = price;
	this->size = size;
	this->base = base;
	this->ingredients = new Topping * [MAX_INGREDIENTS];
	for (int i = 0; i < MAX_INGREDIENTS; i++) {
		this->ingredients[i] = nullptr;
	}
}

Pizza::Pizza(string name, double price, int size, Base* base, Topping** ingredients)
{
	this->name = name;
	this->price = price;
	this->size = size;
	this->base = base;
	this->ingredients = new Topping * [MAX_INGREDIENTS];
	for (int i = 0; i < MAX_INGREDIENTS; i++) {
		this->ingredients[i] = nullptr;
	}
	for (int i = 0; i < MAX_INGREDIENTS; i++) {
		if (ingredients[i] != nullptr) {
			this->addTopping(ingredients[i]);
		}
	}
}

Pizza::Pizza(Pizza* pizza)
{
	this->name = pizza->name;
	this->price = pizza->price;
	this->size = pizza->size;
	this->base = pizza->base;
	this->ingredients = new Topping * [MAX_INGREDIENTS];
	for (int i = 0; i < MAX_INGREDIENTS; i++) {
		if (pizza->ingredients[i] != nullptr) {
			this->ingredients[i] = new Topping(*pizza->ingredients[i]);
		}
		else {
			this->ingredients[i] = nullptr;
		}
	}
}

Pizza::~Pizza()
{
	delete[] this->ingredients;
}

string Pizza::getName() const
{
	return this->name;
}

double Pizza::getPrice() const
{
	return this->price;
}

void Pizza::setPrice(double price)
{
	this->price = price;
}

void Pizza::calculatePrice() {
	double totalPrice = 0;
	for (int i = 0; i < MAX_INGREDIENTS; i++) {
		if (this->ingredients[i] != nullptr) {
			totalPrice += this->ingredients[i]->getPrice();
		}
	}
	this->price += totalPrice;
}

int Pizza::getSize() const
{
	return this->size;
}

Base* Pizza::getBase() const
{
	return this->base;
}

bool Pizza::addTopping(Topping* ingredient)
{
	for (int i = 0; i < MAX_INGREDIENTS; i++) {
		if (this->ingredients[i] == nullptr) {
			this->ingredients[i] = ingredient;
			return true;
		}
	}
	return false;
}

bool Pizza::removeTopping(int index)
{
	if (index < 0 || index >= MAX_INGREDIENTS) {
		return false;
	}
	if (this->ingredients[index] != nullptr) {
		delete this->ingredients[index];
		this->ingredients[index] = nullptr;
		return true;
	}
	return false;
}

vector<Topping*> Pizza::getToppings()
{
	vector<Topping*> ingredients;
	for (int i = 0; i < MAX_INGREDIENTS; i++) {
		if (this->ingredients[i] != nullptr) {
			ingredients.push_back(this->ingredients[i]);
		}
	}
	return ingredients;
}

Nutritions* Pizza::calculateNutritions() const
{
	Nutritions* nutritions = new Nutritions(0, 0, 0, 0);
	if (this->base != nullptr) {
		nutritions->add(this->base->getNutritions());
	}
	for (int i = 0; i < MAX_INGREDIENTS; i++) {
		if (this->ingredients[i] != nullptr) {
			nutritions->add(this->ingredients[i]->getNutritions());
		}
	}
	return nutritions;
}

Pizza* Pizza::clone() const
{
	return new Pizza(*this);
}
