#include<iostream>
#include<vector>
#include<string>
#include"TemplateTest.h"

using namespace std;

template<typename T >
class Type_Trait {
public:
	typedef T value_type;
	typedef T& referent_type;
};
/*
指针的偏特化
*/
template<typename T>
class Type_Trait<T* > {
public:
	typedef T value_type;
	typedef T& referent_type;
};

template<typename T>
class MyIter:Type_Trait<T> {
public:
	
	MyIter(T * p=0):ptr(p){}
	T& operator*() const { return *ptr; }
	bool operator<(const T& a)const {
		return *ptr < *a;
	}
	
private:
	T * ptr;
};

//模板特例化
/*template<>
class MyIter<int> {
public:
	typedef int value_type;
	MyIter(int * p = 0) :ptr(p) { cout << "aa" << endl; }
	int& operator*() const { return *ptr; }
private:
	int * ptr;
};*/

/*
一般我们可以用区域运算符::来访问类型或者类的静态变量，由编译器帮助我们去做判断
对于非模板类，由于编译期间无从而知，所以编译器无法知道::访问类型还是静态变量，
可以用关键字typename加以说明,告诉编译器这是一个类型
*/
template<typename I>
typename Type_Trait<I>::value_type func(I iter) {
	//模板可以有参数推导规则来判断类型，但是无法由该规则推导出返回值类型
	return *iter;
}

template<typename T>
T min(T& a, T& b) {
	return a < b?a:b;
}

template<typename T>
T min(const T& a, const T& b) {
	return a < b ? a : b;
}

/*template  <typename T>
class Message {
public:
	Message() { }
	Message(T& a) :data(a) {  }
	T showMessage();
private:
	std::string data;
	//std::string name;
};*/
template<typename T>
typename T Message<T> ::showMessage() {
	return data;
}


/*int main() {
	int *p = new int(8);
	memset(p, 1, 8);
	int *q = new int(10);
	memset(q, 2, 10);
	MyIter<int> pIter(p);
	MyIter<int> qIter(q);
	cout << p[0] << "  " << q[0] << endl;
	cout << *pIter << "  " << *qIter << endl;
	MyIter<int> w= func(pIter);
	MyIter<int> r= func(qIter);
	cout<<*w<<endl;
	cout << *r << endl;
	
	cout << func(p) << "  " << func(q) << endl;
	string a = "adfdf";
	string b = "ddfsf";
	int num1=11;
	int num2 = 12;

	MyIter<int> p(&num1);
	MyIter<int> q(&num2);

	cout << min(11, 10) << "  " << *(min(p,q))<<endl;
	string s("adfadf");
	Message<string> m(s);
	cout << m.showMessage() << endl;
	getchar();
	return 0;
}*/