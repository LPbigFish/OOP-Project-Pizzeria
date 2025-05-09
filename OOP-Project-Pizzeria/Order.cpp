#include "Order.h"

Order::Order(string customerName, string customerAddress, string customerPhone, string customerEmail)
{
	this->customerName = customerName;
	this->customerAddress = customerAddress;
	this->customerPhone = customerPhone;
	this->customerEmail = customerEmail;
	this->totalPrice = 0.0;
	this->pizza = new Pizza * [MAX_PIZZAS];
	for (int i = 0; i < MAX_PIZZAS; i++) {
		this->pizza[i] = nullptr;
	}
}

Order::Order(string customerAddress, string customerPhone)
{
	this->customerName = "";
	this->customerAddress = customerAddress;
	this->customerPhone = customerPhone;
	this->customerEmail = "";
	this->totalPrice = 0.0;
	this->pizza = new Pizza * [MAX_PIZZAS];
	for (int i = 0; i < MAX_PIZZAS; i++) {
		this->pizza[i] = nullptr;
	}
}

void Order::addPizza(Pizza* pizza)
{
	for (int i = 0; i < MAX_PIZZAS; i++) {
		if (this->pizza[i] == nullptr) {
			this->pizza[i] = pizza;
			return;
		}
	}
}

void Order::removePizza(int index)
{
	if (index < 0 || index >= MAX_PIZZAS) {
		return;
	}
	if (this->pizza[index] != nullptr) {
		delete this->pizza[index];
		this->pizza[index] = nullptr;
	}
}

Order::~Order()
{
	for (int i = 0; i < MAX_PIZZAS; i++) {
		if (this->pizza[i] != nullptr) {
			delete this->pizza[i];
		}
	}
	delete[] this->pizza;
}

Pizza** Order::getPizzas() const
{
	return this->pizza;
}

string Order::getCustomerName() const
{
	return this->customerName;
}

string Order::getCustomerAddress() const
{
	return this->customerAddress;
}

string Order::getCustomerPhone() const
{
	return this->customerPhone;
}

string Order::getCustomerEmail() const
{
	return this->customerEmail;
}

double Order::getTotalPrice() const
{
	return this->totalPrice;
}

void Order::calculateTotalPrice()
{
	this->totalPrice = 0.0;
	for (int i = 0; i < MAX_PIZZAS; i++) {
		if (this->pizza[i] != nullptr) {
			this->totalPrice += this->pizza[i]->getPrice();
		}
	}
}
