#include <iostream>
#include <string>
#include "Football.h"

using namespace std;

int set_m_duration()
{
    int duration;
    while (1)
    {
        cout << "Enter match duration (minutes) : " << endl;
        cin >> duration;
        if (cin.fail() || duration < 30)
        {
            cout << "Incorrect value." << endl;
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else return duration;
    }
}

int set_num_teams(const char* champ)
{
    int teams;
    while (1)
    {
        cout << "Enter the number of teams in " << champ << ": " << endl;
        cin >> teams;
        if (cin.fail() || teams < 0 || teams > 40)
        {
            cout << "Incorrect value." << endl;
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else return teams;
    }
}

int set_num_tours(const char* champ)
{
    int tours;
    while (1)
    {
        cout << "Enter the number of tours in " << champ << ": " << endl;
        cin >> tours;
        if (cin.fail() || tours < 0 || tours > 50)
        {
            cout << "Incorrect value." << endl;
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else return tours;
    }
}

int set_position(const char* team, int max)
{
    int pos;
    while (1)
    {
        cout << "Enter the position of " << team << ": " << endl;
        cin >> pos;
        if (cin.fail() || pos < 0 || pos > max)
        {
            cout << "Incorrect value." << endl;
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else return pos;
    }
}

int set_points_dif (const char* team, int max)
{
    int dif;
    while (1)
    {
        cout << "Enter the points difference between " << team << " and the upper team in the table: " << endl;
        cin >> dif;
        if (cin.fail() || dif < 0 || dif > max)
        {
            cout << "Incorrect value." << endl;
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else return dif;
    }
}

int BPL::calculate()
{
    return (n_teams * n_tours) / 2;
}

int Bundesliga::calculate()
{
    return (n_teams * n_tours) / 2;
}

int ManCity::calculate()
{
    const int WIN = 3;
    if (position == 1) return 0;
    else return (pts_difference / WIN) + 1;
}

void BPL::getInfo()
{
    cout << endl << "BPL INFO:" << "\n--- Number of teams: " << n_teams << "\n--- Number of tours: " << n_tours << "\n--- Total matches: " << calculate() << endl;
}

void Bundesliga::getInfo()
{
    cout << endl << "BUNDESLIGA INFO:" << "\n--- Number of teams: " << n_teams << "\n--- Number of tours: " << n_tours << "\n--- Total matches: " << calculate() << endl;
}

void ManCity::getInfo()
{
    cout << endl << "MANCHESTER CITY INFO:" << "\n--- Current place in the table: " << position << "\n--- Points difference: " << pts_difference << "\n--- Matches needed to go up in the table: " << calculate() << endl;
}