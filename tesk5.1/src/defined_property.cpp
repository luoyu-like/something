#ifndef DEFINED_PROPERTY_H
#define DEFINED_PROPERTY_H


#include<iostream>
#include<string>
#include<stdexcept>
#include<optional>
template<typename T>
class DefinedProerty{
private:
    std::optional<T> value_;
    bool defined_ = false;
public:
    void set(const T& value){
        value_ = value;
        defined_ = true;
    }
    void set(T&& value){
        value_ = std::move(value);
        defined_ = true;
 
   }
   const T& get() const { 
        if(!defined_){
            throw std::runtime_error("Property is not defined");
        }
        return value_.value();
   }
   T& getRef(){
        if(!defined_){
            throw std::runtime_error("Property is defined");
        
        }
        return value_.value();
   }
   bool isSEt() const{
      return defined_;  
   }void clear(){
        defined_ = false;
   }
   DefinedProperty<T>& opterator=(const T& value){
        set(value);
        return *this;
   }
   opterator T() const{
    return get();
   }

};
#define DECLARE_PROPERTY(type,name) \
private: \
    DefinedProperty<type>name##_; \
public: \
    void set##name(const type& value);\
    type get##name() const; \
    bool isSet##name() const;\
    void clear##name();
#define IMPLEMENT_PROPERTY(class_name,type& value){\
    void class_name::set##name(const type& value){\
        name##_.set(value);\
    }\
    type class_name::get##name(){\
        return name##_.get();\
    }\
    bool class_name::isSet##name()const{\
        return name##_.isSet();\
    }\
    void class_name::clear##name(){\
        name##_.clear();\
    }
    #endif
}
