#pragma once
#include <set>

// Zdroj alergenù: https://www.bidfood.cz/o-nas/novinky/seznam-alergenu
enum ALLERGY {
	LEPEK = 1,
	KORÝŠI = 2,
	VEJCE = 3,
	RYBY = 4,
	ARAŠÍDY = 5,
	SOJA = 6,
	MLEKO = 7,
	ORECHY = 8,
	CELER = 9,
	HOØÈICE = 10,
	SEZAM = 11,
	OXIDY = 12,
	VLÈÍ_BOB = 13,
	MÌKKÝŠI = 14,
};

class Nutritions {
	// Hodnoty na 100g
	double calories = 0;
	double protein = 0;
	double fat = 0;
	double carbohydrates = 0;
	// Alergeny
	std::set<ALLERGY> allergies;
public:
	Nutritions(double calories, double protein, double fat, double carbohydrates);
	double getCalories() const;
	double getProtein() const;
	double getFat() const;
	double getCarbohydrates() const;
	void addAllergy(ALLERGY allergy);
	std::set<ALLERGY> getAllergies();
};