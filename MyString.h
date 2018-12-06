#ifndef PROCESS_MYSTRING_H
#define PROCESS_MYSTRING_H

#include <iostream>

class MyString {

	char*   buff { nullptr };
	size_t  size { 0 };

public:
	MyString(const char* = "");
	MyString(const MyString&);
	~MyString();

	MyString&   operator=(const MyString&);
	MyString&   operator+=(const MyString&);

	friend MyString         operator+(const MyString&, const MyString&);
	friend std::ostream&    operator<<(std::ostream&, const MyString&);
	friend std::istream&    operator>>(std::istream&, MyString&);

	friend bool             operator==(const MyString&, const MyString&);
	friend bool             operator!=(const MyString&, const MyString&);

	const char* c_str() const;

	MyString&   append(const MyString&);
	int         compare(const MyString&) const;
	size_t      length() const;
	void        resize(size_t);
	void        clear();
	void        swap(MyString&);
	size_t      substr(const MyString&) const;
	MyString&   insert(size_t, char);
	MyString&   insert(size_t, const char*);
};

#endif //PROCESS_MYSTRING_H
