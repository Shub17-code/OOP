#include <iostream>
using namespace std;
class publication
{
private:
    string title;
    float price;

public:
    publication()
    {
        title = "";
        price = 0.0;
    }

    void getdata()
    {
        cout << "Enter the title:" << endl;
        cin >> title;
        cout << "Enter the price:" << endl;
        cin >> price;
    }

    void putdata()
    {
        cout << "Title:" << title;
        cout << "Price:" << price;
    }
};

class book : public publication
{
private:
    int page_count;

public:
    book()
    {
        page_count = 0;
    }

    void add_book()
    {
        try
        {
            cout << "Enter page count of the book:";
            cin >> page_count;
            if (page_count <= 0)
                throw page_count;
        }
        catch (...)
        {
            cout << "Invalid page count";
            page_count = 0;
        }
    }

    void display_book()
    {
        putdata();
        cout << "\n Page count:" << page_count << endl;
    }
};

class tape : public publication
{
private:
    float play_time;

public:
    tape()
    {
        play_time = 0;
    }

    void add_tape()
    {
        try
        {
            cout << "Enter playing time of the tape in minutes:";
            cin >> play_time;
            if (play_time <= 0)
                throw play_time;
        }
        catch (...)
        {
            cout << "Invalid play time";
            play_time = 0;
        }
    }

    void display_tape()
    {
        putdata();
        cout << "\n Page count:" << play_time << endl;
    }
};

int main()
{
    int choice;
    book b;
    tape t;
    do
    {
        cout << "Menu \n";
        cout << "1.Enter book record \n";
        cout << "2.Enter tape record \n";
        cout << "3.Display book record \n";
        cout << "4.Dispalay tape record \n";
        cout << "5.Exit \n";
        cout << "Enter your choice:";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter details for book:" << endl;
            b.add_book();
            break;

        case 2:
            cout << "Enter details for tape:" << endl;
            t.add_tape();
            break;

        case 3:
            cout << "Displaying book records:" << endl;
            b.display_book();
            break;

        case 4:
            cout << "Displaying tape records:" << endl;
            t.display_tape();
            break;

        case 5:
            cout << "Exiting the program" << endl;
            break;

        default:
            cout << "Invalid choice";
        }
    } while (choice != 5);

    return 0;
}