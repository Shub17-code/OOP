#include <iostream>
#include <fstream>
using namespace std;
class Student
{
public:
    int roll;
    string name;
    int marks;

    Student()
    {
        roll = 0;
        name = "";
        marks = 0;
    }

    void getdata()
    {
        cout << "Enter Student Details:" << endl;
        cout << "Enter roll number:";
        cin >> roll;
        cout << "Enter name:";
        cin >> name;
        cout << "Enter marks:";
        cin >> marks;
    }

    void display()
    {
        cout << "\n Roll Number:" << roll << endl;
        cout << "Name:" << name << endl;
        cout << "Marks:" << marks << endl;
    }
};

int main()
{
    Student s[70];
    fstream file;
    int i, n;
    file.open("Exmaple.txt");
    cout << "Enter number of students:";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        s[i].getdata();
        file.write((char *)&s[i], sizeof(s[i]));
    }

    file.close();

    file.open("Exmaple.txt");

    cout << "Reading information from the file:" << endl;

    for (int i = 0; i < n; i++)
    {
        file.read((char *)&s[i], sizeof(s[i]));
        s[i].display();
    }
    file.close();
    return 0;
}