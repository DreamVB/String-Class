#include <iostream>
#include "BString.h"
using namespace std;

int main(){
	int idx = -1;
	char arr[80] = { '\0' };

	BStringClass test("There are two needles in this haystack with needles");
	BStringClass s2("needle");
	BStringClass s3("hi");
	BStringClass s4;
	bool n = false;

	s4 = s3 + " World " + s3;
	
	//Print out string
	std::cout << test.CString() << endl;
	//Print out length
	std::cout << "Length: " << test.length() << endl;
	//Find string index
	idx = test.find(s2);
	if (idx != 0){
		std::cout << "First needle was found at index " << idx << endl;
	}
	idx = test.find(s2, idx + 6);
	if (idx != 0){
		std::cout << "Second needle was found at index " << idx << endl;
	}
	//Extract a string into an array
	test.copy(arr, 30, 8);
	std::cout << "arr array contains: " << arr << endl;
	//See the class for more functions
	std::cout << test.compare("haystack") << endl; // Returns -1 not found
	std::cout << test.compare(14, 6, "needle") << endl; // Returns 0 match found
	std::cout << s2.compare(s3) << endl; // Returns 0 two string objs match

	std::cout << "substr(0,5): " << test.substr(0, 5).CString() << endl;


	s4.reverse();
	std::cout << s4.CString() << endl;
	s4.reverse();
	std::cout << s4.CString() << endl;

	n = test.starts_with("There");
	std::cout << "string test starts with 'There' = " << n << endl;

	n = test.ends_with("needles");
	std::cout << "string test ends with 'needles' = " << n << endl;

	test.clear();
	s2.clear();
	s3.clear();
	s4.clear();

	system("pause");
	return 0;
}