#include "Pizza.h"

const int Pizza::MAX_INGREDIENTS = 10;

Pizza::Pizza(string name, double price, int size)
{
	this->name = name;
	this->price = price;
	this->size = size;
	this->base = nullptr;
	this->ingredients = new Ingredient * [MAX_INGREDIENTS];
	for (int i = 0; i < MAX_INGREDIENTS; i++) {
		this->ingredients[i] = nullptr;
	}
}

Pizza::Pizza(string name, double price, int size, Ingredient* base)
{
	this->name = name;
	this->price = price;
	this->size = size;
	this->base = base;
	this->ingredients = new Ingredient * [MAX_INGREDIENTS];
	for (int i = 0; i < MAX_INGREDIENTS; i++) {
		this->ingredients[i] = nullptr;
	}
}

Pizza::Pizza(string name, double price, int size, Ingredient* base, Ingredient** ingredients)
{
	this->name = name;
	this->price = price;
	this->size = size;
	this->base = base;
	this->ingredients = new Ingredient * [MAX_INGREDIENTS];
	for (int i = 0; i < MAX_INGREDIENTS; i++) {
		this->ingredients[i] = nullptr;
	}
	for (int i = 0; i < MAX_INGREDIENTS; i++) {
		if (ingredients[i] != nullptr) {
			this->addIngredient(ingredients[i]);
		}
	}
}

Pizza::~Pizza()
{
	delete[] this->ingredients;
}

bool Pizza::addIngredient(Ingredient* ingredient)
{
	for (int i = 0; i < MAX_INGREDIENTS; i++) {
		if (this->ingredients[i] == nullptr) {
			this->ingredients[i] = ingredient;
			return true;
		}
	}
	return false;
}

bool Pizza::removeIngredient(int index)
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

vector<Ingredient*> Pizza::getIngredients()
{
	vector<Ingredient*> ingredients;
	for (int i = 0; i < MAX_INGREDIENTS; i++) {
		if (this->ingredients[i] != nullptr) {
			ingredients.push_back(this->ingredients[i]);
		}
	}
	return ingredients;
}