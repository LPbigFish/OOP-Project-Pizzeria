#pragma once
#include "Ingredient.h"

#include <string>
#include <vector>

using namespace std;

class Topping : public Ingredient {
private:
	int grams = 0;
public:
	Topping(string name, double add_price, int grams) : Ingredient(name, add_price) {
		this->grams = grams;
	}
	int getGrams() const;
	virtual Topping* clone() override;
};