#include "Topping.h"

Topping::~Topping()
{
	if (this->nutritions != nullptr) {
		delete this->nutritions;
	}
}

Topping* Topping::clone()
{
	return new Topping(*this);
}

vector<Topping*> Topping::test_toppings() {
	vector<Topping*> toppings;
	toppings.push_back(new Topping("Mozzarella", 20, 100));
	toppings.front()->setNutritions(new Nutritions(300, 20, 10, 5));
	toppings.push_back(new Topping("Šunka", 30, 100));
	toppings.front()->setNutritions(new Nutritions(250, 25, 15, 0));
	toppings.push_back(new Topping("Pepperoni", 40, 100));
	toppings.front()->setNutritions(new Nutritions(350, 30, 20, 0));
	toppings.push_back(new Topping("Houbová smìs", 25, 100));
	toppings.front()->setNutritions(new Nutritions(200, 10, 5, 10));
	toppings.push_back(new Topping("Ananas", 15, 70));
	toppings.front()->setNutritions(new Nutritions(100, 1, 0, 20));
	toppings.push_back(new Topping("Olivy", 20, 50));
	toppings.front()->setNutritions(new Nutritions(150, 5, 10, 5));
	toppings.push_back(new Topping("Oregáno", 10, 5));
	toppings.front()->setNutritions(new Nutritions(50, 0, 0, 0));
	toppings.push_back(new Topping("Chilli", 5, 2));
	toppings.front()->setNutritions(new Nutritions(20, 0, 0, 0));
	toppings.push_back(new Topping("Slanina", 35, 100));
	toppings.front()->setNutritions(new Nutritions(400, 30, 35, 0));
	return toppings;
}

int Topping::getGrams() const
{
	return this->grams;
}