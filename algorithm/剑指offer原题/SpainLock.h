#pragma once
#include <iostream>       // std::cout
#include <atomic>         // std::atomic
#include <thread>         // std::thread
#include <vector>         // std::vector
#include <mutex>
#include <sstream>

//RAII的手法封装自旋锁
class SpainLockGuard {
public:
	SpainLockGuard(){
		lock();
	}
	~SpainLockGuard() {
		_lock.clear();
		printf("解锁\n");
	}
	void lock() {
		while (_lock.test_and_set()) {};
		printf("加锁\n");
	}
private:
	std::atomic_flag _lock= ATOMIC_FLAG_INIT;
	
};

class SpainLock {
public:
	void lock() {
		while (_lock.test_and_set()) {};
		printf("加锁\n");
	}
	void unlock() {
		_lock.clear();
		printf("解锁\n");
	}
private:
	std::atomic_flag _lock = ATOMIC_FLAG_INIT;
};