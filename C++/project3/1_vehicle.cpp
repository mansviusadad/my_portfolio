
/* Vehicle Registry System */

#include<iostream>
#include<cstring>
using namespace std;

class Vehical
{
protected:
    int vehicalID;
    char manufacture[30];
    char model[30];
    int year;

public:
    static int totalVehicles;

    Vehical()
    {
        vehicalID = 0;
        year = 0;
        strcpy(manufacture, "unknown");
        strcpy(model, "unknown");
    }

    void getData()
    {
        cout << "Enter Vehicle ID: ";
        cin >> vehicalID;

        cout << "Enter Manufacturer: ";
        cin >> manufacture;

        cout << "Enter Model: ";
        cin >> model;

        cout << "Enter Year: ";
        cin >> year;

        totalVehicles++;
    }

    virtual void display()
    {
        cout << "\nVehicle ID: " << vehicalID << endl;
        cout << "Manufacturer: " << manufacture << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }

    int getID()
    {
        return vehicalID;
    }

    virtual ~Vehical()
    {
    }
};

int Vehical::totalVehicles = 0;


// Single Inheritance
class Car : public Vehical
{
protected:
    char fuelType[20];

public:
    void getCarData()
    {
        getData();

        cout << "Enter Fuel Type: ";
        cin >> fuelType;
    }

    void display() override
    {
        Vehical::display();
        cout << "Fuel Type: " << fuelType << endl;
    }
};


// Multilevel Inheritance
class ElectricCar : public Car
{
protected:
    int batteryCapacity;

public:
    void getElectricData()
    {
        getCarData();

        cout << "Enter Battery Capacity: ";
        cin >> batteryCapacity;
    }

    void display() override
    {
        Car::display();
        cout << "Battery Capacity: "
             << batteryCapacity << " kWh" << endl;
    }
};


// Multilevel Inheritance
class SportsCar : public ElectricCar
{
    int topSpeed;

public:
    void getSportData()
    {
        getElectricData();

        cout << "Enter Top Speed: ";
        cin >> topSpeed;
    }

    void display() override
    {
        ElectricCar::display();
        cout << "Top Speed: " << topSpeed << " km/h" << endl;
    }
};


// Hierarchical Inheritance
class Sedan : public Car
{
public:
    void getSedanData()
    {
        getCarData();
    }

    void display() override
    {
        cout << "\n--- Sedan Details ---" << endl;
        Car::display();
    }
};


// Hierarchical Inheritance
class SUV : public Car
{
public:
    void getSUVData()
    {
        getCarData();
    }

    void display() override
    {
        cout << "\n--- SUV Details ---" << endl;
        Car::display();
    }
};


// Multiple Inheritance
class Aircraft
{
protected:
    int flightRange;

public:
    Aircraft()
    {
        flightRange = 0;
    }
};

class FlyingCar : public Car, public Aircraft
{
public:
    void getFlyingData()
    {
        getCarData();

        cout << "Enter Flight Range: ";
        cin >> flightRange;
    }

    void display() override
    {
        cout << "\n--- Flying Car Details ---" << endl;
        Car::display();
        cout << "Flight Range: " << flightRange << " km" << endl;
    }
};


// Vehicle Registry
class VehicalRegistry
{
    Vehical *v[100];
    int count;

public:
    VehicalRegistry()
    {
        count = 0;
    }

    void addVehicle()
    {
        int choice;

        cout << "\n1. Car";
        cout << "\n2. Electric Car";
        cout << "\n3. Sports Car";
        cout << "\n4. Sedan";
        cout << "\n5. SUV";
        cout << "\n6. Flying Car";
        cout << "\nEnter Choice: ";
        cin >> choice;

        if(count >= 100)
        {
            cout << "Registry is full!";
            return;
        }

        switch(choice)
        {
            case 1:
                v[count] = new Car;
                ((Car*)v[count])->getCarData();
                break;

            case 2:
                v[count] = new ElectricCar;
                ((ElectricCar*)v[count])->getElectricData();
                break;

            case 3:
                v[count] = new SportsCar;
                ((SportsCar*)v[count])->getSportData();
                break;

            case 4:
                v[count] = new Sedan;
                ((Sedan*)v[count])->getSedanData();
                break;

            case 5:
                v[count] = new SUV;
                ((SUV*)v[count])->getSUVData();
                break;

            case 6:
                v[count] = new FlyingCar;
                ((FlyingCar*)v[count])->getFlyingData();
                break;

            default:
                cout << "Invalid Choice!" << endl;
                return;
        }

        count++;
        cout << "\nVehicle Added Successfully!" << endl;
    }

    void displayAll()
    {
        if(count == 0)
        {
            cout << "No Vehicles Found!" << endl;
            return;
        }

        for(int i = 0; i < count; i++)
        {
            cout << "\n--- Vehicle Details ---" << endl;
            v[i]->display();
        }
    }

    void searchVehicle()
    {
        int id;

        cout << "Enter Vehicle ID: ";
        cin >> id;

        for(int i = 0; i < count; i++)
        {
            if(v[i]->getID() == id)
            {
                cout << "\nVehicle Found!" << endl;
                v[i]->display();
                return;
            }
        }

        cout << "Vehicle Not Found!" << endl;
    }

    ~VehicalRegistry()
    {
        for(int i = 0; i < count; i++)
        {
            delete v[i];
        }
    }
};


// Main Function
int main()
{
    VehicalRegistry vr;
    int choice;

    do
    {
        cout << "\n\n===== VEHICLE REGISTRY SYSTEM =====";
        cout << "\n1. Add Vehicle";
        cout << "\n2. View All Vehicles";
        cout << "\n3. Search Vehicle by ID";
        cout << "\n4. Total Vehicles";
        cout << "\n5. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                vr.addVehicle();
                break;

            case 2:
                vr.displayAll();
                break;

            case 3:
                vr.searchVehicle();
                break;

            case 4:
                cout << "Total Vehicles: "
                     << Vehical::totalVehicles << endl;
                break;

            case 5:
                cout << "Thank You!";
                break;

            default:
                cout << "Invalid Choice!";
        }

    } while(choice != 5);

    return 0;
}

