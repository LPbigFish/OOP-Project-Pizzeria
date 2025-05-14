#include "Employee.h"

Employee::Employee(string name, string surname, string phone, string email, string address, string position)
{
	this->name = name;
	this->surname = surname;
	this->phone = phone;
	this->email = email;
	this->address = address;
	this->position = position;
}

Employee::~Employee()
{
}

string Employee::getName() const
{
	return this->name;
}

string Employee::getSurname() const
{
	return this->surname;
}

string Employee::getPhone() const
{
	return this->phone;
}

string Employee::getEmail() const
{
	return this->email;
}

string Employee::getAddress() const
{
	return this->address;
}

string Employee::getPosition() const
{
	return this->position;
}

bool Employee::isWorking() const
{
	return this->working;
}

void Employee::setName(string name)
{
	this->name = name;
}

void Employee::setSurname(string surname)
{
	this->surname = surname;
}

void Employee::setPhone(string phone)
{
	this->phone = phone;
}

void Employee::setEmail(string email)
{
	this->email = email;
}

void Employee::setAddress(string address)
{
	this->address = address;
}

void Employee::setPosition(string position)
{
	this->position = position;
}

void Employee::Work()
{
	this->working = true;
}

void Employee::StopWork()
{
	this->working = false;
}
