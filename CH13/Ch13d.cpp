#include "Graph.h"
#include "Simple_window.h"
#include "GUI.h"
#include "Lines_window.h"
#include "std_lib_facilities.h"

//g++ Ch13d.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill13 `fltk-config --ldflags --use-images` -std=c++11

int main(){

	using namespace Graph_lib;

	Point tl {100,100};

	Simple_window win {tl,800,1000,"Simple_window"};  

	int x_size = win.x_max();
	int y_size = win.y_max();
	int x_grid = 100;
	int y_grid = 100;

	Lines grid;
	for(int x = x_grid; x < x_size ; x+=x_grid)
		grid.add(Point{x,0},Point{x,y_size});
	for(int y = y_grid; y < y_size ; y+=y_grid)	
		grid.add(Point{0,y},Point{x_size,y});


	Vector_ref<Rectangle> rect;
	for(int i = 0; i< 800;i+=100){
		rect.push_back(new Rectangle{Point{i,i},100,100});
	}
	for(int i = 0; i<rect.size();++i){
		rect[i].set_fill_color(Color::red);
		win.attach(rect[i]);
	}


	Image img1{Point{300,100},"img.jpg"};
	Image img2{Point{100,400},"img.jpg"};
	Image img3{Point{600,300},"img.jpg"};
	Image simg{Point{0,0},"simg.jpg"};
	int y_Loc = 0;

	win.attach(grid);
	win.attach(img1);
	win.attach(img2);
	win.attach(img3);
	win.attach(simg);

	win.wait_for_button();
	for(int i= 1; i<9;++i){
		for(int j=1;j<8;++j){
			simg.move(100,0);
			win.wait_for_button();
		}
		y_Loc+=100;
		if(y_Loc==800)
			break;
		simg.move(-700,100);
		win.wait_for_button();
	}

}