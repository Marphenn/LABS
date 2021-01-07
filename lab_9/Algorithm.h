#pragma once

#include <iostream>
#include <list>
#include <iterator>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Product.h"

using namespace std;
using  namespace pr;

namespace alg {

	class Algorithm
	{
	public:
		list<string> strList;
		list<Product> prctList;

		ifstream fin;
		ofstream fout;

		void count(string fromFile, string toFile, string symbols)
		{
			cout << "Trying to open " << fromFile << endl;
			try {
				fin.open(fromFile);
				if (!fin.is_open()) throw 1;
			}
			catch (int)
			{
				cout << "Can't open " << fromFile << endl;
			}
			fout.open(toFile);
			readFromFile();
			cout << "Invalid symbols: " << symbols << endl;
			int res = countWords(symbols);
			cout << res << endl;
			cout << "Writing result to " << toFile << endl;
			fout << res;
			strList.clear();
		}

		template<typename T>
		int fstDetection(list<Product>::iterator begin, list<Product>::iterator end, T& object)
		{
			int position = 0;
			bool isDetected = false;
			for (list<Product>::iterator it = begin; it != end; it++)
			{
				if ((*it) == object)
				{
					isDetected = true;
					break;
				}
				position++;
			}
			if (isDetected) return position;
			else return -1;
		}

		template<typename T>
		void deleteDuplicates(list<Product>& l, T& obj)
		{
			list<Product>::iterator begin = l.begin(), tmp;
			list<Product>::iterator end = l.end();
			int id = obj.getId();
			for (list<Product>::iterator it = begin; it != end; it++)
			{
				if ((*it) == obj)
				{
					(*it).setId(id + 1);
					tmp = it;
					break;
				}
			}

			for (list<Product>::iterator it = begin; it != end;)
			{
				if ((*it) == obj)
				{
					it = l.erase(it);
				}
				else it++;
			}
			(*tmp).setId(id);
		}

	private:
		void readFromFile()
		{
			while (!fin.eof())
			{
				string s;
				fin >> s;
				strList.push_back(s);
			}
		}

		int countWords(string symbols)
		{
			int res = 0;
			for (list<string>::iterator it = strList.begin(); it != strList.end(); it++) {
				cout << *it << endl;
				vector<int> flags(symbols.size(), 0);
				for (int i = 0; i < (*it).size(); i++) {
					for (int j = 0; j < symbols.size(); j++)
					{
						if ((*it)[i] == symbols[j]) flags[j]++;
					}
				}
				bool noWord = true;
				for (int i = 0; i < flags.size() && noWord; i++)
				{
					if (flags[i]) noWord = false;
				}

				if (noWord)
				{
					res++;
					cout << "\t<TRUE>" << endl;
				}
				else cout << "\t<FALSE>" << endl;
			}
			return res;
		}
	};
}