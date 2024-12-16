#include <iostream>
using namespace std;
class complex
{
    float real;
    float imag;

public:
    complex()
    {
        real = 0;
        imag = 0;
    }

    complex operator+(complex b)
    {
        complex r;
        r.real = real + b.real;
        r.imag = imag + b.imag;
        return r;
    }

    complex operator*(complex b)
    {
        complex r;
        r.real = real * b.real - imag * b.imag;
        r.imag = real * b.imag + imag * b.real;
        return r;
    }

    friend ostream &operator<<(ostream &os, const complex &z);
    friend istream &operator>>(istream &is, complex &z);
};

ostream &operator<<(ostream &os, const complex &z)
{
    os << z.real << "*i" << z.imag;
    return os;
}

istream &operator>>(istream &is, complex &z)
{
    is >> z.real >> z.imag;
    return is;
}

int main()
{
    int choice;
    string ans;
    complex z1, z2;
    while (true)
    {
        cout << "\n Menu:";
        cout << "\n 1.Addition";
        cout << "\n 2.Multiplication";
        cout << "\n 3.Exit";
        cout << "\n Enter your choice:";
        cin >> choice;

        cout << "Enter real and imaginary part of complex number z1: \n";
        cin >> z1;
        cout << "Enter real and imaginary part of complex number z2: \n";
        cin >> z2;

        switch (choice)
        {
        case 1:
            cout << "\n Addition of complex numbers:" << z1 + z2;
            break;

        case 2:
            cout << "\n Multiplication of complex numbers:" << z1 * z2;
            break;

        case 3:
            cout << "Exiting the program";
            exit(1);
            break;

        default:
            cout << "Invalid choice" << endl;
            break;
        }

        cout << "\n Do you want to continue(yes/no):";
        cin >> ans;
        if (ans == "no")
        {
            break;
        }
    }
    return 0;
}
