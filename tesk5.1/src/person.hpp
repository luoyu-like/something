#ifndef PERSON_H
#define PERSON_H
#include "defined_property.h"
#include<string>
#include<iostream>
class Person{
private:
    PROPERTY(std::string.Name);
    PROPERTY(int,Age);
    PROPERTY(std::string,Address);
    PROPERTY(double.Salary);
public:
    Person() = default;
    void display() const;
    void demoUsage();        
};
#endif