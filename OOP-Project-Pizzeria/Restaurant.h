#pragma once
#include <string>
#include "Order.h"
#include "Stock.h"
#include "Base.h"
#include "Pizza.h"
#include "Employee.h"
#include "Cook.h"
#include "Waiter.h"
#include "Delivery.h"

using namespace std;

class Restaurant {
	string name;
	string address;
	string phone;
	string email;
	string website;

	Order** orders;
	int max_orders = USHRT_MAX;

	Stock** stock_ingredients;
	int max_stock = USHRT_MAX;

	Employee** employees;
	int max_employees = 20;
public:
	Restaurant(string name, string address, string phone, string email, string website);
	~Restaurant();
	string getName() const;
	string getAddress() const;
	string getPhone() const;
	string getEmail() const;
	string getWebsite() const;
	Pizza* createPizza(string name, int size, Base* base, vector<string> toppings);
	void addOrder(Order* order);
	void removeOrder(int index);
	Order** getOrders() const;
	Stock** getStock() const;
	bool addStock(Stock* stock);
	bool removeStock(int index);
	Stock* getStockByName(string name) const;
	Employee** getEmployees() const;
	bool addEmployee(Employee* employee);
	bool removeEmployee(int index);
	bool removeEmployeeByName(string name);
	Cook* getWorkingCook() const;
	Waiter* getWorkingWaiter() const;
	Delivery* getWorkingDelivery() const;
};