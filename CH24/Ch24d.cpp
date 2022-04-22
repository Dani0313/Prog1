#include "std_lib_facilities.h"
#include<iostream>
#include<iomanip>
#include<cmath>
#include<complex>
#include<cerrno>
#include "include/Matrix.h"
#include "include/MatrixIO.h"

using namespace Numeric_lib;

//g++ Ch24d.cpp -o drill24

void printSqrt()
{
    int input;
    cout<<"Enter an integer number: ";  
    cin>>input;
    if (input<0)
        cout<<"No square root"<<endl;
    else
        cout<<"The square root of "<<input<<" is "<<sqrt(input)<<endl;
}




int main(){

	cout << "Size of (bits):" << endl;
	cout << "int: " << sizeof(int) << endl;
	cout << "short: " << sizeof(short) << endl;
	cout << "long: " << sizeof(long) << endl;
	cout << "float: " << sizeof(float) << endl;
	cout << "double: " << sizeof(double) << endl;
	cout << "int*: " << sizeof(int*) << endl;
	cout << "" << endl;


	Matrix<int>a(10);
	Matrix<int>b(100);
	Matrix<double>c(10);
	Matrix<int,2>d(10,10);
	Matrix<int,3>e(10,10,10);
	cout << "Size of: "<< endl;
	cout << "Matrix<int>a(10): " << sizeof(a) << endl;
	cout << "Matrix<int>b(100): " << sizeof(b) << endl;
	cout << "Matrix<double>c(10): " << sizeof(c) << endl;
	cout << "Matrix<int,2>d(10,10)" << sizeof(d) << endl;
	cout << "Matrix<int,3>e(10,10,10): " << sizeof(e) << endl;
	cout << "" << endl;

	cout << "Number of elements: " << endl;
	cout << "Matrix<int>a(10): " << a.size() << endl;
	cout << "Matrix<int>b(100): " << b.size() << endl;
	cout << "Matrix<double>c(10): " << c.size() << endl;
	cout << "Matrix<int,2>d(10,10)" << d.size() << endl;
	cout << "Matrix<int,3>e(10,10,10): " << e.size() << endl;
	cout << "" << endl;

    printSqrt();

    Matrix<double>doubles(10);
    cout<<"Enter 10 float numbers: "<<endl;
    float f_input=0;
    for (int i=0;i<10;i++)
        {
        cin>>doubles(i);
        }
    cout<<doubles<<endl;

    int n,m;
    cout<<"Enter the dimensions of the multiplication table: "<<endl;
    cin>>n>>m;
    
    Matrix<double,2> m_table(n,m);

    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            m_table(i,j)=i*j;   
    for (int i=0;i<n;i++)
        {
        for (int j=0;j<m;j++)
            cout<<m_table(i,j)<<' ';
        cout<<endl;
        }

    Matrix<complex<double>>c_matrix(10);
    cout<<"Enter ten complex numbers: "<<endl;
    for (int i=0;i<10;i++)
        {
        cin>>c_matrix(i);
        }
    cout<<c_matrix<<endl;
    complex<double> sum=accumulate(c_matrix.data(),c_matrix.data()+c_matrix.size(),complex<double>{});
    cout<<sum<<endl;

    Matrix<int,2>six_m(2,3);
    cout<<"Enter 6 integers: "<<endl;
    for (int i=0;i<2;i++)
        for (int j=0;j<3;j++)
            cin>>six_m(i,j);
    cout<<six_m<<endl;
    
    for (int i=0;i<2;i++)
        {
        for (int j=0;j<3;j++)
            cout<<six_m(i,j)<<' ';
        cout<<endl;
        }   

    return 0;
 	}