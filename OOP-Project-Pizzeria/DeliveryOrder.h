#pragma once
#include "Order.h"

class DeliveryOrder : public Order
{
private:
	string deliveryAddress;
	string deliveryTime;
public:
	DeliveryOrder(string customerName, string customerPhone, string deliveryAddress, string deliveryTime);
	~DeliveryOrder();
	string getDeliveryAddress() const;
	string getDeliveryTime() const;
	void calculateTotalPrice() override;
};