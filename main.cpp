#include <iostream>
#include "Football.h"

using namespace std;

int set_m_duration();
int set_num_teams(const char*);
int set_num_tours(const char*);
int set_position(const char*, int);
int set_points_dif(const char*, int);

int main()
{
	const int SIZE = 3;
	int dur = set_m_duration();
	int teamsBPL = set_num_teams("BPL");
	int toursBPL = set_num_tours("BPL");
	int teamsBundes = set_num_teams("BUNDESLIGA");
	int toursBundes = set_num_tours("BUNDESLIGA");
	int pos = set_position("Manchester City", teamsBPL);
	int points = set_points_dif("Manchester City", pos);

	Football** arr = new Football*[SIZE];
	arr[0] = new BPL(dur, teamsBPL, toursBPL);
	arr[1] = new Bundesliga(dur, teamsBundes, toursBundes);
	arr[2] = new ManCity(dur, teamsBPL, toursBPL, pos, points);

	for (int i = 0; i < SIZE; i++)
	{
		arr[i]->getInfo();
		cout << "Calculation result: " << arr[i]->calculate() << endl;
	}
	for (int i = 0; i < SIZE; i++)
	{
		delete arr[i];
	}
	

	return 0;
}