#include "Delivery.h"
#include <iostream>

Delivery::Delivery(string name, string surname, string phone, string email, string address) : Employee(name, surname, phone, email, address, "Delivery")
{

}

Delivery::~Delivery()
{

}

void Delivery::deliverOrder(DeliveryOrder* order)
{
	if (order != nullptr) {
		order->calculateTotalPrice();
		cout << "Order delivered to: " << order->getDeliveryAddress() << endl;
		order->setStatus(DORUCENO);
		cout << "Order status: " << statusToString(order->getStatus()) << endl;
	}
	else {
		cout << "Error" << endl;
	}
}