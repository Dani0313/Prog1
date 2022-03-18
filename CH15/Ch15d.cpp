
//g++ Ch15d.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp Lines_window.cpp -o drill15 `fltk-config --ldflags --use-images` -std=c++11

#include "Graph.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"

double one(double x){ return 1; }

double slope(double x){return x/2;}

double square(double x) { return x*x; }

double sloping_cos(double x) { return cos(x)+slope(x); }

struct Person{
	Person(){}
	Person(string nn, int aa);
	string name() const { return nev; }
	int age() const { return kor; }
private:
	string nev;
	int kor;
};

Person::Person(string n, int a) : nev{n}, kor{a}{
	if(a < 0 || a > 150){
		error("Invalid age!");
	}

	for(char c : n){
		switch(c){
		   case ';': case ':': case '"': case '[': case ']': case '*':
           case '&': case '^': case '%': case '$': case '#': case '@':
           case '!':
            error("Invalid character in name!");
            break;
           default:
            break;
		}
	}
}

ostream& operator<<(ostream& os, Person& p){
	return os << p.name()  << " , " << p.age() << endl;
}

istream& operator>>(istream& is, Person& p){
	string n;
	int a;
	is >> n >> a;
	if(!is)
		error("Unable to read into Person");

	p = Person(n , a);

	return is;
	
}

int main(){

	
	Point tl {100,100};
	Simple_window win {tl,600,600,"Function graphs"};

	const Point orig {300,300};

	constexpr int r_min = -10;
	constexpr int r_max = 11;

	constexpr int n_points = 400;

	constexpr int x_scale = 20;
	constexpr int y_scale = 20;

	Axis xa {Axis::x,Point{100,300},400,20,"1 == 20 pixels"};
	Axis ya {Axis::y,Point{300,500},400,20,"1 == 20 pixels"}; 

	xa.set_color(Color::red);
	ya.set_color(Color::red);

	win.attach(xa);
	win.attach(ya);

	Text ts {Point{100,410},"x/2"};

	Function f1 {one,r_min,r_max,orig,n_points,x_scale,y_scale};
	Function f2 {slope,r_min,r_max,orig,n_points,x_scale,y_scale};
	Function f3 {square,r_min,r_max,orig,n_points,x_scale,y_scale};
	Function f4 {sloping_cos,r_min,r_max,orig,n_points,x_scale,y_scale};
	Function f5 {[](double x) { return cos(x); },
            r_min, r_max, orig, n_points, x_scale, y_scale};
	f5.set_color(Color::blue);


	Person person{"Goofy",63};
	cout << person;

	cout << "Enter a name and an age!" << endl;
	Person readPerson{"",0};
	cin >> readPerson;
	cout << readPerson << endl;

	cout << "Enter some names and ages. Stop the loop by naming the next person 'end'." << endl;
	vector<Person> people;
	Person intoVector{"",0};
	while(intoVector.name() != "end"){
		cin >> intoVector;
		people.push_back(intoVector);
	}

	people.pop_back();

	cout << "Content of vector: " << endl;
	for(int i = 0; i < people.size();i++){
		cout << i << ": " << " " << people[i];
	}


	win.attach(ts);
	win.attach(f1);
	win.attach(f2);
	win.attach(f3);
	win.attach(f4);
	win.attach(f5);
	win.wait_for_button();




}