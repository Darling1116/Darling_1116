#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <mutex>

using namespace std;

//RAII˼���������������ֹ�쳣��ȫ���µ���������
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
			//��lock������������ڿ��Ƴ�����Դ����֤++n������ԭ�ӵ�
			LockGuard<mutex> lock(mtx);
			++n;
		}
	}
}