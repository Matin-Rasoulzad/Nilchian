
//
// Created by Matin on 5/22/2024.
//

#ifndef ADDRESS_EMPLOYEE_H
#define ADDRESS_EMPLOYEE_H

#include "Person.h"

class Employee : public Person {
private:
    int hourWork;
    int salaryPerHour;
    int workToDo;
    int workDone;

public:
    Employee(string name, string id, Address address, int hourWork, int salaryPerHour, int workToDo, int workDone);
    Employee(const Employee &obj);
    string getEmployee() const;
    void setEmployee(string name, string id, Address address, int hourWork, int salaryPerHour, int workToDo, int workDone);
    friend ostream &operator<<(ostream &os, const Employee &employee);
    friend istream &operator>>(istream &is, Employee &employee);
    Employee &operator=(const Employee &other);
    bool validate(string id);
    int calculateSalary() const;
    double efficiency() const;
};

#endif //ADDRESS_EMPLOYEE_H