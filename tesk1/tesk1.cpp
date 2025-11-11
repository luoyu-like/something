#include<iostream>
#include<Eigen/Dense>
using namespace Eigen;
using namespace std;
int main(){
    cout<<"===Eigen库运行示例==="<<endl;
    Matrix3d A;
    A << 1,2,3,
         4,5,6,
         7,8,10;
    Vector3d b(1,1,1);
    cout<<"矩阵A:\n"<<A<<endl;
    cout<<"向量b:\n"<<b<<endl;
    Matrix3d A_squared = A*A;
    cout<<"A的平方:\n"<<A_squared<<endl;
    Vector3d x =A.colPivHouseholderQr().solve(b);
    cout<<"解 x(Ax = b):\n"<<x<<endl;
    Vector3d b_verify = A * x;
    cout <<"验证A*x:\n"<<b_verify<<endl;
    EigenSolver<Matrix3d> solver(A);
    cout<<"特征值:\n"<<solver.eigenvalues()<<endl;
    cout<<"特征向量:\n"<<solver.eigenvectors()<<endl;
    cout<<"行列式:\n"<<A.determinant()<<endl;
    cout<<"逆矩阵:\n"<<A.inverse()<<endl;
    return 0;
}
