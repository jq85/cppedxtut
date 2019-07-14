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

/*
* we can have one generic template type
* here and then we have two integer type specified.
*/
template<class pointx, class pointy, class pointz>
class MultiTypePoint {
public:
  MultiTypePoint(pointx x, pointy y, pointz z) : px(x), py(y), pz(z) {
    cout << "MultiTypePoint object constructor." << endl;
  }

  void printPoint() {
    cout << " X " << px << " Y " << py << " Z " << pz << endl;
  }

private:
  pointx px;
  pointy py;
  pointz pz;
};

template<class pointx, int pointy, int pointz>
class MultiTypedPoint {
public:
  MultiTypedPoint(pointx x) : px(x), py(pointy), pz(pointz) {
    cout << "MultiTypedPoint object constructor." << endl;
  }

  void printPoint() {
    cout << " X " << px << " Y " << py << " Z " << pz << endl;
  }

private:
  pointx px;
  int py;
  int pz;
};


int main() {
  Point<int> basePoint(5, 5);
  Point3D<double> derivedPoint(99.9, 99.9, 99.9);
  MultiTypePoint<int, double, float> mtp(5, 5.5, 5.55555555);
  MultiTypedPoint<float, 5, 5> mtypedp(5.555555555);

  cout << "basePoint is ";
  basePoint.printPoint();

  cout << "derivedPoint is ";
  derivedPoint.printPoint();

  cout << "MultiTypePoint is ";
  mtp.printPoint();

  cout << "MultiTypedPoint is ";
  mtypedp.printPoint();

  return 0;
}
