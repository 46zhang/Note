#include<string>
#include<vector>
using namespace std;

/*
c++Ĭ�ϵĿ������캯����ǳ����
ǳ�������Ƕ�������ݳ�Ա֮��ļ򵥸�ֵ�����������һ��û�����û���ṩ���ĸ��ƹ��캯����
���ø����һ������ȥ����һ������ֵʱ��ִ�еĹ��̾���ǳ����
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
���ڶѡ��ļ�����Դһ��Ҫ���н�����㿽�����Զ��ϵ�ָ��Ϊ���ӣ������ǳ�㿽�������������ָ��ָ��ͬһ���ڴ�
�ڽ�������ʱ���ڴ���ͷ����Σ�����delete
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
	A  a2= a1;//ǳ������ֱ�ӿ���������
	B b1(10);
	B b2 = b1;//�Ѿ������˹��캯�����������
	
	getchar();
	return 0;
}*/