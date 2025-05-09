#pragma once
#include <string>
#include "Nutritions.h"

class Ingredient {
protected:
	std::string name;
	double price = 0.0;
	Nutritions* nutritions;
public:
	Ingredient(std::string name, double price);
	~Ingredient();
	std::string getName() const;
	double getPrice() const;
	Nutritions* getNutritions() const;
	void setNutritions(Nutritions* nutritions);
	virtual Ingredient* clone() = 0;
};