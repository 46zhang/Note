#include<atomic>
#include<iostream>
#include<thread>
using namespace std;
// atomic::compare_exchange_weak example:
#include <iostream>       // std::cout
#include <atomic>         // std::atomic
#include <thread>         // std::thread
#include <vector>         // std::vector
#include <mutex>
#include <sstream>
#include "SpainLock.h"
template <typename T>
class LockFreeStack {
public:
	LockFreeStack():top(nullptr)
	{

	}
	void push(T a) {
		StackNode *node = new StackNode{ a, top };
		while (!top.compare_exchange_strong(node->next, node)) {};
	}
	T pop() {
		StackNode* res = top.load();
		while (res&&!top.compare_exchange_strong(res, res->next)) {};
		if (!res)
			return -1;
		T a = res->value;
		delete res;
		return a;
	};
	void operator()()    //将类对象作为参数，需要重载运算符()
	{
		std::cout << "作为类参数对象正在执行，执行的线程为：" << std::this_thread::get_id()  << std::endl;
		return;
	}
private:
	struct StackNode {
		T value;
		StackNode * next;
	};
	atomic<StackNode *> top;
};

// a simple global linked list:
struct Node { int value; Node* next; };
std::atomic<Node*> list_head(new Node{ -1,nullptr });
mutex _mutex;
void append(int val) {     // append an element to the list
	Node *head = list_head.load();
	Node* newNode = new Node{ val,nullptr };
	// next is the same as: list_head = newNode, but in a thread-safe way:
	while (!list_head.compare_exchange_weak(newNode->next, newNode)) {}
	//(with newNode->next updated accordingly if some other thread just appended another node)
	
	/*Node * newNode = new Node{ val,nullptr };
	Node *head = list_head.load();
	lock_guard<mutex> a(_mutex);
	while (head->next) {
		head = head->next;
		printf("data:  %d   ", head->value);
	}
	while (!list_head.compare_exchange_weak(head->next, newNode)) {
		printf("%x   ", head->next);
	};*/
}
void freeLockLinkTest() {
	// spawn 10 threads to fill the linked list:
	std::vector<std::thread> threads;
	for (int i = 0; i < 10; ++i) threads.push_back(std::thread(append, i));
	for (auto& th : threads) th.join();
	// print contents :
	for (Node* it = list_head; it != nullptr; it = it->next)
		std::cout << ' ' << it->value;
	std::cout << '\n';
	// cleanup:
	Node* it; while (it = list_head) { list_head = it->next; delete it; }
}
void pushToStack(int val,LockFreeStack<int>& s) {
	s.push(val);
	//cout << "over" << endl;
}
void freeLockStackTest() {
	// spawn 10 threads to fill the linked list:
	std::vector<std::thread> threads;
	LockFreeStack<int> s;
	for (int i = 0; i < 10; ++i) threads.push_back(std::thread(pushToStack,i,std::ref(s)));
	for (auto& th : threads) th.join();
	
	// print contents:
	//pushToStack(1, s);
	//pushToStack(2,s);
	//pushToStack(3, s);

	for (int i = 0; i < 10; ++i)
		cout << s.pop() << " ";
	std::cout << '\n';
	
}
atomic_int atomicA = { 10 };


std::atomic_flag lock_stream = ATOMIC_FLAG_INIT;
std::stringstream stream;

int globalNum(0);
SpainLock a;
void append_number(int x)
{
	//SpainLock a;
	a.lock();
	a.unlock();
	
	globalNum = x;
	stream << "thread #" << globalNum << '\n';
	//a.unlock();
}

/*
//进行自旋锁的测试
int main()
{
	std::vector < std::thread > threads;
	for (int i = 1; i <= 10; ++i)
		threads.push_back(std::thread(append_number, i));
	for (auto & th : threads)
		th.join();

	std::cout << stream.str() << std::endl;;
	getchar();
	return 0;
}*/
/*int main()
{
	//freeLockStackTest();
	freeLockLinkTest();
	int b = 20;
	int c = 50;
	bool flag=atomicA.compare_exchange_strong(b, c);
	cout << atomicA << "   " << b << "   " << c <<"  "<<flag<< endl;

	flag = atomicA.compare_exchange_strong(b,c);
	cout << atomicA << "   " << b << "   " << c << "  " << flag << endl;

	int d = 30;
	atomicA.exchange(d);
	cout << atomicA << "   " << b << "   " << c << "  " << d << endl;
	getchar();
	return 0;
}*/