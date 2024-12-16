#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Person
{
public:
    string name;
    string dob;
    string phone;

    Person(string n, string date, string number)
    {
        name = n;
        dob = date;
        phone = number;
    }

    void display() const
    {
        cout << "Person name:" << name << endl;
        cout << "Person date of birth:" << dob <<endl;
        cout << "Person phone number:" << phone <<endl;
        cout << endl;
    }
};

class Item
{
public:
    int code;
    string name;
    float cost;
    int quantity;

    Item(int a, string b, float c, int d)
    {
        code = a;
        name = b;
        cost = c;
        quantity = d;
    }

    void display() const
    {
        cout << "Item code:" << code << endl;
        cout << "Item name:" << name << endl;
        cout << "Item cost:" << cost << endl;
        cout << "Item quantity:" << quantity << endl;
        cout << endl;
    }
};

vector<Person> person;
vector<Item> item;

void addPerson()
{
    string name;
    string dob;
    string phone;
    cout << "Enter person name:";
    cin >> name;
    cout << "Enter person date of birth(YYYY-MM-DD):";
    cin >> dob;
    cout << "Enter person phone number:";
    cin >> phone;
    person.push_back(Person(name, dob, phone));
    cout << "\n Person added successfully";
}

void addItem()
{
    int code;
    string name;
    float cost;
    int quantity;
    cout << "Enter item code:";
    cin >> code;
    cout << "Enter item name:";
    cin >> name;
    cout << "Enter item cost:";
    cin >> cost;
    cout << "Enter item quantity:";
    cin >> quantity;
    item.push_back(Item(code, name, cost, quantity));
    cout << "\n Item added successfully";
}

bool comparePerson(const Person &a, const Person &b)
{
    return a.name < b.name;
}

bool compareItem(const Item &a, const Item &b)
{
    return a.name < b.name;
}

void sortPerson()
{
    sort(person.begin(), person.end(), comparePerson);
    cout << "Sorted person records:" << endl;
    for (const auto &p : person)
    {
        p.display();
    }
}

void sortItem()
{
    sort(item.begin(), item.end(), compareItem);
    cout << "Sorted item records:" << endl;
    for (const auto &i : item)
    {
        i.display();
    }
}

void searchPerson()
{
    string name;
    cout << "Enter person name to search:";
    cin >> name;
    bool found=false;
    for(const auto &p:person){
        if(p.name==name){
            cout<<"Person found";
            p.display();
            found=true;
            break;

        }
    }
    if(!found){
        cout<<"Person not found";
    }
}

void searchItem()
{
    int code;
    cout << "Enter item code to search:";
    cin >> code;
    auto it = find_if(item.begin(), item.end(), [code](const Item &i)
                      { return i.code == code; });
    if (it != item.end())
    {
        cout << "Item found";
        it->display();
    }
    else
    {
        cout << "Item not found";
    }
}

int main()
{
    int choice;
    do
    {
        cout << "Menu" << endl;
        cout << "1. Add person" << endl;
        cout << "2. Add item" << endl;
        cout << "3. Sort person records" << endl;
        cout << "4. Sort item records" << endl;
        cout << "5. Search person" << endl;
        cout << "6. Search item" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice:";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addPerson();
            break;

        case 2:
            addItem();
            break;

        case 3:
            sortPerson();
            break;

        case 4:
            sortItem();
            break;

        case 5:
            searchPerson();
            break;

        case 6:
            searchItem();
            break;

        case 7:
            cout << "Exiting the code";
            break;

        default:
            cout << "Invalid choice!Please try again";
        }
    } while (choice != 7);
    return 0;
}
