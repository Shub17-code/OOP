#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    map<string, int> state_Population;
    state_Population["Maharashtra"] = 123144223;
    state_Population["Uttar Pradesh"] = 231502578;
    state_Population["Bihar"] = 129967743;
    state_Population["West Bengal"] = 104832200;
    state_Population["Tamil Nadu"] = 7200000;

    int choice;
    do
    {
        cout << "List of states:" << endl;
        cout << "1.Maharashtra" << endl;
        cout << "2.Uttar Pradesh" << endl;
        cout << "3.Bihar" << endl;
        cout << "4.West Bengal" << endl;
        cout << "5.Tamil Nadu" << endl;
        cout << "1. Find the population of the state" << endl;
        cout << "2. Exit" << endl;

        cout << "Enter your choice:";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string state;
            cout << "Enter the name of the state:";
            cin >> state;
            if (state_Population.find(state) != state_Population.end())
            {
                cout << "The population of the state " << state << "is:" << state_Population[state] << endl;
            }
            else
            {
                cout << "State not found" << endl;
            }
            break;
        }

        case 2:
            cout << "Exiting the program";
            break;
        }

    } while (choice != 2);
    return 0;
}