# DEFINING TEMPLATE ADAPTERS
============================

## ADAPTER DESIGN PATTERN
Template adapters allow the implementation of the adapter design pattern.
This design pattern is used when you want to implement an interface to reuse existing code that does not provide the required interface.
There are many examples of the adapter pattern in the STL such as the reverse_iterator but we will look at a simple example.
Suppose we have four animal classes, that is a class that prints out the animal noise it is named after for example.



  class Cat {
  public:
  	void makeCatMeow() {
  		cout << catnoise.c_str() << endl;
  	}
  private:
  	string catnoise = "meow meow";
  };  
  Now these animal classes are independent from one another i.e. they have no relationship to each other. We could define an interface class with an execute function to print out the animal sounds like so.

  class AnimalInterface {
  public:
  	//Destructor
  	virtual ~AnimalInterface() {}
  	//Pure virtual execute function has to be implemented by derived classes.
  	virtual void execute() = 0;
  };
  and we could derive this interface class with a template class and implement the execute pure virtual function like so.

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



This allows us to use the AnimalAdapter class with multiple different animal class types and print out their animal sounds.
It works but passing an instance of the animal class and it's function to print out it's animal sound on construction of an AnimalAdapter object.
It uses a private pointer to the animal object and a function pointer to the animal sound print function.

In the STL we have the stack container which adapts the deque container along with the queue,
which also adapts the deque container, while priority_queue adapts the vector container.
