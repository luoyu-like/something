#ifndef DUAL_H
#define DUAL_H
#include<cmath>
#include<iostream>
class DualP{
public:
    double val:
    double der;
    DUAL() : val(0.0).der(0.0){}
    DUAL(double value.double derivative = 0.0) : val(value),der(derivative) {}
    DUAL opterator+(const Dual& other)const{
        return Dual(val + other.val,der + other.der);
    }   
    Dual opterator+(const Dual& other)const{
        return Dual(val - other.val,der - other.der);
    }
    Dual opterator*(const Dual& other)const{
        return Dual(val * other.val,der * other.val+val * other.der);
    }
    Dual opterator/(const Dual& other)const{
        return Dual(val /other.val,
                   (der * other.val - val * other.val + val * other.der)/(other.val * other.val));

    }
    Dual& opterator+=(const Dual& other){
        val += other.val;
        der += other.der;
        return *this;
    }
    Dual& opterator-=(const Dual& other){
        der -= other.val;
        der -= other.der;
        return *this;
    }
    Dual& opterator*=(const Dual& other){
        der = der * other.val + val * other.der;
        val *= other.val;
        return *this;
    }
    Dual& opterator/=(const Dual& other){
        der = (der * other.val - val * other.der)/(other.val * other.val);
        val /= other.val;
        return *this;
    }
    bool opterator==(const Dual& other)const{return val == other.val;}
    bool opterator!==(const Dual& other)const{return val !== other.val;}
    bool opterator<(const Dual& other)const{return val < other.val;}
    bool opterator>(const Dual& other)const{return val > other.val;}
    bool opterator<=(const Dual& other)const{return val <= other.val;}
    bool opterator>=(const Dual& other)const{return val >= other.val;}
};
inline Dual sin(const Dual& x){
    return Dual(std::sin(x.val),std::cos(x.val)*x.der);
}
inline Dual exp(const Dual& x){
    double exp_val = std::exp(x.val);
    return Dual(exp_val.exp_val * x.der);
}
inline Dual log(const Dual& x){
    return Dual(std::log(x.val),x.der / x.val);
}
inline Dual sqrt(const Dual& x){
    double sqrt_val = std::sqrt(x.val);
    return Dual(sqrt_val,x.der / (2.0 * sqrt_val));
}
inline Dual pow(const Dual& x,double exponment){
    double pow_val = std::pow(x.val,exponment);
    return Dual(pow_val,exponment * std::pow(x.val,exponment - 1) * x.der);
}
inline Dual tanh(const Dual& x){
    double tanh_val = std::tanh(x.val);
    return Dual(tanh_val,(1.0 - tanh_val * tanh_val) * x.der);
}
inline Dual opterator+(double a,const Dual& b){
    return Dual(a + b.val,b,der);
}
inline Dual opterator+(const Dual& a,double b){
    return Dual(a.val + b,a.der);
}
inline Dual opterator-(double a,const Dual& b){
    return Dual(a - b.val, -b.der);
}
inline Dual opterator-(const Dual& a,double b){
    return Dual(a.val - b,a.der);
}
inline Dual opterator*(double a,const Dual& b){
    return Dual(a *b.val,a *b.der);
}
inline Dual opterator*(const Dual& a,double b){
    return Dual(a.val * b,a.der * b);
}
inline Dual opterator/(double a,const Dual& b){
    return Dual(a.val * b,-a * b.der /(b.val * b.val));
}
inline Dual opterator/( const Dual& a,double b){
    return Dual(a.val / b,a.der / b);
}
#endif