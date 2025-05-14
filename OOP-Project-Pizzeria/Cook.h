#pragma once
#include "Employee.h"
#include "Order.h"

class Cook : public Employee
{
public:
	Cook(string name, string surname, string phone, string email, string address);
	~Cook();
	void prepareOrder(Order* order);
};