#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string *name;
    int rollNumber;
    string *className;
    char division;
    string dob;
    string bloodGroup;
    string contactAddress;
    string phoneNumber;
    string drivingLicense;

    static int studentCount;

public:
    Student()
    {
        name = new string("");
        rollNumber = 0;
        className = new string("");
        division = 'A';
        dob = "";
        bloodGroup = "";
        contactAddress = "";
        phoneNumber = "";
        drivingLicense = "";
        studentCount++;
    }

    Student(string n, int roll, string cls, char div, string birthDate, string bg, string address, string phone, string license)
    {
        name = new string(n);
        rollNumber = roll;
        className = new string(cls);
        division = div;
        dob = birthDate;
        bloodGroup = bg;
        contactAddress = address;
        phoneNumber = phone;
        drivingLicense = license;
        studentCount++;
    }

    Student(const Student &s)
    {
        name = new string(*s.name);
        rollNumber = s.rollNumber;
        className = new string(*s.className);
        division = s.division;
        dob = s.dob;
        bloodGroup = s.bloodGroup;
        contactAddress = s.contactAddress;
        phoneNumber = s.phoneNumber;
        drivingLicense = s.drivingLicense;
        studentCount++;
    }

    ~Student()
    {
        delete name;
        delete className;
        studentCount--;
    }

    static int getStudentCount()
    {
        return studentCount;
    }

    void setDetails(string n, int roll, string cls, char div, string birthDate, string bg, string address, string phone, string license)
    {
        this->name = new string(n);
        this->rollNumber = roll;
        this->className = new string(cls);
        this->division = div;
        this->dob = birthDate;
        this->bloodGroup = bg;
        this->contactAddress = address;
        this->phoneNumber = phone;
        this->drivingLicense = license;
        studentCount++;
    }

    void input()
    {
        cout << "Enter name:" << endl;
        cin >> *name;
        cout << "Enter roll number:" << endl;
        cin >> rollNumber;
        cout << "Enter class:" << endl;
        cin >> *className;
        cout << "Enter division:" << endl;
        cin >> division;
        cout << "Enter date of birth:" << endl;
        cin >> dob;
        cout << "Enter blood group:" << endl;
        cin >> bloodGroup;
        cout << "Enter address:" << endl;
        cin >> contactAddress;
        cout << "Enter phone number:" << endl;
        cin >> phoneNumber;
        cout << "Enter driving license number:" << endl;
        cin >> drivingLicense;
    }

    inline void displayInfo() const
    {
        cout << "Name:" << *name << endl;
        cout << "Roll Number:" << rollNumber << endl;
        cout << "Class:" << *className << endl;
        cout << "Division:" << division << endl;
        cout << "Date of birth:" << dob << endl;
        cout << "Blood Group:" << bloodGroup << endl;
        cout << "Contact Address:" << contactAddress << endl;
        cout << "Phone Number:" << phoneNumber << endl;
        cout << "Driving License:" << drivingLicense << endl;
    }

    friend class Display;
};

class Display
{
public:
    void showDetails(const Student &student)
    {
        cout << "Name:" << *student.name << endl;
        cout << "Roll Number:" << student.rollNumber << endl;
        cout << "Class:" << *student.className << endl;
        cout << "Division:" << student.division << endl;
        cout << "Date of birth:" << student.dob << endl;
        cout << "Blood Group:" << student.bloodGroup << endl;
        cout << "Contact Address:" << student.contactAddress << endl;
        cout << "Phone Number:" << student.phoneNumber << endl;
        cout << "Driving License:" << student.drivingLicense << endl;
    }
};

int Student::studentCount = 0;

int main()
{
    Student s1("Atharva", 101, "SY", 'A', "12-12-2000", "O+", "Pune", "1234567890", "DL12345");
    Student s2;
    s2.setDetails("Shrisha", 102, "FY", 'B', "01-01-2001", "A+", "Mumbai", "9876543210", "DL54321");
    Student s3;
    Student s4(s1);
    cout << "Student 1 info:\n";
    s1.displayInfo();
    cout << "Student 2 info:\n";
    s2.displayInfo();
    cout << "Enter student 3 details:";
    s3.input();
    cout << "Student 3 info:\n";
    s3.displayInfo();
    cout << "Student 4 info(Copied from student 1):\n";
    s4.displayInfo();
    Display display;
    cout << "USing Friend class to display student 1 info:\n";
    display.showDetails(s1);
    cout << "Total students:" << Student::getStudentCount() << endl;
    return 0;
}