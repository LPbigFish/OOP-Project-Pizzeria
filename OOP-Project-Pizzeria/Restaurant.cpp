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
	this->stock_ingredients = new Stock * [max_stock];
	for (int i = 0; i < max_stock; i++) {
		this->stock_ingredients[i] = nullptr;
	}
	this->employees = new Employee * [max_employees];
	for (int i = 0; i < max_employees; i++) {
		this->employees[i] = nullptr;
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
	for (int i = 0; i < max_stock; i++) {
		if (this->stock_ingredients[i] != nullptr) {
			delete this->stock_ingredients[i];
		}
	}
	delete[] this->stock_ingredients;
	for (int i = 0; i < max_employees; i++) {
		if (this->employees[i] != nullptr) {
			delete this->employees[i];
		}
	}
	delete[] this->employees;
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

Pizza* Restaurant::createPizza(string name, int size, Base* base, vector<string> toppings)
{
	// Kotronla zda jsou všechny suroviny dostupné
	int totalToppings = 0;
	for (string toppingName : toppings) {
		for (int j = 0; j < max_stock; j++) {
			if (this->stock_ingredients[j] != nullptr && this->stock_ingredients[j]->getIngredient()->getName() == toppingName && this->stock_ingredients[j]->getQuantity() > 0) {
				totalToppings++;
				break;
			}
		}
	}
	if (totalToppings != toppings.size()) {
		return nullptr;
	}

	// Vytvoøení pizzy
	Pizza* pizza = new Pizza(name, size, base);
	for (string toppingName : toppings) {
		for (int j = 0; j < max_stock; j++) {
			if (this->stock_ingredients[j] != nullptr && this->stock_ingredients[j]->getIngredient()->getName() == toppingName) {
				pizza->addTopping(((Topping*) this->stock_ingredients[j]->getIngredient()));
				this->stock_ingredients[j]->removeQuantity(1);
				break;
			}
		}
	}
	return pizza;
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

Employee** Restaurant::getEmployees() const
{
	return this->employees;
}

bool Restaurant::addEmployee(Employee* employee)
{
	for (int i = 0; i < max_employees; i++) {
		if (this->employees[i] == nullptr) {
			this->employees[i] = employee;
			return true;
		}
	}
	return false;
}

bool Restaurant::removeEmployee(int index)
{
	if (index < 0 || index >= max_employees) {
		return false;
	}
	if (this->employees[index] != nullptr) {
		delete this->employees[index];
		this->employees[index] = nullptr;
		return true;
	}
	return false;
}

bool Restaurant::removeEmployeeByName(string name)
{
	for (int i = 0; i < max_employees; i++) {
		if (this->employees[i] != nullptr && this->employees[i]->getName() == name) {
			delete this->employees[i];
			this->employees[i] = nullptr;
			return true;
		}
	}
	return false;
}

Cook* Restaurant::getWorkingCook() const
{
	for (int i = 0; i < max_employees; i++) {
		if (this->employees[i] != nullptr && this->employees[i]->getPosition() == "Cook" && this->employees[i]->isWorking()) {
			return (Cook*)this->employees[i];
		}
	}
	return nullptr;
}

Waiter* Restaurant::getWorkingWaiter() const
{
	for (int i = 0; i < max_employees; i++) {
		if (this->employees[i] != nullptr && this->employees[i]->getPosition() == "Waiter" && this->employees[i]->isWorking()) {
			return (Waiter*)this->employees[i];
		}
	}
	return nullptr;
}

Delivery* Restaurant::getWorkingDelivery() const
{
	for (int i = 0; i < max_employees; i++) {
		if (this->employees[i] != nullptr && this->employees[i]->getPosition() == "Delivery" && this->employees[i]->isWorking()) {
			return (Delivery*)this->employees[i];
		}
	}
	return nullptr;
}
