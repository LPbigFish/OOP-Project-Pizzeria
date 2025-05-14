#pragma once
#include "Employee.h"
#include "DeliveryOrder.h"

class Delivery : public Employee
{
public:
	Delivery(string name, string surname, string phone, string email, string address);
	~Delivery();
	void deliverOrder(DeliveryOrder* order);
};