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
	~Topping();
	virtual Topping* clone() override;

	static vector<Topping*> test_toppings();
};