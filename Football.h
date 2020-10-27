#pragma once
#include <iostream>

using namespace std;

class Football {
private:
	int m_duration;

public:
	Football(int dur = 90)
		: m_duration(dur)
	{ };
	virtual ~Football() {
		cout << "\nFootball destroyed.\n";
	};
	virtual int calculate() = 0;
	virtual void getInfo() = 0;
};


class BPL : virtual public Football
{
private:
	int n_teams;
	int n_tours;
public:
	BPL(int dur = 90, int teams = 20, int tours = 38)
		: Football(dur), n_teams(teams), n_tours(tours)
	{};
	virtual ~BPL()
	{
		cout << "\nBPL destroyed.\n";
	}
	virtual int calculate();
	virtual void getInfo();
};


class Bundesliga : virtual public Football
{
private:
	int n_teams;
	int n_tours;
public:

	Bundesliga(int dur = 90, int teams = 18, int tours = 34)
		: Football(dur), n_teams(teams), n_tours(tours)
	{};
	virtual ~Bundesliga()
	{
		cout << "\nBundesliga destroyed.\n";
	}
	virtual int calculate();
	virtual void getInfo();
};

class ManCity : public BPL
{
private:
	int position;
	int pts_difference;
public:
	ManCity(int dur = 90, int teams = 20, int tours = 38, int p = 14, int dif=5)
		: BPL(dur, teams, tours), position(p), pts_difference(dif)
	{};
	virtual ~ManCity()
	{
		cout << "\nManchester City destroyed.\n";
	}
	virtual int calculate();
	virtual void getInfo();
};