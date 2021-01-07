#include <iostream>
#include "Product.h"
#include "Algorithm.h"

using namespace std;
using namespace alg;

void show(list<Product> lst)
{
	list<Product>::iterator begin = lst.begin(), it;
	list<Product>::iterator end = lst.end();
	for (it = begin; it != end; it++)
	{
		(*it).getInfo();
	}
}

int main()
{
	alg::Algorithm alg;
	alg.count("from.txt", "to.txt", "abc");

	cout << "Creating new list l1" << endl;
	list<pr::Product>l1;
	//l1.push_back(pr::Product(5, "Apple", 3.4));
	l1.push_back(pr::Product(10, "Water", 1.7));
	l1.push_back(pr::Product(1, "Coconut", 5.0));
	l1.push_back(pr::Product(5, "Apple", 3.4));
	l1.push_back(pr::Product(6, "Banana", 4.1));
	l1.push_back(pr::Product(5, "Apple", 3.4));
	l1.push_back(pr::Product(5, "Apple", 3.4));
	
	pr::Product check(5, "Apple", 3.4);
	cout << "First appearance of ";
	check.showName();
	int fstPos = alg.fstDetection(l1.begin(), l1.end(), check);
	try
	{
		if (fstPos >= 0) cout << fstPos << endl;
		else throw 1;
	}
	catch (int)
	{
		cout << "There is no such element" << endl;
	}

	show(l1);
	cout << "\nDelete duplicates of "; check.showName();
	alg.deleteDuplicates(l1, check);
	show(l1);

	return 0;
}
