#include "DeliveryOrder.h"

DeliveryOrder::DeliveryOrder(string customerName, string customerPhone, string deliveryAddress, string deliveryTime) : Order(customerName, customerPhone)
{
	this->deliveryAddress = deliveryAddress;
	this->deliveryTime = deliveryTime;

	this->type = "Doruèení";
}

DeliveryOrder::~DeliveryOrder()
{
	for (int i = 0; i < MAX_PIZZAS; i++)
	{
		if (pizza[i] != nullptr)
		{
			delete pizza[i];
			pizza[i] = nullptr;
		}
	}
	delete[] pizza;
}

string DeliveryOrder::getDeliveryAddress() const
{
	return deliveryAddress;
}

string DeliveryOrder::getDeliveryTime() const
{
	return deliveryTime;
}

void DeliveryOrder::calculateTotalPrice()
{
	// Cena za doruèení
	totalPrice = 30;

	for (int i = 0; i < MAX_PIZZAS; i++)
	{
		if (pizza[i] != nullptr)
		{
			totalPrice += pizza[i]->getPrice();
		}
	}
}
