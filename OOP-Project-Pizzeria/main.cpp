#include <iostream>
#include "Restaurant.h"
#include "Waiter.h"
#include "Cook.h"
#include "Delivery.h"
#include "Topping.h"

int main() {
	// Vytvoøení restaurace
	Restaurant* restaurant = new Restaurant("Džonofo", "Praha", "+420 123 456 789", "info@dzonofo.cz", "www.dzonofo.cz");

	cout << "Restaurant: " << restaurant->getName() << ", Address: " << restaurant->getAddress() << ", Phone: " << restaurant->getPhone() << ", Email: " << restaurant->getEmail() << ", Website: " << restaurant->getWebsite() << endl;

	cout << endl;

	// Vytvoøení surovin
	vector<Topping*> toppings;
	toppings.push_back(new Topping("Mozzarella", 20, 100));
	toppings.back()->setNutritions(new Nutritions(300, 20, 10, 5));
	toppings.push_back(new Topping("Šunka", 30, 100));
	toppings.back()->setNutritions(new Nutritions(250, 25, 15, 0));
	toppings.push_back(new Topping("Pepperoni", 40, 100));
	toppings.back()->setNutritions(new Nutritions(350, 30, 20, 0));
	toppings.push_back(new Topping("Houbová smìs", 25, 100));
	toppings.back()->setNutritions(new Nutritions(200, 10, 5, 10));
	toppings.push_back(new Topping("Ananas", 15, 70));
	toppings.back()->setNutritions(new Nutritions(100, 1, 0, 20));
	toppings.push_back(new Topping("Olivy", 20, 50));
	toppings.back()->setNutritions(new Nutritions(150, 5, 10, 5));
	toppings.push_back(new Topping("Oregáno", 10, 5));
	toppings.back()->setNutritions(new Nutritions(50, 0, 0, 0));
	toppings.push_back(new Topping("Chilli", 5, 2));
	toppings.back()->setNutritions(new Nutritions(20, 0, 0, 0));
	toppings.push_back(new Topping("Slanina", 35, 100));
	toppings.back()->setNutritions(new Nutritions(400, 30, 35, 0));

	// Pøidání surovin do "skladu"
	vector<Stock*> stock;
	while (toppings.size() != 0) {
		stock.push_back(new Stock(toppings.back(), 100));
		cout << "Ingrediece: " << stock.back()->getIngredient()->getName() << ", Množství: " << stock.back()->getQuantity() << endl;
		restaurant->addStock(stock.back());
		toppings.pop_back();
	}

	cout << endl;

	// Pøidání zamìstnancù
	// 
	// Èíšníci
	Waiter* w1 = new Waiter("Don", "W.", "+420 713 923 919", "email@gmail.com", "Praha 6");
	cout << "Èíšník: " << w1->getName()
		<< ", Tel: " << w1->getPhone()
		<< ", Email: " << w1->getEmail()
		<< ", Adresa: " << w1->getAddress() << endl;
	restaurant->addEmployee(w1);

	Waiter* w2 = new Waiter("Den", "E.", "+420 831 328 382", "email1@gmail.com", "Praha 7");
	cout << "Èíšník: " << w2->getName()
		<< ", Tel: " << w2->getPhone()
		<< ", Email: " << w2->getEmail()
		<< ", Adresa: " << w2->getAddress() << endl;
	restaurant->addEmployee(w2);

	Waiter* w3 = new Waiter("Dan", "F.", "+420 841 328 382", "email2@gmail.com", "Praha 1");
	cout << "Èíšník: " << w3->getName()
		<< ", Tel: " << w3->getPhone()
		<< ", Email: " << w3->getEmail()
		<< ", Adresa: " << w3->getAddress() << endl;
	restaurant->addEmployee(w3);

	cout << endl;

	// Kuchaøi
	Cook* c1 = new Cook("Emil", "S.", "+420 245 593 302", "email3@gmail.com", "Praha 2");
	cout << "Kuchaø: " << c1->getName()
		<< ", Tel: " << c1->getPhone()
		<< ", Email: " << c1->getEmail()
		<< ", Adresa: " << c1->getAddress() << endl;
	restaurant->addEmployee(c1);

	Cook* c2 = new Cook("Emanuel", "N.", "+420 241 593 602", "email5@gmail.com", "Praha 3");
	cout << "Kuchaø: " << c2->getName()
		<< ", Tel: " << c2->getPhone()
		<< ", Email: " << c2->getEmail()
		<< ", Adresa: " << c2->getAddress() << endl;
	restaurant->addEmployee(c2);

	cout << endl;

	// Doruèovatel
	Delivery* d1 = new Delivery("Alton", "D.", "+420 943 120 492", "email6@gmail.com", "Praha 4");
	cout << "Doruèovatel: " << d1->getName()
		<< ", Tel: " << d1->getPhone()
		<< ", Email: " << d1->getEmail()
		<< ", Adresa: " << d1->getAddress() << endl;
	restaurant->addEmployee(d1);

	cout << endl;

	cout << endl;

	// 6 Pizz
	Pizza* p1 = restaurant->createPizza("Margherita", 32, new Base("Rajèatová", 10, 32), {"Mozzarella", "Oregáno"});
	cout << "Pizza: " << p1->getName() << ", Cena: " << p1->calculatePrice() << " Kè, Velikost: " << p1->getSize() << " cm" << endl;
	p1->calculateNutritions()->info();

	cout << endl;

	Pizza* p2 = restaurant->createPizza("Hawaiian", 32, new Base("Rajèatová", 10, 32), { "Mozzarella", "Šunka", "Ananas" });
	cout << "Pizza: " << p2->getName() << ", Cena: " << p2->calculatePrice() << " Kè, Velikost: " << p2->getSize() << " cm" << endl;
	p2->calculateNutritions()->info();
	cout << endl;

	Pizza* p3 = restaurant->createPizza("Pepperoni", 32, new Base("Rajèatová", 10, 32), { "Mozzarella", "Pepperoni" });
	cout << "Pizza: " << p3->getName() << ", Cena: " << p3->calculatePrice() << " Kè, Velikost: " << p3->getSize() << " cm" << endl;
	p3->calculateNutritions()->info();

	cout << endl;

	Pizza* p4 = restaurant->createPizza("Vegetarian", 32, new Base("Rajèatová", 10, 32), { "Mozzarella", "Houbová smìs", "Olivy" });
	cout << "Pizza: " << p4->getName() << ", Cena: " << p4->calculatePrice() << " Kè, Velikost: " << p4->getSize() << " cm" << endl;
	p4->calculateNutritions()->info();

	cout << endl;

	Pizza* p5 = restaurant->createPizza("BBQ", 32, new Base("BBQ", 15, 32), { "Mozzarella", "Šunka", "Oregáno" });
	cout << "Pizza: " << p5->getName() << ", Cena: " << p5->calculatePrice() << " Kè, Velikost: " << p5->getSize() << " cm" << endl;
	p5->calculateNutritions()->info();

	cout << endl;

	// Osobní objednávka
	cout << "Vytvoøení objednávky pro zákazníka:" << endl;
	Order* o1 = new Order("John Doe", "+420 123 456 789");
	restaurant->addOrder(o1);
	o1->addPizza(p1);
	o1->addPizza(p2);
	o1->calculateTotalPrice();
	cout << "Osobní objednávka: " << o1->getCustomerName()
		<< ", Tel: " << o1->getCustomerPhone()
		<< ", Celkem: " << o1->getTotalPrice() << " Kè" << endl;

	// Zpracování objednávky
	Waiter* w = restaurant->getWorkingWaiter();
	if (w) 
		w->takeOrder(o1);
	Cook* c = restaurant->getWorkingCook();
	if (c) 
		c->prepareOrder(o1);
	if (w) 
		w->serveOrder(o1);

	cout << endl;

	// Doruèení objednávky
	cout << "Dodávka objednávky pro zákazníka:" << endl;
	DeliveryOrder* d = new DeliveryOrder(
		"John Doe",
		"+420 783 130 392",
		"17. listopadu 2503, Ostrava-Poruba",
		"19:10"
	);
	restaurant->addOrder(d);
	d->addPizza(p3);
	d->calculateTotalPrice();
	cout << "Objednávka pro: " << d->getCustomerName()
		<< ", Tel: " << d->getCustomerPhone()
		<< ", Adresa: " << d->getDeliveryAddress()
		<< ", Èas doruèení: " << d->getDeliveryTime()
		<< ", Cena: " << d->getTotalPrice() << " Kè" << endl;

	// Zpracování objednávky
	Waiter* wl = restaurant->getWorkingWaiter();
	if (wl)
		wl->takeOrder(d);
	Cook* cl = restaurant->getWorkingCook();
	if (cl)
		cl->prepareOrder(d);
	Delivery* dl = restaurant->getWorkingDelivery();
	if (dl) 
		dl->deliverOrder(d);

	cout << endl;

	// Vypsání objednávek
	cout << "Objednávky:" << endl;
	Order** orders = restaurant->getOrders();
	for (int i = 0; i < 5; i++) {
		if (orders[i] != nullptr) {
			cout << "Order ID: " << orders[i]->getId() <<", Typ: " << orders[i]->getType() << ", Zákazník: " << orders[i]->getCustomerName() << ", Phone: " << orders[i]->getCustomerPhone() << ", Celkem: " << orders[i]->getTotalPrice() << " Kè, Status: " << statusToString(orders[i]->getStatus()) << endl;
			Pizza** pizzas = orders[i]->getPizzas();
			for (int j = 0; j < 10; j++) {
				if (pizzas[j] != nullptr) {
					cout << "Pizza: " << pizzas[j]->getName() << ", Velikost: " << pizzas[j]->getSize() << " cm" << endl;
				}
			}
		}
	}

	cout << endl;

	// Vypsání 10 zamìstnancù
	cout << "Zamìstnanci:" << endl;
	Employee** employees = restaurant->getEmployees();
	for (int i = 0; i < 10; i++) {
		if (employees[i] != nullptr) {
			cout << employees[i]->getPosition() << ": "
				<< employees[i]->getName()
				<< ", Tel: " << employees[i]->getPhone()
				<< ", Email: " << employees[i]->getEmail()
				<< ", Adresa: " << employees[i]->getAddress()
				<< endl;
		}
	}

	// Uvolnìní pamìti
	// Všechny pizzy, objednávky a suroviny by se mìly uvolnit v destruktorech
	delete restaurant;

	return 0;
}