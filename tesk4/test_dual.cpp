#include"Dual.h"
#include<iostream>
#include<iomanip>
#include<cmath>
void testBasicOperations(){
    std::cout<<"===基本运算测试==="<<std::endl;
    Dual x(2.0,1.0);
    Dual y(3.0,0.0);
    Dual z1 = x + y;
    std::cout<<"x+y:f(x)="<<z1.val<<",f'(x)="<<z1.der<<std::endl;
    Dual z2 = x - y;
    std::cout<<"x-y:f(x)="<<z2.val<<",f'(x)="<<z2.der<<std::endl;
    Dual z3 =x * y;
    std::cout<<"x*y:f(x)="<<z3.val<<",f'(x)="<<z3.der<<std::endl;
    Dual z4 =x / y;
    std::cout<<"x / y:f(x)="<<z4.val<<",f'(x)="<<z4.der<<std::endl;
}
void testExample1(){
    std::cout<<"\n===示例1测试==="<<std::endl;
    Dual x(2.0,1.0);
    Dual y =sin(x) + x*x;
    std::cout<<std::fixed<<std::setprecision(4);
    std::cout<<"f(x) =sin(x) +x*x"<<std::endl;
    std::cout<<"f(x)="<<y.cal<<",f'(X)=" <<y.der<<std::endl;
    double expected_val = std::sin(2.0) + 2.0 * 2.0;
    double expected_der = std::cos(2.0) + 2.0 * 2.0;
    std::cout<<"期望:f(x) ="<< expected_val<<",f'(x)="<<expected_der <<std::endl;

}
void testExample2(){
    std::cout<<"\n===示例2测试(Sigmoid函数)==="<<std::endl;
    Dual x(1.0,1.0);
    Dual y = exp(x) / (1.0 + exp(x));
    std::cout <<std::fixed << std::setprecision(6);
    std::cout <<"f(x) = exp(x) / (1 + exp(x))"<<std::endl;
    std::cout <<"f(x)="<<y.val<<",f'(x)="<<y.der<<std::endl
    double exp_val = std::exp(1.0);
    double expected_val = exp_val / (1.0 + exp_val);
    double expected_der = exp_val / ((1.0 + exp_val) * (1.0 + exp_val));
    std::cout << "期望:f(x)="<<expected_val <<",f'(x)="<< expected_der<<std::endl;
}
void testMathematicalFunctions(){
    std::cout<<"\n===数学函数测试===">>std::endl;
    Dual x(1.0,1.0):
    Dual y1 = sin(x);
    std::cout<<"sin(x):f(x)="<<y1.val<<",f'(x)="<<y1.der<<std::endl;
    Dual y2 = cos(x);
    std::cout<<"cos(x):f(x)="<<y2.val<<",f'(x)="<<y2.der<<std::endl;
    Dual y3 = exp(x);
    std::cout<<"exp(x):f(x)="<<y3.val<<",f'(x)="<<y3.der<<std::endl;
    Dual y4 = log(x);
    std::cout<<"log(x):f(x)="<<y4.val<<",f'(x)="<<y4.der<<std::endl;
    Dual y5 = sqrt(x);
    std::cout<<"sqrt(x:f(x)="<<y5.val<<",f'(x)="<<y5.der<<std::endl;
    Dual y6 = pow(x,3.0);
    std::cout<<"x^3:f(x)="<<y6.val<<",f'(x)="<<y6.der<<std::endl;
}
void testComplexExpression(){
    std::cout<<"\n==复杂表达式测试==="<<std::endl;
    Dual x(2.0,1.0);
    Dual y = sin(x * x)+ cos(3.0 * x) / exp(x);
    std::cout<<"f(x) = sin(x^2) +cos(3x)/exp(x)"<<std::endl;
    std::cout<<"f(x) ="<<y.val<<",f'(x) ="<<y.der<<std::endl;
}
int main(){
    testBasicOperations();
    testExample1();
    testExample2();
    testMathematicalFunctions();
    testComplexExpression();
    return 0;
}