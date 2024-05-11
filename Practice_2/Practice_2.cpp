#include <iostream>
#include <vector>
#include <string>
#include <fstream>


void PointerPrint(int &var) {
	std::cout << "Value of variable: " << var << "\n";
	std::cout << "Location of variable: " << &var << "\n";
	std::cout << "Size of variable in bytes: " << sizeof(var) << "\n";
}


template <typename T>
class DynamicArray {

	size_t m_size;
	T* m_arr;

public:
	DynamicArray(size_t size) 
		: m_size(size)
		, m_arr(new T[size] {})
	{
		std::cout << "Array Constructor \n";
	}

	~DynamicArray()
	{
		delete[] m_arr;
	std::cout << "Array Destructor \n";
	}

	T get(size_t index) const {
		return m_arr[index];
	}

	void set(size_t index, T value) {
		m_arr[index] = value;
	}

	void print() const {
		for (size_t i{0}; i < m_size; i++) {
			std::cout << m_arr[i] << " ";
		}
		std::cout << "\n";
	}

	//Operator Overloading

	T & operator [] (size_t index){
		return m_arr[index];
	}

	const T & operator [] (size_t index) const {
		return m_arr[index];
	}

};

int main(int argc, char * argv[]) {


	//DynamicArray<int> myArray(10);
	DynamicArray<float> myArray(10);
	//DynamicArray<std::string> myArray(10);
	myArray.set(4, 100.10);
	//myArray.set(0, "Hello There");

	myArray[8] = 3.14;

	std::cout << myArray[8] << "\n";

	myArray.print();



	/*
	int a{ 10 };
	int b{ 25 };
	int* pa{ &a };
	int* pb{ &b };

	//*pa = 17;

	*(&a) = 105;

	PointerPrint(a);
	PointerPrint(b);

	// PointerPrint(pa) won't work;


	*/
	/*
	int arr[10] {};
	int* harr = new int[10] {};

	for (size_t i{ 0 }; i < 10; i++) {
		PointerPrint(arr[i]);
	}

	for (size_t i{ 0 }; i < 10; i++) {
		PointerPrint(harr[i]);
	}

	delete harr;
	*/

	/*
	int a { 10 };
	int b { 25 };

	PointerPrint(a);
	PointerPrint(b);
	*/
	return 0;
}