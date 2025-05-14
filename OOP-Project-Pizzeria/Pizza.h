#pragma once
#include <string>
#include <vector>
#include "Topping.h"
#include "Base.h"

using namespace std;

class Pizza {
	string name;
	int size;
	double price;
	Base* base;
	Topping** ingredients;
	Nutritions* nutritions;
public:
	static const int MAX_INGREDIENTS;
	Pizza(string name, int size);
	Pizza(string name, int size, Base* base);
	Pizza(string name, int size, Base* base, Topping** ingredients);
	Pizza(Pizza* pizza);
	~Pizza();
	string getName() const;
	double getPrice() const;
	void setPrice(double price);
	double calculatePrice();
	int getSize() const;
	Base* getBase();
	bool addTopping(Topping* ingredient);
	bool removeTopping(int index);
	vector<Topping*> getToppings();

	Nutritions* calculateNutritions();
};