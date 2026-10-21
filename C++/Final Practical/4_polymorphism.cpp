/*  Extend the `Shape` hierarchy from Question 3 to include a virtual function `displayDetails()`. Implement the `displayDetails()` 
function in each derived class to print information specific to the shape. Create an array of `Shape` pointers, pointing to objects 
of different shapes. Demonstrate polymorphism by calling the `displayDetails()` function for each object.*/

#include<iostream>
#include<string>
using namespace std;

class Shape
{
private:
    string color;
    float area;

public:
    void setData(string c, float a)
    {
        color = c;
        area = a;
    }

    string getColor()
    {
        return color;
    }

    float getArea()
    {
        return area;
    }

    virtual void displayDetails()
    {
        cout << "Shape Details" << endl;
    }
};

class Circle : public Shape
{
public:
    void calculateArea(float r)
    {
        setData("Red", 3.14 * r * r);
    }

    void displayDetails()
    {
        cout << "Circle Color: " << getColor() << endl;
        cout << "Circle Area: " << getArea() << endl;
    }
};

class Rectangle : public Shape
{
public:
    void calculateArea(float l, float w)
    {
        setData("Blue", l * w);
    }

    void displayDetails()
    {
        cout << "Rectangle Color: " << getColor() << endl;
        cout << "Rectangle Area: " << getArea() << endl;
    }
};

int main()
{
    Circle c;
    Rectangle r;

    c.calculateArea(5);
    r.calculateArea(4, 6);

    Shape *s[2];

    s[0] = &c;
    s[1] = &r;

    s[0]->displayDetails();
    cout << endl;
    s[1]->displayDetails();

    return 0;
}

