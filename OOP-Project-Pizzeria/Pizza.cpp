#include "Pizza.h"

const int Pizza::MAX_INGREDIENTS = 10;

Pizza::Pizza(string name, int size)
{
	this->name = name;
	this->size = size;
	this->base = nullptr;
	this->nutritions = nullptr;
	this->ingredients = new Topping * [MAX_INGREDIENTS];
	for (int i = 0; i < MAX_INGREDIENTS; i++) {
		this->ingredients[i] = nullptr;
	}
}

Pizza::Pizza(string name, int size, Base* base)
{
	this->name = name;
	this->size = size;
	this->base = base;
	this->nutritions = nullptr;
	this->ingredients = new Topping * [MAX_INGREDIENTS];
	for (int i = 0; i < MAX_INGREDIENTS; i++) {
		this->ingredients[i] = nullptr;
	}
}

Pizza::Pizza(string name, int size, Base* base, Topping** ingredients)
{
	this->name = name;
	this->size = size;
	this->base = base;
	this->nutritions = nullptr;
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
	this->nutritions = nullptr;
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
	delete this->nutritions;
	if (this->base != nullptr) {
		delete this->base;
	}
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

double Pizza::calculatePrice() {
	double totalPrice = 60;
	for (int i = 0; i < MAX_INGREDIENTS; i++) {
		if (this->ingredients[i] != nullptr) {
			totalPrice += this->ingredients[i]->getPrice();
		}
	}
	return this->price = totalPrice;
}

int Pizza::getSize() const
{
	return this->size;
}

Base* Pizza::getBase()
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

Nutritions* Pizza::calculateNutritions()
{
	Nutritions* nutritions = new Nutritions(542, 104, 6.8, 15.8);
	for (int i = 0; i < MAX_INGREDIENTS; i++) {
		if (this->ingredients[i] != nullptr) {
			nutritions->add(this->ingredients[i]->getNutritions());
		}
		else {
			break;
		}
	}
	return this->nutritions = nutritions;
}
