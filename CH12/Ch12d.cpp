
//g++ Ch12d.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp Lines_window.cpp -o drill12 `fltk-config --ldflags --use-images` -std=c++11


#include "Simple_window.h"
#include "Graph.h"
#include "GUI.h"
#include "Lines_window.h"

int main(){

	using namespace Graph_lib;

	Point tl {100,100};

	Simple_window win {tl,600,400,"My window"};	

	Axis xa {Axis::x,Point{20,300},280,10,"x axis"};  //make an Axis
	Axis ya {Axis::y,Point{20,300},280,10,"y axis"};  // same here
	ya.set_color(Color::green);						  //axis color
	ya.label.set_color(Color::dark_blue);			  //axis label color

	
	Function sine {sin,0,100,Point{20,150},500,50,50};
	sine.set_color(Color::blue);


	Polygon poly;
	poly.add(Point{300,150});
	poly.add(Point{350,100});
	poly.add(Point{400,200});
	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);
	poly.set_style(Line_style(Line_style::dash,2));


	Rectangle r {Point{200,200},200,50};
	r.set_fill_color(Color::yellow);


	Closed_polyline poly_rect;
	poly_rect.add(Point{100,70});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,130});
	poly_rect.add(Point{100,100});
	poly_rect.add(Point{50,75});
	poly_rect.set_style(Line_style(Line_style::dash,2));
	poly_rect.set_fill_color(Color::blue);

	Text t{Point{150,150},"Hello, graphical world!"};
	t.set_font(Font::times_bold);
	t.set_font_size(20);


	//Image ii{Point(100,50),"CPlus.jpg"};
	//ii.move(100,200);


	Circle c {Point{100,200},50};

	Ellipse e {Point{100,200},75,25};
	e.set_color(Color::dark_red);

	Mark m {Point{100,210},'x'};

	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
	<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point{100,20},oss.str()};


	win.attach(xa);
	win.attach(ya);
	win.attach(sine);
	win.attach(poly);
	win.attach(r);
	win.attach(poly_rect);
	win.attach(t);
	//win.attach(ii);
	win.attach(c);
	win.attach(e);
	win.attach(m);
	win.attach(sizes);


	win.wait_for_button();
}