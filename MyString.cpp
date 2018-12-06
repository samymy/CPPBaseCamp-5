#include "MyString.h"

#include <cstring>
#include <utility>

MyString::MyString(const char* str) {

	if (!str)
		str = "";

	size = std::strlen(str);
	buff = new char[size + 1];
	std::strcpy(buff, str);
}

MyString::MyString(const MyString& copy) {

	*this = copy;
}

MyString::~MyString() {

	delete[] buff;
}

MyString&   MyString::operator=(const MyString& rhs) {

	if (this != &rhs) {

		delete[] buff;
		size = rhs.size;
		buff = new char[size + 1];
		std::strcpy(buff, rhs.buff);
	}

	return *this;
}

MyString&   MyString::operator+=(const MyString& rhs) {

	*this = *this + rhs;

	return *this;
}

MyString    operator+(const MyString& lhs, const MyString& rhs) {

	char buff[lhs.size + rhs.size + 1];

	std::strcpy(buff, lhs.c_str());
	std::strcat(buff, rhs.c_str());

	return { buff };
}

std::ostream&    operator<<(std::ostream& out, const MyString& obj) {

	out << obj.buff;

	return out;
}

std::istream&    operator>>(std::istream& in, MyString& obj) {

	delete[] obj.buff;

	in >> obj.buff;
	obj.size = std::strlen(obj.buff);

	return in;
}

bool    operator==(const MyString& lhs, const MyString& rhs) {

	return lhs.compare(rhs) == 0;
}

bool    operator!=(const MyString& lhs, const MyString& rhs) {

	return lhs.compare(rhs) != 0;
}

const char* MyString::c_str() const {

	return buff;
}

MyString&   MyString::append(const MyString& obj) {

	return *this += obj;
}

int MyString::compare(const MyString& obj) const {

	size_t  i = 0;
	size_t  j = 0;

	while (buff[i] && obj.buff[j] && buff[i] == obj.buff[j]) {
		++i;
		++j;
	}

	return buff[i] - obj.buff[j];
}

size_t      MyString::length() const {

	return size;
}

void        MyString::resize(size_t count) {

	if (count != size) {

		char*   buff_ptr = buff;
		buff = new char[count + 1];

		if (count > size) {
			std::strcpy(buff, buff_ptr);
			std::memset(buff + size, '\0', count - size + 1);
		}
		else {
			std::strncpy(buff, buff_ptr, count);
			buff[count] = '\0';
		}

		size = count;
		delete[] buff_ptr;
	}
}

void    MyString::clear() {

	std::memset(buff, '\0', size);
	size = 0;
}

void    MyString::swap(MyString& obj) {

	buff = std::exchange(obj.buff, buff);
	size = std::exchange(obj.size, size);
}

size_t MyString::substr(const MyString& obj) const {

	for (size_t idx = 0; idx < size; ++idx)
		if (std::strncmp(buff + idx, obj.c_str(), std::strlen(obj.c_str())) == 0)
			return idx;

	return std::string::npos;
}

MyString&   MyString::insert(size_t pos, char ch) {

	char*   buff_ptr = buff;

	buff = new char[size + 2];

	std::strncpy(buff, buff_ptr, pos);
	std::strcpy(buff + pos + 1, buff_ptr + pos);
	buff[pos] = ch;

	delete[] buff_ptr;

	return *this;
}

MyString&   MyString::insert(size_t pos, const char* str) {

	char*   buff_ptr = buff;
	size_t  str_size = std::strlen(str);

	buff = new char[size + str_size + 1];

	std::strncpy(buff, buff_ptr, pos);
	std::strcpy(buff + pos + str_size, buff_ptr + pos);
	std::strncpy(buff + pos, str, str_size);

	delete[] buff_ptr;

	return *this;
}
