# Overview of Template Classes

It is possible to create generic classes like we did with template functions. Why would we want to do this.? Well we could create a class like Point which has private members x and y for the x and y coordinates. Now we might want several different types for these members like int's, doubles, floats etc. depending on how much precision we want a point to have or maybe you want to define your own container class to hold the point objects. So we can see that having type independent classes would be useful, now we can use both the keyword typename and class to declare a template class however I prefer to use class. To declare a template class all we need is

template<class point>
class Point{
	public:
		Point() {}
		Point( point x,point y): px(x),py(y)  {}

	private:
		point px;
		point py;

};
We can inherit from templates as well like so

template<class derPoint>
class Point3D : Point<derPoint> {
	public:
		Point3D(derPoint x,derPoint y,derPoint z) : px(x), py(y), pz(z) {}

	private:
		derPoint px;
		derPoint py;
		derPoint pz;

};
Here is a demo of the above classes

#include <iostream>

using namespace std;

template<class point>
class Point {
	public:

		Point() {}
		Point(point x, point y) : px(x), py(y) {
			cout << "Point object constructor." << endl;
		}

		void printPoint() {
			cout << " X " << px << " Y " << py << endl;
		}

	private:
		point px;
		point py;

};

template<class derPoint>
class Point3D : Point<derPoint> {
	public:
		Point3D(derPoint x, derPoint y, derPoint z) : px(x), py(y), pz(z) {
			cout << "Point3D object constructor." << endl;
		}

		void printPoint() {
			cout << " X " << px << " Y " << py << " Z " << pz << endl;
		}

	private:
		derPoint px;
		derPoint py;
		derPoint pz;

};

int main() {

	Point<int> basePoint(5,5);
	Point3D<double> derivedPoint(99.9,99.9,99.9);

	cout << "basePoint is ";
	basePoint.printPoint();

	cout << "derivedPoint is ";
	derivedPoint.printPoint();

	return 0;

}
In the above program we have a base class point which represents a two dimensional point and we extend that with Point3D which is a three dimensional point. In the main function we create an instance of each class and print out their private member coordinates x, y and z.
