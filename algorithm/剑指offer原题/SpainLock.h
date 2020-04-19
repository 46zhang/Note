#pragma once
#include <iostream>       // std::cout
#include <atomic>         // std::atomic
#include <thread>         // std::thread
#include <vector>         // std::vector
#include <mutex>
#include <sstream>

//RAII���ַ���װ������
class SpainLockGuard {
public:
	SpainLockGuard(){
		lock();
	}
	~SpainLockGuard() {
		_lock.clear();
		printf("����\n");
	}
	void lock() {
		while (_lock.test_and_set()) {};
		printf("����\n");
	}
private:
	std::atomic_flag _lock= ATOMIC_FLAG_INIT;
	
};

class SpainLock {
public:
	void lock() {
		while (_lock.test_and_set()) {};
		printf("����\n");
	}
	void unlock() {
		_lock.clear();
		printf("����\n");
	}
private:
	std::atomic_flag _lock = ATOMIC_FLAG_INIT;
};