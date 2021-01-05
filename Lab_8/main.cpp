#include <iostream>
#include "Cartoon.h"
#include "Files.h"

using namespace std;

int main()
{
	//Cartoon mickey("America", "Mickey Mouse", 50, 7.9, 1994);
	//cout << mickey.toString();

	File f1;
	f1.openTextFile("text1.txt");
	for (int i = 0; i < 10; i++)
	{
		f1 << to_string(i);
	}
	f1.outputToConsole();
	cout << endl;
	f1.outputToConsoleReverse();
	cout << endl;
	f1.close();

	File f2;
	f2.openFileStream("bin.bin");
	setlocale(LC_ALL, "Russian");
	Cartoon* mickey = new Cartoon("Àìåðèêà", "Ìèêêè Ìàóñ", 50, 7.9, 1954);
	Cartoon* tom = new Cartoon("Àìåðèêà", "Òîì è Äæåððè", 120, 8.4, 1938);
	Cartoon* scooby = new Cartoon("Àìåðèêà", "Ñêóáè-Äó", 30, 8.0, 1994);
	Cartoon* nu = new Cartoon("ÑÑÑÐ", "Íó, ïîãîäè!", 80, 10.0, 1980);
	Cartoon* ivan = new Cartoon("Ðîññèÿ", "Èâàí Öàðåâè÷ è ñåðûé âîëê", 1, 5.2, 2014);
	Cartoon* maugli = new Cartoon("Àìåðèêà", "Ìàóãëè", 55, 7.4, 1976);
	f2.putObject(mickey);
	f2.putObject(tom);
	f2.putObject(scooby);
	f2.putObject(nu);
	f2.putObject(ivan);
	f2.putObject(maugli);
	Cartoon* any = new Cartoon();
	f2.printObject();
	f2.printObjectReverse();
	f2.sortByName();
	f2.printObject();
	f2.sortByRating();
	f2.printObject();
	f2.sortByParts();
	f2.printObject();

	f2.SortedList();
	f2.printObject();
	
	for (int i = 0; i < f2.getLength(); i++)
	{
		if (f2.fetchObject(i)->getCountry() == "Америка")
		{
			Cartoon* del=f2.deleteObject(i);
			cout << del->toString() << " IS DELETED" << endl;
			i--;
		}
	}
	f2.printObject();
	
	f2.close();

	return 0;
}
