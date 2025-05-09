#pragma once
#include <string>
#include "Pizza.h"

using namespace std;

class Order
{
private:
	Pizza** pizza;
	const int MAX_PIZZAS = USHRT_MAX;
	string customerName;
	string customerAddress;
	string customerPhone;
	string customerEmail;
	double totalPrice;

public:
	Order(string customerName, string customerAddress, string customerPhone, string customerEmail);
	Order(string customerAddress, string customerPhone);
	~Order();
	void addPizza(Pizza* pizza);
	void removePizza(int index);
	Pizza** getPizzas() const;
	string getCustomerName() const;
	string getCustomerAddress() const;
	string getCustomerPhone() const;
	string getCustomerEmail() const;
	double getTotalPrice() const;
	void calculateTotalPrice();
};
