#pragma once
#include <string>
#include <vector>
#include "Ingredient.h"

using namespace std;

class Pizza {
	string name;
	int size;
	double price;
	Ingredient* base;
	Ingredient** ingredients;
public:
	static const int MAX_INGREDIENTS;
	Pizza(string name, double price, int size);
	Pizza(string name, double price, int size, Ingredient* base);
	Pizza(string name, double price, int size, Ingredient* base, Ingredient** ingredients);
	~Pizza();
	bool addIngredient(Ingredient* ingredient);
	bool removeIngredient(int index);
	vector<Ingredient*> getIngredients();
};