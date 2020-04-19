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
ָ���ƫ�ػ�
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

//ģ��������
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
һ�����ǿ��������������::���������ͻ�����ľ�̬�������ɱ�������������ȥ���ж�
���ڷ�ģ���࣬���ڱ����ڼ��޴Ӷ�֪�����Ա������޷�֪��::�������ͻ��Ǿ�̬������
�����ùؼ���typename����˵��,���߱���������һ������
*/
template<typename I>
typename Type_Trait<I>::value_type func(I iter) {
	//ģ������в����Ƶ��������ж����ͣ������޷��ɸù����Ƶ�������ֵ����
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