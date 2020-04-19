#include<iostream>
#include<string>

using namespace std;

struct student {
	void print() { cout << "a"; }
	virtual void p() { cout << "hello"; };
	
};

/*int main() {
	student a;
	cout << sizeof(a) << endl;
	int *p;		
	char *q;
	student *x;
	cout << sizeof(p) << "  " << sizeof(q) << "  " << sizeof(x) << endl;
	getchar();
	return 0;
}*/