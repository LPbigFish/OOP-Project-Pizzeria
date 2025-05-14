#include "Order.h"

long Order::idCounter = 0;

Order::Order(string customerName, string customerPhone)
{
	this->idCounter++;
	this->id = idCounter;
	this->customerName = customerName;
	this->customerPhone = customerPhone;
	this->totalPrice = 0.0;
	this->type = "Odbìr";
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
	idCounter--;
	for (int i = 0; i < MAX_PIZZAS; i++) {
		if (this->pizza[i] != nullptr) {
			delete this->pizza[i];
		}
	}
	delete[] this->pizza;
}

long Order::getId() const
{
	return this->id;
}

Pizza** Order::getPizzas() const
{
	return this->pizza;
}

string Order::getCustomerName() const
{
	return this->customerName;
}

string Order::getCustomerPhone() const
{
	return this->customerPhone;
}

double Order::getTotalPrice()
{
	calculateTotalPrice();
	return this->totalPrice;
}

string Order::getType() const
{
	return this->type;
}

STATUS Order::getStatus() const
{
	return this->status;
}

void Order::setStatus(STATUS status)
{
	this->status = status;
}

void Order::calculateTotalPrice()
{
	this->totalPrice = 0.0;
	for (int i = 0; i < MAX_PIZZAS; i++) {
		if (this->pizza[i] != nullptr) {
			this->totalPrice += this->pizza[i]->calculatePrice();
		}
	}
}
