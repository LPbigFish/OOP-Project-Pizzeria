#pragma once
#include "Ingredient.h"
#include <vector>

using namespace std;

class Stock {
private:
	Ingredient* ingredient;
	int quantity = 0;
public:
	Stock(Ingredient* ingredient, int quantity);

	Ingredient* getIngredient() const;

	int getQuantity() const;

	void setQuantity(int quantity);

	void addQuantity(int amount);

	bool removeQuantity(int amount);

	static vector<Stock*> test_stock();
};