#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

void little_sleep(std::chrono::microseconds us)
{
	auto start = std::chrono::high_resolution_clock::now();
	auto end = start + us;
	do {
		std::this_thread::yield();
	} while (std::chrono::high_resolution_clock::now() < end);
}

void yeildTest() {
	auto start = std::chrono::high_resolution_clock::now();

	little_sleep(std::chrono::microseconds(100));

	auto elapsed = std::chrono::high_resolution_clock::now() - start;
	std::cout << "waited for "
		<< std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count()
		<< " microseconds\n";
}
std::mutex globalMutex;
void tryLockFunc() {
	/*std::unique_lock<std::mutex> _mutex(globalMutex);
	if (_mutex.try_lock())
		printf("锁住\n");
	else
		printf("没锁住\n");*/
	globalMutex.lock();
	printf("锁住\n");

	
}
void tryLockTest() {
	std::thread a(tryLockFunc), b(tryLockFunc);
	a.join();
	b.detach();
}
/*int main()
{
	tryLockTest();
	getchar();
	return 0;

}*/