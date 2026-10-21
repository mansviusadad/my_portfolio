/* Define a base class `Shape` with private attributes `color` and `area`. Implement public methods for setting and getting these 
attributes. Derive two classes, `Circle` and `Rectangle`, from the `Shape` class. Implement methods to calculate the area specific 
to each shape. Demonstrate abstraction by calling the area calculation methods for both `Circle` and `Rectangle`.*/

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
};

class Circle : public Shape
{
public:
    void calculateArea(float r)
    {
        float a = 3.14 * r * r;
        setData("Pink", a);

        cout << "Circle Color: " << getColor() << endl;
        cout << "Circle Area: " << getArea() << endl;
    }
};

class Rectangle : public Shape
{
public:
    void calculateArea(float l, float w)
    {
        float a = l * w;
        setData("Green", a);

        cout << "Rectangle Color: " << getColor() << endl;
        cout << "Rectangle Area: " << getArea() << endl;
    }
};

int main()
{
    Circle c;
    Rectangle r;

    c.calculateArea(5);

    cout << endl;

    r.calculateArea(4, 6);

    return 0;
}

