#include <iostream>
#include "Restaurant.h"

int main() {
	Restaurant* restaurant = new Restaurant("Džonofo", "Praha", "+420 123 456 789", "info@dzonofo.cz", "www.dzonofo.cz");

	// Test Stock
	vector<Stock*> t = Stock::test_stock();
	while (t.size() > 0) {

		restaurant->addStock(t.front());
		t.pop_back();
	}

	return 0;
}