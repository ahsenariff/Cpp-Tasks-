#include <iostream>
using namespace std;

class Truck;

class Car {
    public:
        double speed;
        double distance;
public:
    Car(int s, int d) {
        speed = s;
        distance = d;
    }
    int sp_greater(Truck t);
    friend void travel_time(Car c, Truck t);
};

class Truck {
    public:
    double speed;
    double distance;

public:
    Truck(int s, int d) {
        distance = d;
        speed = s;
    }
    friend int Car::sp_greater(Truck t);
    friend void travel_time(Car c, Truck t);
};


int Car::sp_greater(Truck t) {
    return speed - t.speed;
}

void travel_time(Car c, Truck t) {
    double time_car = c.distance / c.speed;
    double time_truck = t.distance / t.speed;

    cout << "Travel time of the car: " << time_car << "\n";
    cout << "Travel time of the truck: " << time_truck << "\n";
}

int main() {
    int t;
    Car c1(55, 300);
    Truck t1(55, 400);

    cout << "Comparing c1 and t1:\n";
    t = c1.sp_greater(t1);
    if (t < 0)
        cout << "Truck is faster.\n";
    else if (t == 0)
        cout << "Car and truck speed is the same.\n";
    else
        cout << "Car is faster.\n";

    // cout << "\nComparing c2 and t2:\n";
    // t = c2.sp_greater(t2);
    // if (t < 0)
    //     cout << "Truck is faster.\n";
    // else if (t == 0)
    //     cout << "Car and truck speed is the same.\n";
    // else
    //     cout << "Car is faster.\n";


    // Car car1(55, 300);
    // Truck truck1(55, 300);
    travel_time(c1, t1);

    return 0;
}

