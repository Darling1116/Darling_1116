#include "LockGuard.h"
#include <thread>

using namespace GXR;

int main(){
	int begin = clock();

	thread t1(Func);
	thread t2(Func);
	t1.join();
	t2.join();

	int end = clock();
	cout << "n: " << n << endl;
	cout << "cost time: " << end - begin << endl;
	system("pause");
	return 0;
}