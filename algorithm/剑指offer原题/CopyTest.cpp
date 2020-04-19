#include<string>
#include<vector>
using namespace std;

/*
c++默认的拷贝构造函数是浅拷贝
浅拷贝就是对象的数据成员之间的简单赋值，如你设计了一个没有类而没有提供它的复制构造函数，
当用该类的一个对象去给令一个对象赋值时所执行的过程就是浅拷贝
*/
class A
{
public:
	A(int _data) : data(_data) {}
	A() {}
private:
	int data;
};

/*
对于堆、文件等资源一般要进行进行深层拷贝，以堆上的指针为例子，如果是浅层拷贝，俩个对象的指针指向同一块内存
在进行析构时，内存会释放俩次，俩次delete
*/
class B
{
public:
	B() { data = new int; }
	B(int _data)  {
		data = new int;
		*data = _data;
	}
	B(B& a) {
		data = new int;
		*data = *(a.data);
	}
	B& operator= (const B & a) {
		*data = *(a.data);
	}
	
private:
	int* data;
};

/*int main() {
	A a1(5);
	A  a2= a1;//浅拷贝，直接拷贝其数据
	B b1(10);
	B b2 = b1;//已经定义了构造函数，且是深拷贝
	
	getchar();
	return 0;
}*/