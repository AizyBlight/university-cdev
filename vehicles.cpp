#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

class LandVehicle {
protected:
    string brand;
    double engineVolume;
    double maxSpeed;
    string bodyType;

public:
    LandVehicle() : brand("Unknown"), engineVolume(0), maxSpeed(0), bodyType("Unknown") {}

    LandVehicle(string b, double e, double m, string bt)
        : brand(b), engineVolume(e), maxSpeed(m), bodyType(bt) {}

    LandVehicle(const LandVehicle& other) {
        brand = other.brand;
        engineVolume = other.engineVolume;
        maxSpeed = other.maxSpeed;
        bodyType = other.bodyType;
    }

    virtual ~LandVehicle() {}

    void setBrand(string b) { brand = b; }
    string getBrand() { return brand; }

    void setEngineVolume(double e) { engineVolume = e; }
    double getEngineVolume() { return engineVolume; }

    void setMaxSpeed(double m) { maxSpeed = m; }
    double getMaxSpeed() { return maxSpeed; }

    void setBodyType(string bt) { bodyType = bt; }
    string getBodyType() { return bodyType; }

    virtual void printClassName() = 0;
    virtual void printInfo() = 0;

    virtual void start() = 0;
    virtual void drive(double distance) = 0;
    virtual void refuel() = 0;
};

class Car : public LandVehicle {
public:
    Car() : LandVehicle() {}
    Car(string b, double e, double m, string bt) : LandVehicle(b, e, m, bt) {}
    Car(const Car& other) : LandVehicle(other) {}
    ~Car() {}

    void printClassName() override {
        cout << "Car" << endl;
    }

    void printInfo() override {
        cout << "Car: " << brand << ", " << engineVolume << ", "
            << maxSpeed << ", " << bodyType << endl;
    }

    void start() override {
        cout << "Car started\n";
    }

    void drive(double distance) override {
        cout << "Car drives " << distance << " km\n";
    }

    void refuel() override {
        cout << "Car refueled\n";
    }

    void openTrunk() {
        cout << "Trunk opened\n";
    }
};

class Tank : public LandVehicle {
public:
    Tank() : LandVehicle() {}
    Tank(string b, double e, double m, string bt) : LandVehicle(b, e, m, bt) {}
    Tank(const Tank& other) : LandVehicle(other) {}
    ~Tank() {}

    void printClassName() override {
        cout << "Tank" << endl;
    }

    void printInfo() override {
        cout << "Tank: " << brand << ", " << engineVolume << ", "
            << maxSpeed << ", " << bodyType << endl;
    }

    void start() override {
        cout << "Tank started\n";
    }

    void drive(double distance) override {
        cout << "Tank moves " << distance << " km\n";
    }

    void refuel() override {
        cout << "Tank refueled\n";
    }

    void fire() {
        cout << "Tank fired!\n";
    }
};

class Neckbreaker : public LandVehicle {
public:
    Neckbreaker() : LandVehicle() {}
    Neckbreaker(string b, double e, double m, string bt) : LandVehicle(b, e, m, bt) {}
    Neckbreaker(const Neckbreaker& other) : LandVehicle(other) {}
    ~Neckbreaker() {}

    void printClassName() override {
        cout << "Neckbreaker" << endl;
    }

    void printInfo() override {
        cout << "Neckbreaker: " << brand << ", " << engineVolume << ", "
            << maxSpeed << ", " << bodyType << endl;
    }

    void start() override {
        cout << "Neckbreaker started\n";
    }

    void drive(double distance) override {
        cout << "Neckbreaker rides " << distance << " km\n";
    }

    void refuel() override {
        cout << "Neckbreaker charged\n";
    }

    void ringBell() {
        cout << "Ring ring!\n";
    }
};

class Roller : public LandVehicle {
public:
    Roller() : LandVehicle() {}
    Roller(string b, double e, double m, string bt) : LandVehicle(b, e, m, bt) {}
    Roller(const Roller& other) : LandVehicle(other) {}
    ~Roller() {}

    void printClassName() override {
        cout << "Roller" << endl;
    }

    void printInfo() override {
        cout << "Roller: " << brand << ", " << engineVolume << ", "
            << maxSpeed << ", " << bodyType << endl;
    }

    void start() override {
        cout << "Roller started\n";
    }

    void drive(double distance) override {
        cout << "Roller moves " << distance << " km\n";
    }

    void refuel() override {
        cout << "Roller refueled\n";
    }

    void flattenRoad() {
        cout << "Road flattened\n";
    }
};

int main() {
    vector<LandVehicle*> vehicles;

    int choice;

    do {
        cout << "\n1. Add object\n2. Start all\n3. Print all\n4. Unique method\n5. Drive all\n6. Refuel all\n7. Print class names\n0. Exit\n";
        cin >> choice;

        if (choice == 1) {
            int type;
            cout << "1-Car 2-Tank 3-Neckbreaker 4-Roller: ";
            cin >> type;

            if (type == 1) vehicles.push_back(new Car("Porsche", 2.0, 200, "911"));
            if (type == 2) vehicles.push_back(new Tank("T-90M", 12.0, 60, " Breakthrough"));
            if (type == 3) vehicles.push_back(new Neckbreaker("Xiaomi", 0, 25, "Turbo"));
            if (type == 4) vehicles.push_back(new Roller("CAT", 8.0, 40, "Heavy"));
        }

        if (choice == 2) {
            for (auto v : vehicles) v->start();
        }

        if (choice == 3) {
            for (auto v : vehicles) v->printInfo();
        }

        if (choice == 4) {
            int index;
            cout << "Enter index: ";
            cin >> index;

            if (index >= 0 && index < vehicles.size()) {
                LandVehicle* v = vehicles[index];

                if (typeid(*v) == typeid(Car)) {
                    dynamic_cast<Car*>(v)->openTrunk();
                }
                else if (typeid(*v) == typeid(Tank)) {
                    dynamic_cast<Tank*>(v)->fire();
                }
                else if (typeid(*v) == typeid(Neckbreaker)) {
                    dynamic_cast<Neckbreaker*>(v)->ringBell();
                }
                else if (typeid(*v) == typeid(Roller)) {
                    dynamic_cast<Roller*>(v)->flattenRoad();
                }
            }
        }

        if (choice == 5) {
    for (auto v : vehicles) v->drive(10);
        }

        if (choice == 6) {
    for (auto v : vehicles) v->refuel();
        }

        if (choice == 7) {
    for (auto v : vehicles) v->printClassName();
        }

    } while (choice != 0);

    for (auto v : vehicles) delete v;

    return 0;
}