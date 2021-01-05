#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Cartoon.h"

using namespace std;

class File
{
private:

	string filename;
	fstream fileStream;
	int length;

	struct cartoon
	{
		long int year;
		int parts;
		double rating;
		vector<string> n_c;
	};

public:

	File()
	{
		this->length = 0;
	}

	void openTextFile(string filename) {
		try {
			this->fileStream.open(filename, ios::in | ios::out | ios::trunc);
			this->filename = filename;
			if (!this->fileStream.is_open()) throw 1;
		}
		catch (int) {
			cerr << "[RUNTIME] Error while opening file...\n";
			terminate();
		}
	}

	void putString(string text) {
		try {
			if (!this->fileStream.is_open()) throw 1;
			for (auto ch : text) {
				this->fileStream.put(ch);
			}
			this->length += text.size();
		}
		catch (int) {
			cerr << "[RUNTIME] File is not open error...\n";
			terminate();
		}

	}

	void openFileStream(string filename) {
		try {
			this->fileStream.open(filename, ios::binary | ios::in | ios::out | ios::trunc);
			this->filename = filename;
			if (!this->fileStream.is_open()) throw 1;
		}
		catch (int) {
			cerr << "[RUNTIME] Error while opening file...\n";
			terminate();
		}
	}

	File& operator<< (string obj)
	{
		try {
			if (!this->fileStream.is_open()) throw 1;
			putString(obj);
			return *this;
		}
		catch (int) {
			cerr << "[RUNTIME] Error while opening file...\n";
			terminate();
		}
	}

	File& operator>> (string& obj) {
		try {
			if (!this->fileStream.is_open()) throw 1;
			this->fileStream.seekg(0);
			char ch;
			for (int i = 0; i < getLength(); i++) {
				this->fileStream.get(ch);
				obj.push_back(ch);
			}
		}
		catch (int) {
			cerr << "[RUNTIME] Error while opening file...\n";
			terminate();
		}
	}


	int getLength()
	{
		return this->length;
	}

	void outputToConsole() {
		try {
			if (!this->fileStream.is_open()) throw 1;
			this->fileStream.seekg(0);
			char ch;
			for (int i = 0; i < getLength(); i++) {
				this->fileStream.get(ch);
				cout << ch;
			}
		}
		catch (int) {
			cerr << "[RUNTIME] File is not open error...\n";
			terminate();
		}
	}

	void outputToConsoleReverse() {
		try {
			if (!this->fileStream.is_open()) throw 1;
			this->fileStream.seekg(0);
			char ch;
			for (int i = getLength()-1; i >= 0; i--) {
				this->fileStream.seekg(i);
				this->fileStream.get(ch);
				cout << ch;
			}
		}
		catch (int) {
			cerr << "[RUNTIME] File is not open error...\n";
			terminate();
		}
	}

	void putObject(Cartoon* object, int index = -1) {
		try {
			if (!this->fileStream.is_open()) throw 1;
			if (index < 0) {
				this->fileStream.seekg(length * sizeof(Cartoon));
				this->length++;
			}
			else {
				try {
					if (index >= this->length) throw 1;
					this->fileStream.seekg(index * sizeof(Cartoon));
				}
				catch (int) {
					cerr << "[RUNTIME] Run out of scope error...\n";
					terminate();
				}
			}
			this->fileStream.write((char*)object, sizeof(Cartoon));
		}
		catch (int) {
			cerr << "[RUNTIME] File is not open error...\n";
			terminate();
		}
	}

	void outputToObject(Cartoon* object, int index) {
		try {
			if (!this->fileStream.is_open()) throw 1;
			this->fileStream.seekg(index * sizeof(Cartoon));
			this->fileStream.read((char*)object, sizeof(Cartoon));
		}
		catch (int) {
			cerr << "[RUNTIME] File is not open error...\n";
			terminate();
		}
	}

	Cartoon* fetchObject(int index) {
		try {
			if (!this->fileStream.is_open()) throw 1;
			try {
				if (index >= this->length || index < 0) throw 1;
				Cartoon* object = new Cartoon;
				this->fileStream.seekg(index * sizeof(Cartoon));
				this->fileStream.read((char*)object, sizeof(Cartoon));
				return object;
			}
			catch (int) {
				cerr << "[RUNTIME] Run out of scope error...\n";
				terminate();
			}
			cout << "";
		}
		catch (int) {
			cerr << "[RUNTIME] File is not open error...\n";
			terminate();
		}
	}

