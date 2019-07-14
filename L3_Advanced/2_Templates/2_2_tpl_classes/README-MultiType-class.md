# Specifying multiple type parameters
======================================

If we want to pass multiple types to a template we can do the following

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
So the class MultiTypePoint takes three different types as parameters to it's constructor, we can also pass typed parameters to templates like so.

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
and we can create an instance of MultiTypedPoint like so

MultiTypedPoint<float,5,5> mtypedp(5.55555555555);
