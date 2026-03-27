#include <iostream>
#include <vector>

//===================================================
template <typename T>
class ServiceStation {
public:

    class Garage {
    public:
        void addGarage(T& other) {
            if (other.getisRepaired()) {
                garageRepaired.push_back(other);
            }
        }

        void DisplayAll() {
            for (int i = 0; i < garageRepaired.size(); ++i) {
                std::cout << garageRepaired[i];
            }
        }
    
        std::vector<T> garageRepaired;
    };

    ServiceStation() = default;

    void addCar(T& other) {
        if (station.size() >= 5) {
            std::cout << "The station is full.\n";
            return;
        }
        station.push_back(other);
    }

    void RepairAll() {
        std::cout << "Before repair:\n";
        for (int i = 0; i < station.size(); ++i) {
            std::cout << station[i];
        }
        for (int i = 0; i < station.size(); ++i) {
            station[i].repair();
            GarageObj.addGarage(station[i]);
        }
        station.clear();
        std::cout << "-------------------------------\nAfter repair:\n";
        DisplayGarage();
        std::cout << "-------------------------------\n";
    }

    void DisplayGarage() {
        GarageObj.DisplayAll();
    }

private:
    std::vector<T> station;
    Garage GarageObj;
};

//===================================================

class PassangerCar {
public:
    PassangerCar(std::string name) {
        _name = name;
    }

    void repair() {
        isRepaired = 1;
    }

    bool getisRepaired() {
        return isRepaired;
    }

    friend std::ostream& operator<<(std::ostream& os, const PassangerCar& car) {
        os << "[Passanger] " << car._name
            << " | repaired: " << (car.isRepaired ? "yes" : "no") << "\n";
        return os;
    }
private:
    std::string _name;
    bool isRepaired = 0;
};

class CargoCar {
public:
    CargoCar(std::string name) {
        _name = name;
    }

    void repair() {
        isRepaired = 1;
    }

    bool getisRepaired() {
        return isRepaired;
    }

    friend std::ostream& operator<<(std::ostream& os, const CargoCar& car) {
        os << "[Cargo] " << car._name
            << " | repaired: " << (car.isRepaired ? "yes" : "no") << "\n";
        return os;
    }
private:
    std::string _name;
    bool isRepaired = 0;
};

//===================================================

int main()
{
    std::cout << "Hello World!\n";
    ServiceStation<PassangerCar> PassangerStation;
    ServiceStation<CargoCar> CargoStation;

    PassangerCar Volvo("Volvo");
    for (int i = 0; i < 6; ++i) {
        PassangerStation.addCar(Volvo);
    }
    PassangerStation.RepairAll();

    for (int i = 0; i < 6; ++i) {
        PassangerStation.addCar(Volvo);
    }
    PassangerStation.RepairAll();

    CargoCar MTW("Belarus");
    for (int i = 0; i < 6; ++i) {
        CargoStation.addCar(MTW);
    }
    CargoStation.RepairAll();
}

