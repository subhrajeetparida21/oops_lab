#include <iostream>
using namespace std;

class Vehicle {
protected:
    int wheels;
    int speed;
public:
    Vehicle() : wheels(0), speed(0) {}

    void inputVehicle() {
        cout << "Enter number of wheels: ";
        cin >> wheels;
        cout << "Enter speed: ";
        cin >> speed;
    }

    void displayVehicle() const {
        cout << "Wheels: " << wheels << "\nSpeed: " << speed << endl;
    }

    int getSpeed() const {
        return speed;
    }
};

class Car : public Vehicle {
    int passengers;
public:
    Car() : passengers(0) {}

    void inputCar() {
        inputVehicle();
        cout << "Enter number of passengers: ";
        cin >> passengers;
    }

    void displayCar() const {
        cout << "\nCar Details:\n";
        displayVehicle();
        cout << "Passengers: " << passengers << endl;
    }
};

class Truck : public Vehicle {
    int loadLimit;
public:
    Truck() : loadLimit(0) {}

    void inputTruck() {
        inputVehicle();
        cout << "Enter load limit: ";
        cin >> loadLimit;
    }

    void displayTruck() const {
        cout << "\nTruck Details:\n";
        displayVehicle();
        cout << "Load Limit: " << loadLimit << endl;
    }
};

int main() {
    Car c;
    Truck t;

    cout << "Enter Car Details:\n";
    c.inputCar();

    cout << "\nEnter Truck Details:\n";
    t.inputTruck();

    c.displayCar();
    t.displayTruck();

    cout << "\nSpeed Comparison: ";
    if (c.getSpeed() > t.getSpeed())
        cout << "Car is faster than Truck.\n";
    else if (c.getSpeed() < t.getSpeed())
        cout << "Car is slower than Truck.\n";
    else
        cout << "Car and Truck have the same speed.\n";

    return 0;
}
