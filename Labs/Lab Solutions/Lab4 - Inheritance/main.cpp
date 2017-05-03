//
// Object-Oriented Programming in C++
// Lab Exercise 04
//

#include <iostream>
#include <vector>
using namespace std;

struct Point {
	Point(int ix, int iy ) :
		x(ix), y(iy) {}
	int x;
	int y;
};

class Shape {
    public:
        Shape(Point p) : p_(p){}
        virtual void draw() = 0;
        virtual ~Shape(){ };

        Point p_;

};

// Implement Circle
class Circle : public Shape {
    public:
        Circle(Point p) : Shape(p) { }
        virtual void draw(){
            cout << "Drawing Circle at location (" << p_.x << "," << p_.y << ")" << endl;
        }
        virtual ~Circle(){ }
};

// Implement Rectangle
class Rectangle : public Shape {
    public:
        Rectangle(Point p) : Shape(p) { }
        virtual void draw(){
            cout << "Drawing Rectangle at location (" << p_.x << "," << p_.y << ")" << endl;
        }
        virtual ~Rectangle(){ }
};

// Implement drawAll( ... )
/* STL Container gerir sitt eigið afrit af gögnum við innsetningu
 * Ef týpan er base class týpa mun afritið því einungis vera base klasa hluti gagnana útaf týpunni
 * En ef týpan er base class pointer, munu gögnin sem eru afrituð vera pointerinn í heild,
 * s.s. sækja actual implementation týpunnar sem er skilgreind
 */
void drawAll(vector<Shape*> shape_vec)
{
    for(unsigned int i = 0; i < shape_vec.size(); i++)
    {
        shape_vec[i]->draw();
    }
}

int main()
{
	// Shape     s( Point(0,0) );
	Circle    c( Point(1,1) );
	Rectangle r( Point(3,2) );
	cout << '\n';
	// s.draw();
	c.draw();
	r.draw();

	// Shape     *ps = new Shape( Point(0,0) );
	Circle    *pc = new Circle( Point(1,1) );
	Rectangle *pr = new Rectangle( Point(3,2) );
	cout << '\n';
	// ps->draw();
	pc->draw();
	pr->draw();

	// Shape *psc = new Circle( Point(3,3 ) );
	cout << '\n';
	//psc->draw();

	vector<Shape*> shape_vec;

	// shape_vec.push_back(ps);
	shape_vec.push_back(pc);
	shape_vec.push_back(pr);
	// shape_vec.push_back(psc);

    cout << endl << "Drawing all:" << endl;
    drawAll(shape_vec);

    delete pr;
    delete pc;
    // delete ps;

	return 0;
}
