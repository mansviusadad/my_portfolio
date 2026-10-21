/* Define an abstract class `Vehicle` with pure virtual functions `startEngine()` and `drive()`. Implement concrete classes `Car` 
and `Bike` that inherit from `Vehicle`. Demonstrate polymorphism by creating an array of `Vehicle` pointers, pointing to objects of 
both `Car` and `Bike`. Call the `startEngine()` and `drive()` functions for each object.*/

#include<iostream>
using namespace std;

class Vehicle
{
    public:
        virtual void startEngine() = 0;
        virtual void drive() = 0;
};

class Car : public Vehicle
{
    public:
        void startEngine()
        {
            cout << "Car Engine Started" << endl;
        }

        void drive()
        {
            cout << "Car is Driving" << endl;
        }
};

class Bike : public Vehicle
{
    public:
        void startEngine()
        {
            cout << "Bike Engine Started" << endl;
        }

        void drive()
        {
            cout << "Bike is Driving" << endl;
        }
};

int main()
{
    Car c;
    Bike b;

    Vehicle *v[2];

    v[0] = &c;
    v[1] = &b;

    v[0]->startEngine();
    v[0]->drive();

    cout << endl;

    v[1]->startEngine();
    v[1]->drive();

    return 0;
}

