#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

template<typename T>
void print(string text, vector<T> & vec) {
	cout << text << " ";
	for (T t : vec)
		cout << t << " ";
	cout << endl;
}

bool compareAscending(int x, int y) {
	return x < y;
}

bool compareDescending(int x, int y) {
	return x > y;
}

/*
	Iterates the array of integers and invokes the function, implemented as template to be able to invoke FP as function AND capture the variables
*/
template<typename Functor>
void iterate(int arr[], int n, Functor fp) {
	for (int i = 0; i < n; ++i)
		fp(arr[i]);
}

/*
Non capturing version
*/
void iterate2(int arr[], int n, void (*fp)(int)) {
	for (int i = 0; i < n; ++i)
		fp(arr[i]);
}

/*
Bona fide capturing version, like in real functional programming (not languages)
*/
double iterateBonaFide(int arr[], int n, double startValue, double(*fp)(double, int)) {
	double accumulator = startValue;
	for (int i = 0; i < n; ++i)
		accumulator = fp(accumulator, arr[i]);
	return accumulator;
}

int main() {

	/*
		Showing the lambdas first
	*/
	vector<int> vector_1 = { 25,1,23,9,0,-5,-4,-999 };
	vector<string> vector_2 = { "mysterion", "cartman", "kyle", "impossibru"};

	print("Original int array:", vector_1);
	print("Original string array:", vector_2);

	cout << endl;
	
	/*
	You can use the function as the paramter, example sort(begin, end, COMPARATOR <- this is pointer to the function)
	*/

	sort(vector_1.begin(), vector_1.end(), compareAscending);
	print("Sorted ascending:", vector_1);

	sort(vector_1.begin(), vector_1.end(), compareDescending);
	print("Sorted descending:", vector_1);

	cout << endl;

	/*
	We can assign the function to the special type: function pointer. The whole trick is to establish the type:
	*/
	bool(*fp)(int, int) = compareAscending;
	sort(vector_1.begin(), vector_1.end(), fp); //use it as follows
	print("Sorted ascending:", vector_1);

	/*
	We can do weird sh*t like this:
	*/
	for (int i = 0; i < 10; ++i) {
		fp = rand() % 2 == 0 ? compareAscending : compareDescending;
		sort(vector_1.begin(), vector_1.end(), fp); //use it as follows
		print("Sort technique chosen at runtime:", vector_1);
	}


	/*
	Now the lambdas - which are anonymous function (pointers)
	Showing the lambdas
	*/
	/*sort(vector_1.begin(), vector_1.end(), [](int x, int y) {return x > y; });
	print("Sorted descending:", vector_1);

	sort(vector_1.begin(), vector_1.end(), [](int x, int y) {return x < y; });
	print("Sorted ascending:", vector_1);

	cout << endl;*/

	cout << "Now lambdas:" << endl;

	sort(vector_2.begin(), vector_2.end(), [&](string x, string y) {return x > y; });
	print("Sorted descending:", vector_2);

	sort(vector_2.begin(), vector_2.end(), [&](string x, string y) {return x < y; });
	print("Sorted ascending:", vector_2);

	cout << endl;

	/*
	Lambdas can be assigned.
	The whole trouble is to find the signature. 
	It is as follows [RETURN TYPE] (*[VARIABLE NAME])(TYPE OF PARAMETER, ..., TYPE OF PARAMETER)
	This is analogous to the signature of function:
	[RETURN TYPE] [FUNCTION NAME(TYPE OF PARAMETER [VARIABLE NAME], ..., TYPE OF PARAMETER [VARIABLE NAME])
	*/
	bool (*lp)(string &, string &) = [](string & x, string & y) {return x > y; };
	sort(vector_2.begin(), vector_2.end(), lp);
	print("Sorted using assigned lambda:", vector_2);

	cout << endl;

	/*
	Type can be inferred
	*/
	auto lam = [](string & x, string & y) {return x < y; };
	sort(vector_2.begin(), vector_2.end(), lam);
	print("Sorted using auto lambda:", vector_2);

	cout << endl;

	/*
	Advanced mode ON
	We did: fp = rand() % 2 == 0 ? compareAscending : compareDescending;
	Can we do something similar with lambdas?
	*/
	//DISAPPOINT
	//bool(*slp)(string &, string &) = (rand() % 2 == 0) ? ([](string & x, string & y) {return x > y; }) : ([](string & x, string & y) {return x < y; }); 
	//EVEN BIGGER DISAPPOINT
	//auto slp = (rand() % 2 == 0) ? ([](string & x, string & y) {return x > y; }) : ([](string & x, string & y) {return x < y; }); 
	
	/*
		Why is that? Because, the lambdas are compiled as a dedicated class.
		This means that 'auto' can't infer the type: 
		
		[](string & x, string & y) { return x > y; } -> this can be seen as class name $_F1
		[](string & x, string & y) { return x < y; } -> this can be seen as class name $_F2
		auto fp = conditon ? lambda : lambda;  
		In terms of types is:
		($F_1 or $F_2) fp = BOOLEAN ? $_F1 : $_F2;

		Interestingly, it's not the AUTO which fails here: in fact ?: operator is responsible.
	*/
	
	/*
		Even if you get rid of ?: you formally can't do the following:
	*/
	/*auto slp = [](string & x, string & y) {return x > y; }; <- slp is type of $_F1
	if (rand() % 2 == 0) {
		slp = [](string & x, string & y) {return x < y; }; <- here the compiler will fail, because $_F1 <> $_F2
	}*/

	/*
	The only option that will work is:
	*/
	bool(*slp)(string &, string &);
	
	for (int i = 0; i < 10; ++i) {
		if (rand() % 2 == 0) {
			slp = [](string & x, string & y) {return x < y; };
		}
		else {
			slp = [](string & x, string & y) {return x > y; };
		}
		sort(vector_2.begin(), vector_2.end(), slp);
		print("Works, lambda at runtime!:", vector_2);
	}

	cout << endl;

	/*
	Expert mode ON
	Ok. But what is better: function pointers or lambdas.
	Answer: lambdas CAN access the fields in enclosing scope.
	Lambdas <> function pointers, due to the enclosing scope (google C++ capture list lambda).
	Basically, this ->[]<- fu**s our day up.
	
	What is the concept:
	assume lambda: 
		[](int x){return x;}; <- it doesn't require knowledge about 'outer variables'
	Now assume:
		int myVariable = 5;
		[](int x){return x + myVariable;}; <- it DOES require knowledge about outer variables
		The info can be entered here []
		Options are:
		[=] <- pass the variables from outer scope BY VALUE (operate on copy)
		[&] <- pass the variables from outer scope BY REFERENCE (operate on them)
		Specify manually i.e:
		[=myVariable, &myVariable2] <- pass myVariable by value, myVariable2 by reference
	*/

	int arr[] = { 215,1,0,3 };
	int n = sizeof(arr) / sizeof(arr[0]);

	/*
		Using the iterate to print the elements;
		We do NOT utilize the encolsing scope
	*/
	cout << "Print with capturing version" << endl;
	iterate(arr, n, [](int x) {cout << x << " "; });
	cout << endl;

	cout << "Print with noncapturing version" << endl;
	iterate2(arr, n, [](int x) {cout << x << " "; });
	cout << endl;

	/*
	Now count the numbers.
	Noe we utilze;
	*/
	int counter = 0;
	iterate(arr, n, [&](int x) {counter++; });
	cout << "Number of elements: " << counter << endl;


	/*
	iterate(arr, n, [=](int x) {counter++; }); <- won't compile because COUNTER is passed by value. 
	It CAN'T incremented, as value is lost - think about memory layout
	cout << "Number of elements: " << counter << endl;
	*/

	double sum = 0, holder;
	iterate(arr, n, [&](int x) {sum += x; });
	cout << "Sum of elements: " << sum << endl;
	cout << "Avg of elements: " << sum/counter << endl;

	holder = arr[0];
	iterate(arr, n, [&](int x) {holder = holder > x ? holder : x ; });
	cout << "Max of elements: " << holder << endl;

	holder = arr[0];
	iterate(arr, n, [&](int x) {holder = holder < x ? holder : x; });
	cout << "Min of elements: " << holder << endl;

	/*
	In functional programming the capturing groups can be considered haxx0r (bad design).
	So the captures are implemented as the parameter passed alongside of the lambda.
	The function which uses the function pointer returns the modified value of the parameter;
	*/
	cout << "Bona fide version:" << endl;
	cout << "SUM:" << iterateBonaFide(arr, n, 0.0, [](double acc, int val) {return acc + val; }) << endl; // sum
	cout << "COUNT:" << iterateBonaFide(arr, n, 0.0, [](double acc, int val) {return acc + 1; }) << endl; // count
	cout << "MAX:" << iterateBonaFide(arr, n, arr[0], [](double acc, int val) {return acc > val ? acc : val; }) << endl; // max
	cout << "MIN:" << iterateBonaFide(arr, n, arr[0], [](double acc, int val) {return acc < val ? acc: val; }) << endl; // min

	return 0;
}