#include<iostream>
#include<string>

using namespace std;

class A {
public:
	virtual void test() {
		cout << "AÀà" << endl;
	}
};

class B {
public:
	virtual void test() {
		cout << "BÀà" << endl;
	}
};

class C :A, B {
public:
	int a;
	void test()override {
		cout << "a" << endl;
	}
};

/*int main() {
	C t;
	t.test();
	getchar();
	return 0;
}*/