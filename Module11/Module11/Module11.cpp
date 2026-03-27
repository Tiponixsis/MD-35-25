#include <iostream>
#include <vector>

class Employee {
public:
    virtual ~Employee() = default;
};

class Manager : public Employee {
public:
    void manageTeam() {
        std::cout << "I'm managing it!\n";
    }
private:

};

class Developer : public Employee {
public:
    void writeCode() {
        std::cout << "I'm developing it!\n";
    }
private:

};

std::vector<Employee*> Employees;

void add(Employee* other) {
    Employees.push_back(other);
}

void checkEmployees(){
    for (int i = 0; i < Employees.size(); ++i) {
        if (auto m = dynamic_cast<Manager*>(Employees[i])) {
            m->Manager::manageTeam();
        }
        else {
            auto d = dynamic_cast<Developer*>(Employees[i]);
            d->Developer::writeCode();
       }
   }
}

int main() {
    std::cout << "Hello World!\n";
    Manager John;
    Developer Mike;
    Developer Smith;
    Developer Jenna;
    add(&Smith);
    add(&John);
    add(&Mike);
    add(&Jenna);
    checkEmployees();
}

