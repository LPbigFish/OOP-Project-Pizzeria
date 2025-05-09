#include "Restaurant.h"

Restaurant::Restaurant(string name, string address, string phone, string email, string website)
{
	this->name = name;
	this->address = address;
	this->phone = phone;
	this->email = email;
	this->website = website;
	this->orders = new Order * [max_orders];
	for (int i = 0; i < max_orders; i++) {
		this->orders[i] = nullptr;
	}
	this->pizzas = new Pizza * [max_pizzas];
	for (int i = 0; i < max_pizzas; i++) {
		this->pizzas[i] = nullptr;
	}
	this->stock_ingredients = new Stock * [max_stock];
	for (int i = 0; i < max_stock; i++) {
		this->stock_ingredients[i] = nullptr;
	}
}

Restaurant::~Restaurant()
{
	for (int i = 0; i < max_orders; i++) {
		if (this->orders[i] != nullptr) {
			delete this->orders[i];
		}
	}
	delete[] this->orders;
	for (int i = 0; i < max_pizzas; i++) {
		if (this->pizzas[i] != nullptr) {
			delete this->pizzas[i];
		}
	}
	delete[] this->pizzas;
	for (int i = 0; i < max_stock; i++) {
		if (this->stock_ingredients[i] != nullptr) {
			delete this->stock_ingredients[i];
		}
	}
	delete[] this->stock_ingredients;
}

string Restaurant::getName() const
{
	return this->name;
}

string Restaurant::getAddress() const
{
	return this->address;
}

string Restaurant::getPhone() const
{
	return this->phone;
}

string Restaurant::getEmail() const
{
	return this->email;
}

string Restaurant::getWebsite() const
{
	return this->website;
}

bool Restaurant::createPizza(string name, double price, int size, Base* base, vector<string> toppings)
{
	for (int i = 0; i < max_pizzas; i++) {
		if (this->pizzas[i] == nullptr) {
			this->pizzas[i] = new Pizza(name, price, size, base);
			for (string toppingName : toppings) {
				for (int j = 0; j < max_stock; j++) {
					if (this->stock_ingredients[j] != nullptr && this->stock_ingredients[j]->getIngredient()->getName() == toppingName) {
						this->pizzas[i]->addTopping(((Topping*) this->stock_ingredients[j]->getIngredient()));
						break;
					}
				}
			}
			return true;
		}
	}
}

Order* Restaurant::createOrder(string customerAddress, string customerPhone)
{
	for (int i = 0; i < max_orders; i++) {
		if (this->orders[i] == nullptr) {
			this->orders[i] = new Order(customerAddress, customerPhone);
			return this->orders[i];
		}
	}
	return nullptr;
}

void Restaurant::addOrder(Order* order)
{
	for (int i = 0; i < max_orders; i++) {
		if (this->orders[i] == nullptr) {
			this->orders[i] = order;
			return;
		}
	}
}

void Restaurant::removeOrder(int index)
{
	if (index < 0 || index >= max_orders) {
		return;
	}
	if (this->orders[index] != nullptr) {
		delete this->orders[index];
		this->orders[index] = nullptr;
	}
}

Order** Restaurant::getOrders() const
{
	return this->orders;
}

Pizza** Restaurant::getPizzas() const
{
	return this->pizzas;
}

Stock** Restaurant::getStock() const
{
	return this->stock_ingredients;
}

bool Restaurant::addStock(Stock* stock)
{
	for (int i = 0; i < max_stock; i++) {
		if (this->stock_ingredients[i] == nullptr) {
			this->stock_ingredients[i] = stock;
			return true;
		}
	}
	return false;
}

bool Restaurant::removeStock(int index)
{
	if (index < 0 || index >= max_stock) {
		return false;
	}
	if (this->stock_ingredients[index] != nullptr) {
		delete this->stock_ingredients[index];
		this->stock_ingredients[index] = nullptr;
		return true;
	}
	return false;
}

Stock* Restaurant::getStockByName(string name) const
{
	for (int i = 0; i < max_stock; i++) {
		if (this->stock_ingredients[i] != nullptr && this->stock_ingredients[i]->getIngredient()->getName() == name) {
			return this->stock_ingredients[i];
		}
	}
	return nullptr;
}