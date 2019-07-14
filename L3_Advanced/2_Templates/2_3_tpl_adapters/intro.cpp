#include <iostream>

using namespace std;


class AnimalInterface {
public:
	//Destructor
	virtual ~AnimalInterface() {}
	//Pure virtual execute function has to be implemented by derived classes.
	virtual void execute() = 0;
};


template <class T>
class AnimalAdapter : public AnimalInterface {
public:
	//Constructor
	AnimalAdapter(T *o, void(T:: *m)()) {
		animalObject = o;
		animalfunction = m;
	}
	//Deconstructor.
	~AnimalAdapter() {
		delete animalObject;
	}
	//Implement AnimalInterface pure virtual function.
	void execute() {
		(animalObject->*animalfunction)();
	}
private:
	//Members to hold object and function pointers
	T *animalObject;
	void(T:: *animalfunction)();
};


//Animal classes. All provide a function to pring out their sounds,
//Which is stored as a private member string.
class Cat {
public:
  void makeCatMeow() {
    cout << catnoise.c_str() << endl;
  }
private:
  string catnoise = "meow meow";
};


class Dog {
public:
  void makeDogBark() {
    cout << dognoise.c_str() << endl;
  }
private:
  string dognoise = "wof wof";
};


class Horse {
public:
  void makeHorseNay() {
    cout << horsenoise.c_str() << endl;
  }
private:
  string horsenoise = "nay nay";
};


class Frog {
public:
  void makeFrogCroak() {
    cout << frognoise.c_str() << endl;
  }
private:
  string frognoise = "croak croak";
};


int main() {
  //Cat
  AnimalAdapter<Cat> cata(new Cat(), &Cat::makeCatMeow);
  cata.execute();

  //Dog
  AnimalAdapter<Dog> doga(new Dog(), &Dog::makeDogBark);
  doga.execute();

  //Horse
  AnimalAdapter<Horse> horsea(new Horse(), &Horse::makeHorseNay);
  horsea.execute();

  //Frog
  AnimalAdapter<Frog> froga(new Frog(), &Frog::makeFrogCroak);
  froga.execute();

  return 0;
}
