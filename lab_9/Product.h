#pragma once

#include <string>
#include <iostream>

using namespace std;

namespace pr {

	class Product {
	private:
		int id;
		string name;
		double cost;

	public:
		Product();
		Product(int, string, double);
		~Product();
		int getId();
		string getName();
		double getCost();
		void getInfo();
		void setId(int);
		bool operator== (Product& obj)
		{
			if (obj.getId() == this->getId() &&
				obj.getName() == this->getName() &&
				obj.getCost() == this->getCost()
				) return true;
			else return false;
		}
		void showName();
	};

	Product::Product()
	{
		//cout << "Object created..." << endl;
		id = 0;
		name = "";
		cost = 0;
	}

	Product::Product(int i, string n, double c)
	{
		//cout << "Object created..." << endl;
		id = i;
		name = n;
		cost = c;
	}

	Product::~Product() {
		//cout << "Object destroyed..." << endl;
	}

	int Product::getId()
	{
		return id;
	}

	void Product::setId(int a)
	{
		id = a;
	}

	string Product::getName()
	{
		return name;
	}

	double Product::getCost()
	{
		return cost;
	}

	void Product::getInfo()
	{
		cout << "===================================================================" << endl;
		cout << "ID:\t" << this->id << endl;
		cout << "NAME:\t" << this->name << endl;
		cout << "COST:\t" << this->cost << endl;
		cout << "===================================================================" << endl;
	}

	void Product::showName()
	{
		cout << this->name << endl;
	}
}