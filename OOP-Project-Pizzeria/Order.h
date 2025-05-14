#pragma once
#include <string>
#include "Pizza.h"
#include "Status.h"

using namespace std;

class Order
{
protected:
	static long idCounter;
	long id;
	Pizza** pizza;
	const int MAX_PIZZAS = USHRT_MAX;
	string customerName;
	string customerPhone;
	double totalPrice;
	STATUS status = PRIJATO;
	string type;
public:
	Order(string customerName, string customerPhone);
	~Order();
	long getId() const;
	void addPizza(Pizza* pizza);
	void removePizza(int index);
	Pizza** getPizzas() const;
	string getCustomerName() const;
	string getCustomerPhone() const;
	double getTotalPrice();
	string getType() const;
	STATUS getStatus() const;
	void setStatus(STATUS status);
	virtual void calculateTotalPrice();
};
