#pragma once
#include "Employee.h"
#include "Order.h"
#include "DeliveryOrder.h"

class Waiter : public Employee
{
public:
	Waiter(string name, string surname, string phone, string email, string address);
	~Waiter();
	void takeOrder(Order* order);
	void serveOrder(Order* order);
};