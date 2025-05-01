#pragma once
#include <set>

// Zdroj alergen�: https://www.bidfood.cz/o-nas/novinky/seznam-alergenu
enum ALLERGY {
	LEPEK = 1,
	KOR݊I = 2,
	VEJCE = 3,
	RYBY = 4,
	ARA��DY = 5,
	SOJA = 6,
	MLEKO = 7,
	ORECHY = 8,
	CELER = 9,
	HO��ICE = 10,
	SEZAM = 11,
	OXIDY = 12,
	VL��_BOB = 13,
	M�KK݊I = 14,
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