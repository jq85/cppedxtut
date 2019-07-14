# Implementing generic algorithms using template functions

What does the term generic mean in the context of template functions.? Well we stated we want to write code once that can be reused for many types without changing the code. So we want to create an algorithm that we can apply to many different types, if we look at the algorithms in the c++ STL we will see that they all use a random access iterator to iterate over container elements. Each container implements its own random access iterator which is able to iterate through and access its own elements. We should always try to use the STL algorithms if we can as these have complexity specifications and the code is highly optimised. So we have some guidelines to implement our own generic template function and for an example let's implement the bubble sort algorithm. Bubble sort has O(n2) complexity, but what does this mean? A single for loop takes linear time or O(n) so two nested for loops takes O(n2). So we know bubble sort will require two for loops, so how does the algorithm work? Well we need to iterate over every element in the container and if the last element has to move to the front then it has to move n-1 positions so the inner loop will be from 1 to n-1 for n elements. Then we check if two elements next to each other have to swap positions using the operator <.

from first to last elements in container
	from j = 1 to last-1
		if (container[j] > container[j+1])
			swap(container[j] , container[j+1])
As you can see there is not much to bubble sort which is why I choose it for the example. It has very bad performance unless the container is almost already sorted then it has O(n) complexity but this course is about the c++ language and not algorithms.

so in code, this would look like

std::vector<int> myvec;
from(std::vector<int>::iterator i = myvec.begin();i != myvec.end();i++) {
	for(std::vector<int>::iterator j = myvec.begin();j != i;j++) {
		if(*i < *j) {
			std::swap(*i,*j);
		}
	}
}
However we want the code to work for any container and not just vectors which is where templates are useful. If you are developing your own generic algorithms it is easier to start with a non-generic version that works correctly and then make that generic. So we will template the container like so

template<typename TContainer>
void bubbleSort(TContainer begin,TContainer end) {
	from(TContainer i = begin;i != end;i++) {
		for(TContainer j = begin;j != i;j++) {
			if(*i < *j) {
				std::swap(*i,*j);
			}
		}
	}
}
Now the container type is generic and hence the algorithm is generic so long as the type in the container implements the operator <.

The following code is the full program for the demonstration.

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <iterator>

using namespace std;
const double pi = 3.1415926535897;

class Circle {

public:
	Circle(int rad) : radius(rad) {
		area = pi*radius*radius;
	}

	const bool operator < (const Circle &r) const {
		return (area < r.area);
	}

	friend std::ostream& operator<< (std::ostream& stream, const Circle& cir) {
		stream << cir.area << "\n";
		return stream;
	}

private:
	int radius;
	double area;

};

template<typename TContainer>

void bubbleSort(TContainer begin, TContainer end)
{
	TContainer i, j;
		for ( i = begin; i != end; i++) {
			//Loop around all elements in container.
			for ( j = begin; j != i; j++) {
				//Loop around container comparing current element to all others and bubble up.
				if (*i < *j) {
					//Swap elements.
					std::swap(*i, *j);
				}
			}
		}
}



int main() {

	//Vector container
	vector<int> aVec;

	//List container.
	list<double> myList;

	//Vector of user defined objects
	vector<Circle> circleVec;

	aVec.push_back(5);
	aVec.push_back(4);
	aVec.push_back(3);
	aVec.push_back(2);
	aVec.push_back(1);

	myList.push_back(5.954);
	myList.push_back(4.873);
	myList.push_back(3.135);
	myList.push_back(2.851);
	myList.push_back(1.9999);

	circleVec.push_back(Circle(5));
	circleVec.push_back(Circle(4));
	circleVec.push_back(Circle(3));
	circleVec.push_back(Circle(2));
	circleVec.push_back(Circle(1));

	//Display and sort vector

	cout << "Vector before sorting " << endl;
	for (vector<int>::iterator it = aVec.begin(); it != aVec.end(); it++) {
		cout << *it;
	}
	cout << endl << endl;


	bubbleSort(aVec.begin(), aVec.end());

	//print sorted vector
	cout << "Sorted vector is " << endl;
	for (vector<int>::iterator it = aVec.begin(); it != aVec.end();it++) {
		cout << *it;
	}
	cout << endl << endl;

	//Display and sort list
	cout << "List before sorting " << endl;
	for (list<double>::iterator it = myList.begin(); it != myList.end(); it++) {
		cout << *it << " ";
	}
	cout << endl << endl;


	bubbleSort(myList.begin(), myList.end());

	//print sorted list
	cout << "Sorted list is " << endl;
	for (list<double>::iterator it = myList.begin(); it != myList.end(); it++) {
		cout << *it << " ";
	}
	cout << endl << endl;

	//Display and sort circle vector

	cout << "Circle vector before sorting " << endl;
	for (vector<Circle>::iterator it = circleVec.begin(); it != circleVec.end(); it++) {
		cout << *it;
	}
	cout << endl << endl;


	bubbleSort(circleVec.begin(), circleVec.end());

	//print sorted vector
		cout << "Sorted circle vector is " << endl;
	for (vector<Circle>::iterator it = circleVec.begin(); it != circleVec.end(); it++) {
		cout << *it;
	}
	cout << endl;


	return 0;
}
The program works by creating three different type containers and printing out their values before and after calling bubbleSort. So the bubbleSort function is tested with int's, doubles and a user defined Circle class hence the function is type independent. Since it works with any user defined type so long as the operator< is overridden, then the function is generic. Hopefully you now have some idea how to implement generic template algorithms, the best approach is to create a working version of the algorithm and then make it generic as we did above.
