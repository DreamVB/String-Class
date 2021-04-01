#include <iostream>
#include "BString.h"
using namespace std;

int main(){
	int idx = -1;
	char arr[80] = { '\0' };

	BStringClass test("This is a test string!");
	BStringClass s2("hi ");
	BStringClass s3("hi");
	BStringClass s4;

	s4 = s2 + test;

	//Print out string
	std::cout << test.CString() << endl;
	//Print out length
	std::cout << test.length() << endl;
	//Find string index
	idx = test.find("test");
	if (idx==-1){
		std::cout << "The string 'test; was not found" << endl;
	}
	else{
		std::cout << "The string 'test' was found at index : " << idx << endl;
	}
	//Extract a string into an array
	test.copy(arr, 1, 3);
	std::cout << "arr array contains " << arr << endl;
	//show all the chars in the string
	std::cout << "Extracted chars: " << endl;
	for (int y = 0; y < test.length(); y++){
		std::cout << test.at(y) << ".";
	}
	std:cout << endl;
	//See the class for more functions
	std::cout << test.compare("This") << endl; // Returns 1 not found
	std::cout << test.compare(0, 4, "This") << endl; // Returns 0 match found
	std::cout << s2.compare(s3) << endl; // Returns 0 two string objs match

	s4.reverse();
	std::cout << s4.CString() << endl;
	s4.reverse();
	std::cout << s4.CString() << endl;

	test.clear();
	s2.clear();
	s3.clear();
	s4.clear();

	system("pause");
	return 0;
}