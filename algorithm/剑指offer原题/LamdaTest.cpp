#include<iostream>
#include<string>
using namespace std;
/*

每当你定义一个lambda表达式后，编译器会自动生成一个匿名类（这个类当然重载了()运算符），我们称为闭包类型
lambda表达式有俩种捕获值得方式，引用捕获跟复制捕获
复制捕获相当于在匿名类里面生成一个非静态数据成员，无法直接对其进行修改，因为函数调用运算符的重载方法是const属性的
需要用mutable进行修饰
对于引用捕获方式，无论是否标记mutable，都可以在lambda表达式中修改捕获的值。
至于闭包类中是否有对应成员，C++标准中给出的答案是：不清楚的，看来与具体实现有关

*/


/*int main()
{
	int x = 10;
	int &p = x;

	auto add_x = [&x](int a) { x *= 2; return a + x; };  // 引用捕捉x
	auto mutil_x = [x](int a) mutable { x *= 2; return a + x; };  // 复制捕捉x
	cout << add_x(10) << endl; // 输出 30
	cout << x << endl;
	//从C++14开始，lambda表达式支持泛型：其参数可以使用自动推断类型的功能
	auto add_two_num = [](auto a, auto b) { return a + b; };
	string a= "123.153";
	string b = "115.15";
	cout << add_two_num(10, 12.5) << "  " << add_two_num(a,b) << endl;;
	getchar();
	return 0;
}*/