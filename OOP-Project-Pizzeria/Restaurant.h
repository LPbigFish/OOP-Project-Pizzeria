#pragma once
#include <string>
#include "Order.h"
#include "Stock.h"
#include "Base.h"

using namespace std;

class Restaurant {
	string name;
	string address;
	string phone;
	string email;
	string website;

	Order** orders;
	int max_orders = USHRT_MAX;

	Pizza** pizzas;
	int max_pizzas = USHRT_MAX;

	Stock** stock_ingredients;
	int max_stock = USHRT_MAX;

public:
	Restaurant(string name, string address, string phone, string email, string website);
	~Restaurant();
	string getName() const;
	string getAddress() const;
	string getPhone() const;
	string getEmail() const;
	string getWebsite() const;
	bool createPizza(string name, double price, int size, Base* base, vector<string> toppings);
	Order* createOrder(string customerAddress, string customerPhone);
	void addOrder(Order* order);
	void removeOrder(int index);
	Order** getOrders() const;
	Pizza** getPizzas() const;
	Stock** getStock() const;
	bool addStock(Stock* stock);
	bool removeStock(int index);
	Stock* getStockByName(string name) const;
};