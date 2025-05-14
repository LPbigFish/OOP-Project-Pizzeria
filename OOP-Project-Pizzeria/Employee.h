#pragma once
#include <string>

using namespace std;

class Employee
{
protected:
	string name;
	string surname;
	string phone;
	string email;
	string address;
	string position;
	bool working = true;
public:
	Employee(string name, string surname, string phone, string email, string address, string position);
	~Employee();
	string getName() const;
	string getSurname() const;
	string getPhone() const;
	string getEmail() const;
	string getAddress() const;
	string getPosition() const;
	bool isWorking() const;
	void setName(string name);
	void setSurname(string surname);
	void setPhone(string phone);
	void setEmail(string email);
	void setAddress(string address);
	void setPosition(string position);
	void Work();
	void StopWork();
};