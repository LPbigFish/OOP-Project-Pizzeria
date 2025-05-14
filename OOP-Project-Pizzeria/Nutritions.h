#pragma once
#include <set>

class Nutritions {
	// Hodnoty na 100g
	double calories = 0;
	double protein = 0;
	double fat = 0;
	double carbohydrates = 0;
public:
	Nutritions(double calories, double protein, double fat, double carbohydrates);
	double getCalories() const;
	double getProtein() const;
	double getFat() const;
	double getCarbohydrates() const;
	void add(Nutritions* n);
	void info() const;
};