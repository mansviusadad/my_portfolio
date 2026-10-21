/*Create a class `Laptop` with private attributes `name`, `price`, `processor`, and a parameterized constructor. 
Demonstrate the instantiation of objects using this constructor.*/

#include <iostream>
#include <string>
using namespace std;

class Laptop
{
private:
    string name;
    int price;
    string processor;

public:
    Laptop(string n, int p, string pr)
    {
        name = n;
        price = p;
        processor = pr;
    }

    void display()
    {
        cout << "Laptop Name: " << name << endl;
        cout << "Laptop Price: " << price << endl;
        cout << "Processor: " << processor << endl;
    }
};

int main()
{
    Laptop l1("HP", 50000, "i5");
    Laptop l2("Dell", 60000, "i7");

    l1.display();
    cout << endl;
    l2.display();

    return 0;
}

