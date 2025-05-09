#pragma once
#include "Ingredient.h"

class Base : public Ingredient {
	int size = 0;
public:
	Base(std::string name, double add_price, int size) : Ingredient(name, add_price) {
		this->size = size;
	}
	int getSize() const {
		return this->size;
	}
	virtual Base* clone() override {
		return new Base(*this);
	}
};