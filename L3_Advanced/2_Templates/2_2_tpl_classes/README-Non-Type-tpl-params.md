# Defining non-type template parameters
========================================

Template parameters that we have seen so far have always been types i.e. (typename myType, class myClass) etc.
We can also pass a constant expression which is evaluated at compile time,
or the address of a function or object or the address of a static class member.
Non type integral arguments are matched to the template argument as long as the sign and value match the template type.
The values of non-type template arguments form part of the templates type.
So a non-type integral argument looks like the following.

\#include <iostream>

using namespace std;

//Template class demo with user defined object and double and float pointers.
template<class myclass, int myint, double* mydouble,float* myfloat>
class nonType {

public:
	nonType(myclass mc) : myc(mc), t(myint), d(*mydouble), f(*myfloat) {
		cout << "nonType constructor called. \n" << endl;
	}

	void printnonType() {
		cout << "myclass.otpint is " << myc.otpint << " t is " << t << " d is " << d << " f is " << f << endl;
	}

private:
	myclass myc;
	int t;
	double d;
	float f;
};


//Template class demo with user defined object and int parameter with default value.
template<class myclass, int myint = 0>
class nonTypedefault {

public:
	nonTypedefault(myclass mc) : myc(mc),t(myint) {
		cout << "nonTypedefault constructor called. \n" << endl;
	}

	void printnonType() {
		cout << "myclass.otpint is " << myc.otpint << " t is " << t << endl;
	}

private:
	myclass myc;
	int t;
};


class objectToPass {

public:
	int otpint;
};


double md = 8.8;
float mf = 7.777777f;
int main() {

	objectToPass otp;
	otp.otpint = 5;

	nonTypedefault<objectToPass> defaultParams(otp);
	nonType<objectToPass,9,&md,&mf> explicitParams(otp);

	cout << "nonType with default params is ";
	defaultParams.printnonType();
	cout << endl;

	cout << "nonType with explicit params is ";
	explicitParams.printnonType();
	cout << endl;


	return 0;
}


In the above example we create two template classes to show how to pass user defined object types, integers, doubles and floats. It is important to note that doubles and floats can only be passed as pointers and not by value as defined by the c++ standard. We also demonstrate parameters with default values in the second class. The class nonTypedefault is the class with default template parameters and the class nonType has pointers as template parameters for doubles and floats. The main function creates an instance of each class passing parameter values to the constructor for the nonType object and then it prints out these values by calling the public function printnonType. It also creates an instance of the objectToPass class which is used to show how to pass user defined objects.
