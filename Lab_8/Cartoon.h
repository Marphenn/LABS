#pragma once

#include <iostream>
#include <string>

using namespace std;

class Cartoon
{
private:
	string name;
	long int year;
	string country;
	int parts;
	double rating;

public:

	Cartoon()
	{
		this->country = "";
		this->name = "";
		this->parts = 0;
		this->rating = 0;
		this->year = 0;
	}

	Cartoon(string Country, string Name, int Parts, double Rating, long int Year)
	{
		this->country = Country;
		this->name = Name;
		this->parts = Parts;
		this->rating = Rating;
		this->year = Year;
	}

	string toString()
	{
		string res = "<";
		res += this->name + ", " + this->country + ", ";
		res += to_string(this->year) + ", " + to_string(this->parts) + ", " + to_string(this->rating);
		res += ">";
		return res;
	}

	void setCountry(string c)
	{
		this->country = c;
	}

	void setName(string n)
	{
		this->name = n;
	}

	void setParts(int p)
	{
		this->parts = p;
	}

	void setYear(long int y)
	{
		this->year = y;
	}

	void setRating(double r)
	{
		this->rating = r;
	}

	string getCountry()
	{
		return this->country;
	}

	string getName()
	{
		return this->name;
	}

	int getParts()
	{
		return this->parts;
	}

	long int getYear()
	{
		return this->year;
	}

	double getRating()
	{
		return this->rating;
	}
};
