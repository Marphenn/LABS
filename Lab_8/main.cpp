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
	Cartoon* mickey = new Cartoon("�������", "����� ����", 50, 7.9, 1954);
	Cartoon* tom = new Cartoon("�������", "��� � ������", 120, 8.4, 1938);
	Cartoon* scooby = new Cartoon("�������", "�����-��", 30, 8.0, 1994);
	Cartoon* nu = new Cartoon("����", "��, ������!", 80, 10.0, 1980);
	Cartoon* ivan = new Cartoon("������", "���� ������� � ����� ����", 1, 5.2, 2014);
	Cartoon* maugli = new Cartoon("�������", "������", 55, 7.4, 1976);
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
	
	f2.close();

	return 0;
}