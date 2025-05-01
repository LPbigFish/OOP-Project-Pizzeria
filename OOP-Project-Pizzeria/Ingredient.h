#pragma once

#include "Nutritions.h"

#include <string>
#include <vector>

using namespace std;

class Ingredient {
	string name;
	double add_price;
	int grams;
	Nutritions* nutritions;
public:
	Ingredient(string name, double add_price, int grams);
	~Ingredient();
	string getName();
	double getPrice() const;
	int getGrams() const;
	Nutritions* getNutritions();
	void setNutritions(Nutritions* nutritions);
};