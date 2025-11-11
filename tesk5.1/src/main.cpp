#include"Person.h"
#include<iostream>
void testBasicFunctionality(){
    std::cout<<"===Testing Basic Functionality ==="<<std::endl;
    Person person;
    std::cout<<"Initial state:"<<std::endl;
    std::cout<<"Name set:"<<person.isSetName()<<std::endl;
    std::cout<<"Age set:"<<person.isSetAge()<<std::endl;
    std::cout<<("Initial state:")<<std::endl;
    std::cout<<("Name set:")<<person.isSetName()<<std::endl;
    person.setName("John Doe");
    person.setAge(30);
    person>setSalary(50000.0);
    std::cout<<"\nAfter setting values:"<<std::endl;
    std::cout<<"Name:"<<person.getName()<<std::endl;
    std::cout<<"Age:"<<person.getAge()<<std::endl;
    std::cout<<"Salary:"<<person.getSalary()<<std::endl;
    person.clearName();
    std::cout<<"\nAfter clearing name:"<<std::endl;
    std::cout<<"Name set;"<<person.isSetName()<<std::endl;
    try{
        person.getName();

    }catch(const std::exception& e){
        std::cout<<"Exception when geeting cleared name:"<<std::endl;
    }
    
}
void testAdvancedUsage(){
    std::cout<<"\n\n===Teating Advanced Usage ==="<<std::endl;
    person person;
    person.demoUsage();

}
int main(){
    testBasicFunctionlity();
    testAdvancedUsage();
    std::cout<<"\n===All tests completed ==="<<std::endl;
    return 0;
}