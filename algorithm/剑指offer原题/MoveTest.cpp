#include<iostream>
#include<string>
#include<vector>
using namespace std;


class MyString {
private:
	char* _data;
	size_t   _len;
	void _init_data(const char *s) {
		_data = new char[_len + 1];
		memcpy(_data, s, _len);
		_data[_len] = '\0';
	
	}
public:
	MyString() {
		_data = NULL;
		_len = 0;
		std::cout << "consurt data" << this << endl;
	}

	MyString(const char* p) {
		_len = strlen(p);
		_init_data(p);
		std::cout << "consurt data" << this << endl;
	}

	MyString(const MyString& str) {
		_len = str._len;
		_init_data(str._data);
		std::cout << "Copy Constructor is called! source: " << str._data << std::endl;
	}

	MyString( MyString&& str) {
		_len = str._len;
		_init_data(str._data);
		str._len = 0;
		str._data = NULL;
		//str.~MyString();
		std::cout << "Move Constructor is called! source: " << _data<<"  "<< std::endl;
	}

	MyString& operator=(const MyString& str) {
		if (this != &str) {
			_len = str._len;
			_init_data(str._data);
		}
		std::cout << "Copy Assignment is called! source: " << str._data << std::endl;
		return *this;
	}

	virtual ~MyString() {
		if (_data) free(_data);
		std::cout << "free data " << this << endl;
	}
};

void showString(string&& s) {
	std::cout << s << endl;
}
/*int main() {
	MyString a;
	a = MyString("Hello");
	std::vector<MyString> vec;
	vec.push_back(MyString("World"));
	vec.push_back(a);

	
	getchar();
	return 0;
}*/