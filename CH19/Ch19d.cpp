#include "std_lib_facilities.h"

//g++ Ch19d.cpp -o drill19

template<typename T>
struct S {
private:
	T val;
public:
	S(T x){
		val = x;
	}
	T& get();
	T get()const;
	T read_val();

//	void set(T new_val)
//	{
//		val = new_val;
//	}

	void operator=(const T& thing)
	{
		val = thing;
	}

};

template<typename T>
T& S<T>::get()
{
	return val;
}

template<typename T>
T S<T>::get()const
{
	return val;
}

template<typename T> void read_val(T& v)
{
    cin >> v;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v)
{
	os << "{";
	for(int i = 0; i< v.size();i++){
		os << v[i] << ", ";
	}
	os << "}";

	return os;
}


int main(){

	S<int> number(19);
	cout<< number.get() << endl;

//	number.set(20);
//	cout<< number.get() << endl;

	number = 21;
	cout<< number.get() << endl;


	S<char> character('a');
	cout<< character.get() << endl;

	character = 'd';
	cout<< character.get() << endl;

	S<double> ddouble(4.1);
	cout<< ddouble.get() << endl;

	ddouble = 4.2;
	cout<< ddouble.get() << endl;

	S<string> text("This is a string.");
	cout<< text.get() << endl;

	text = ".gnirts a si sihT";
	cout<< text.get() << endl;

	S<vector<int>> numbers({1,13,21,9,7});

	cout << numbers.get() << endl;


	cout << "using read_val()" << endl;
	int ii;
	read_val(ii);
	number = ii;
	cout<< number.get() << endl;

	char cc;
	read_val(cc);
	character = cc;
	cout << character.get() << endl;

	double dd;
	read_val(dd);
	ddouble = dd;
	cout << ddouble.get() << endl;

	string ss;
	read_val(ss);
	text = ss;
	cout << text.get() << endl;

}