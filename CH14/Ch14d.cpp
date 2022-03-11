#include "std_lib_facilities.h"

//g++ Ch14d.cpp -o drill14

class B1{

public:
	virtual void vf(){
		cout << "B1::vf()" << endl;
	}
	void f(){
		cout << "B1::f()" << endl;
	}
	virtual void pvf(){
		cout << "B1::pvf()" << endl;
	}
	
	};

class D1 : public B1{
	public: 
		void vf() override { cout << "D1::vf()" << endl;}
			
		void f(){
				cout << "D1::f()" << endl;
			}
		void pvf() override {cout << "D1::pvf()" << endl;}
};

class D2 : public D1{
public:
	void pvf() override {cout << "D2::pvf()" << endl;}
};

class B2{
public:
	virtual void pvf(){
		cout <<"B2::pvf()"<< endl;
	}
};

class D21 : public B2{
public:
	string s;
	void pvf() override {cout << s << endl;}

};

class D22 : public B2{
public:
	int i;
	void pvf() override {cout << i << endl;}
};

void f(B2& b2Ref) {
 	b2Ref.pvf(); 
}


int main(){

	//1.
	B1 b1;
	b1.vf();
	b1.f();
	b1.pvf();
	
	cout << "" << endl;
	
	//2.
	D1 d1;
	d1.vf();
	d1.f();
	d1.pvf();
	
	cout << "" << endl;
	
	//3
	B1& b1r = d1;
	b1r.vf();
	b1r.f();

	cout << "" << endl;

	//4
	D1 d2;
	d2.vf();
	d2.f();

	cout << "" << endl;

	//6
	D2 d3;
	d3.vf();
	d3.f();
	d3.pvf();

	cout << "" << endl;

	//7
	D21 d21;
	d21.s = "This is a string";
	d21.pvf();

	cout << "" << endl;

	//7
	D22 d22;
	d22.i = 5;
	d22.pvf();

	cout << "" << endl;

	f(d21);
	f(d22);
	return 0;
}
