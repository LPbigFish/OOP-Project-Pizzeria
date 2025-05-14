#include "Cook.h"
#include <iostream>

Cook::Cook(string name, string surname, string phone, string email, string address) : Employee(name, surname, phone, email, address, "Cook")
{
}

Cook::~Cook()
{
}

void Cook::prepareOrder(Order* order)
{
	if (order != nullptr) {
		order->calculateTotalPrice();
		cout << "Order prepared for: " << order->getCustomerName() << endl;
		order->setStatus(PRIPRAVUJEME);
		cout << "Order status: " << statusToString(order->getStatus()) << endl;
	}
	else {
		cout << "Error" << endl;
	}
}