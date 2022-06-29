#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <mutex>

using namespace std;

//RAII思想设计守卫锁，防止异常安全导致的死锁问题
namespace GXR{
	template <class T>
	class LockGuard{
	public:
		LockGuard(T& mutex)
			:_mutex(mutex){
			_mutex.lock();
			cout << "lock..." << endl;
		}

		~LockGuard(){
			_mutex.unlock();
			cout << "unlock..." << endl;
		}
	private:
		T& _mutex;
	};

	mutex mtx;
	static int n = 0;

	void Func(){
		for (size_t i = 0; i < 10000; i++){
			//用lock对象的生命周期控制程序资源，保证++n操作是原子的
			LockGuard<mutex> lock(mtx);
			++n;
		}
	}
}