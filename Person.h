//
// Created by Matin on 5/22/2024.
//

#ifndef ADDRESS_PERSON_H
#define ADDRESS_PERSON_H
#include "Address.h"
#include "iostream"
using namespace std;

class Person {
private:

    string name , id;
    Address address;
public:
    Person(string name, string id, Address address);
    Person(Person& obj);
    string getPerson() const;
    Person& operator=(const Person& other);
    void setPerson(string name ,string id ,Address address);
    friend ostream& operator<<(ostream& os, const Person& person);
    friend istream& operator>>(istream& is, Person& person);
    bool isValid(string id);
};


#endif //ADDRESS_PERSON_H
