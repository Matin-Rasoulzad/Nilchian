//
// Created by Matin on 5/22/2024.
//

#include "Employee.h"

// Constructor
Employee::Employee(string name, string id, Address address, int hourWork, int salaryPerHour, int workToDo, int workDone)
        : Person(name, id, address), hourWork(hourWork), salaryPerHour(salaryPerHour), workToDo(workToDo), workDone(workDone) {
    if (!validate(id)) {
        cout << "Invalid Id!\n";
        exit(1);
    }
}

// Copy constructor
Employee::Employee(const Employee &obj)
        : Person((Person &) obj), hourWork(obj.hourWork), salaryPerHour(obj.salaryPerHour), workToDo(obj.workToDo), workDone(obj.workDone) {}

// Setters
void Employee::setEmployee(string name, string id, Address address, int hourWork, int salaryPerHour, int workToDo, int workDone) {
    setPerson(name, id, address);
    this->hourWork = hourWork;
    this->salaryPerHour = salaryPerHour;
    this->workToDo = workToDo;
    this->workDone = workDone;
}

// Getters
string Employee::getEmployee() const {
    return getPerson() + "Hours Worked: " + to_string(hourWork) + ", Salary per Hour: " + to_string(salaryPerHour) +
           ", Work To Do: " + to_string(workToDo) + ", Work Done: " + to_string(workDone) + "\n";
}

// Overloaded << operator
ostream &operator<<(ostream &os, const Employee &employee) {
    os << static_cast<const Person&>(employee);
    os << "Hours Worked: " << employee.hourWork << ", Salary per Hour: " << employee.salaryPerHour
       << ", Work To Do: " << employee.workToDo << ", Work Done: " << employee.workDone << "\n";
    return os;
}

// Overloaded >> operator
istream &operator>>(istream &is, Employee &employee) {
    is >> (Person&)employee;
    cout << "Enter Hours Worked: ";
    is >> employee.hourWork;
    cout << "Enter Salary per Hour: ";
    is >> employee.salaryPerHour;
    cout << "Enter Work To Do: ";
    is >> employee.workToDo;
    cout << "Enter Work Done: ";
    is >> employee.workDone;
    return is;
}

// Assignment operator
Employee &Employee::operator=(const Employee &other) {
    if (this == &other)
        return *this;
    Person::operator=(other);
    hourWork = other.hourWork;
    salaryPerHour = other.salaryPerHour;
    workToDo = other.workToDo;
    workDone = other.workDone;
    return *this;
}

// Validation function
bool Employee::validate(string id) {
    if (!isValid(id)) return false;
    if (id[2] != '*') return false;
    return true;
}

// Calculate salary function
int Employee::calculateSalary() const {
    double completedWorkRatio = (double)(workDone) / workToDo;
    double reduction = 1.0 - completedWorkRatio;
    int salary = hourWork * salaryPerHour;
    return (int)(salary * (1.0 - reduction));
}

// Efficiency function
double Employee::efficiency() const {
    return (double)(workDone) / hourWork;
}
