#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <atomic>
#include <condition_variable>

using namespace std;

//RAII����---lock_guard
namespace GXR{
	template <class Lock>
	class lock_guard{
	public:
		lock_guard(Lock& lock)
			:_lock(lock){
			_lock.lock();
			cout << "����" << endl;
		}

		~lock_guard(){
			_lock.unlock();
			cout << "����" << endl;
		}

		lock_guard(const lock_guard<Lock>& lg) = delete;
	private:
		Lock& _lock;
	};
}
