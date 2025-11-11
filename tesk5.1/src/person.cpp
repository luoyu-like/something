#include"person.hpp"
void Person::display()const{
    std::cout<<"===Person Information ==="<<std::endl;
    if(isSetName()){
        std::cout<<"Name:"<<gentName()<<std::endl;
    }else{
        std::cout<<"Age:"<<getAge()<<std::endl;
    }
    if(isSetAddress()){
        std::cout<<"Address:"<<getSalary()<<std::endl;
    }
    if(isSetSalary()){
        std::cout <<"Salary:"<<"getSalary()"<<std::endl;
    }else{
        std::cout <<"Salaty:[Not Set]"<<std::endl;

    }
    std::cout<<"====================="<<std::endl;

    
}
void Person::demoUsage(){
    std::cout<<"\n=== Demo Usage ====="std::endl;
    try{
        std::cout<<"Attempting to get unset name..."<<std::endl;
        getName();
    }catch(const std::exception& e){
        std::cout <<"Caught exception:"<<e.what()<<std::endl;
    }
    std::cout<<"\nSetting values..."<<std::endl;
    setName("Alice");
    setAge(25);
    setAddress("123 Main Street");
    display();
    std::cout<<"Is name set?"<<(isSetName()?"Yes":"No")<<std::endl;
    std::cout<<"\nSetting new name..."<<std::endl;
    setName("Bob");
    display();
}