#include <iostream>

#include "MyString.h"

int main() {

	std::cout << "~~~~~Constructors~~~~~\n";

	MyString    obj("Hello");
	std::cout << "Object: " << obj << std::endl;

	MyString    copy(obj);
	std::cout << "Copy: " << copy << std::endl;

	std::cout << "\n~~~~~Operators~~~~~\n";

	obj += "-message";
	std::cout << obj << std::endl;
	std::cout << obj + "!!!" << std::endl;

	std::cout << std::boolalpha << (obj == "Hello-message") << std::endl;
	std::cout << std::boolalpha << (obj != "Hello-message") << std::endl;

	std::cout << "\n~~~~~Functions~~~~~\n";

	std::cout << "Append\n";
	obj.append("!!!");
	std::cout << obj;

	std::cout << "\n\nCompare\n";
	std::cout << obj.compare("Hello-message") << std::endl;

	std::cout << "\nSwap\n";
	MyString    a("aaa");
	MyString    b("bbb");

	std::cout << a << "<=>" << b << std::endl;
	a.swap(b);
	std::cout << a << "<=>" << b << std::endl;

	std::cout << "\nSubstr\n";
	MyString    str("aaabbbccc");
	std::cout << str.substr("bbb") << std::endl;

	std::cout << "\nInsert\n";
	str.insert(str.substr("bbb"), "~~~");
	std::cout << str << std::endl;

	std::cout << "\nResize\n";
	obj.resize(5);
	std::cout << obj << std::endl;

	std::cout << "\nClear\n";
	obj.clear();
	std::cout << obj << std::endl;

	return 0;
}