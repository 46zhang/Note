#include<iostream>
#include<string>
using namespace std;
/*

ÿ���㶨��һ��lambda���ʽ�󣬱��������Զ�����һ�������ࣨ����൱Ȼ������()������������ǳ�Ϊ�հ�����
lambda���ʽ�����ֲ���ֵ�÷�ʽ�����ò�������Ʋ���
���Ʋ����൱������������������һ���Ǿ�̬���ݳ�Ա���޷�ֱ�Ӷ�������޸ģ���Ϊ������������������ط�����const���Ե�
��Ҫ��mutable��������
�������ò���ʽ�������Ƿ���mutable����������lambda���ʽ���޸Ĳ����ֵ��
���ڱհ������Ƿ��ж�Ӧ��Ա��C++��׼�и����Ĵ��ǣ�������ģ����������ʵ���й�

*/


/*int main()
{
	int x = 10;
	int &p = x;

	auto add_x = [&x](int a) { x *= 2; return a + x; };  // ���ò�׽x
	auto mutil_x = [x](int a) mutable { x *= 2; return a + x; };  // ���Ʋ�׽x
	cout << add_x(10) << endl; // ��� 30
	cout << x << endl;
	//��C++14��ʼ��lambda���ʽ֧�ַ��ͣ����������ʹ���Զ��ƶ����͵Ĺ���
	auto add_two_num = [](auto a, auto b) { return a + b; };
	string a= "123.153";
	string b = "115.15";
	cout << add_two_num(10, 12.5) << "  " << add_two_num(a,b) << endl;;
	getchar();
	return 0;
}*/