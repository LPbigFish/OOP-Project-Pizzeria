#include "Waiter.h"
#include <iostream>

Waiter::Waiter(string name, string surname, string phone, string email, string address) : Employee(name, surname, phone, email, address, "Waiter")
{
}

Waiter::~Waiter()
{
}

void Waiter::takeOrder(Order* order) {
	if (order != nullptr) {
		order->calculateTotalPrice();
		cout << "Order taken for: " << order->getCustomerName() << endl;
		order->setStatus(PRIJATO);
		cout << "Order status: " << statusToString(order->getStatus()) << endl;
	}
	else {
		cout << "Error" << endl;
	}
}

void Waiter::serveOrder(Order* order) {
	if (order != nullptr) {
		cout << "Order served to: " << order->getCustomerName() << endl;
		order->setStatus(HOTOVO);
		cout << "Order status: " << statusToString(order->getStatus()) << endl;
	}
	else {
		cout << "Error" << endl;
	}
}