	void printObject() {
		cout << "Printing object: \n";
		for (int i = 0; i < getLength(); i++) {
			cout << fetchObject(i)->toString() << endl;
		}
		cout << endl;
	}

	void printObjectReverse() {
		cout << "Printing object reverse:\n";
		for (int i = getLength() - 1; i >= 0; i--) {
			cout << fetchObject(i)->toString() << endl;
		}
		cout << endl;
	}

	Cartoon* deleteObject(int index) {
		try {
			if (!this->fileStream.is_open()) throw 1;
			try {
				if (index >= this->length || index < 0) throw 1;

				Cartoon* res = fetchObject(index);

				for (int i = index + 1; i < getLength(); i++) {
					Cartoon* tmp = new Cartoon;
					outputToObject(tmp, i);
					putObject(tmp, i - 1);
				}

				this->length--;

				return res;
			}
			catch (int) {
				cerr << "[RUNTIME] Run out of scope error...\n";
				terminate();
			}
			cout << "";
		}
		catch (int) {
			cerr << "[RUNTIME] File is not open error...\n";
			terminate();
		}
	}

	void swapObjectsAt(int i, int j) {
		try {
			if (!this->fileStream.is_open()) throw 1;
			try {
				if (i >= this->length || i < 0 || j >= this->length || j < 0) throw 1;
				Cartoon* tmp = fetchObject(i);
				putObject(fetchObject(j), i);
				putObject(tmp, j);
			}
			catch (int) {
				cerr << "[RUNTIME] Run out of scope error...\n";
				terminate();
			}
			cout << "";
		}
		catch (int) {
			cerr << "[RUNTIME] File is not open error...\n";
			terminate();
		}
	}

	void sortByName(int k=1) {
		if(k) cout << "sortByName()\n";
		int i, j;
		Cartoon* key;
		for (i = 1; i < getLength(); i++)
		{
			key = fetchObject(i);
			j = i - 1;
			while (j >= 0 && fetchObject(j)->getName() > key->getName())
			{
				putObject(fetchObject(j), j + 1);
				j = j - 1;
			}
			putObject(key, j + 1);
		}
	}

	void sortByParts() {
		cout << "sortByParts()\n";
		int i, j;
		Cartoon* key;
		for (i = 1; i < getLength(); i++)
		{
			key = fetchObject(i);
			j = i - 1;
			while (j >= 0 && fetchObject(j)->getParts() > key->getParts())
			{
				putObject(fetchObject(j), j + 1);
				j = j - 1;
			}
			putObject(key, j + 1);
		}
	}

	void sortByRating() {
		cout << "sortByRating()\n";
		int i, j;
		Cartoon* key;
		for (i = 1; i < getLength(); i++)
		{
			key = fetchObject(i);
			j = i - 1;
			while (j >= 0 && fetchObject(j)->getRating() < key->getRating())
			{
				putObject(fetchObject(j), j + 1);
				j = j - 1;
			}
			putObject(key, j + 1);
		}
	}

	void SortedList()
	{
		cout << "Final sort():" << endl;
		sortByName(0);
		for (int i = 0; i < getLength()-1; i++)
		{
			Cartoon* temp=fetchObject(i);
			char key = temp->getName()[0];
			int start = i + 1, end = start;
			while (end < getLength() && key == fetchObject(end)->getName()[0])
			{
				end++;
			}
			if (end != start)
			{
				Cartoon* key;

				for (int i2= start; i2 < end; i2++)
				{
					key = fetchObject(i2);
					int j2 = i2 - 1;
					while (j2 >= start-1 && fetchObject(j2)->getRating() < key->getRating())
					{
						putObject(fetchObject(j2), j2 + 1);
						j2 = j2 - 1;
					}
					putObject(key, j2 + 1);
				}
				
			}
			
		}
	}

	void setSeek(int s) {
		this->fileStream.seekg(s);
	}

	void close() {
		this->fileStream.close();
	}
};