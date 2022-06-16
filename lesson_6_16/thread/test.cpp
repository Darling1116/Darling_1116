#include "thread.h"

using namespace GXR;
//mutex mtx;
//void func(){
//	int x = 0;
//	mtx.lock();  //������������ʹ�̴߳��л������Ǹ���Ч
//	for (int i = 0; i < 10000; i++){
//		cout << "x: " << ++x << endl;
//		cout << "id: " << this_thread::get_id() << endl;
//	}
//	mtx.unlock();
//	cout << x << endl;
//}

//void func(){
//	int x = 0;
//	for (int i = 0; i < 10000000; i++){
//		mtx.lock();
//		++x;
//		//cout << "x: " << ++x << endl;
//		mtx.unlock();
//		//cout << "id: " << this_thread::get_id() << endl;
//	}
//}


void fun(){
	mutex mtx;
	GXR::lock_guard<mutex> lg(mtx);
	FILE* file = fopen("text.txt", "r");
	if (file == nullptr){
		//...
		return;
	}
	return;
}

int main(){
	//int n = 0;
	//cin >> n;

	//mutex mtx;
	////int x = 0;
	//atomic<int> x = 0;

	////��������߳�
	//vector<thread> threads;
	//threads.resize(n);
	////for (auto& th : threads){
	////	th = thread(func);
	////	//cout << x << endl;
	////}
	//for (auto& th : threads){
	//	th = thread([&mtx, &n, &x]{
	//		
	//		for (int i = 0; i < 1000000; i++){
	//			mtx.lock();
	//			//++x;
	//			cout << "id: " << this_thread::get_id() << " " << x++ << endl;
	//			//this_thread::sleep_for(chrono::milliseconds(500));
	//			mtx.unlock();
	//		}
	//		
	//	});
	//}

	//for (auto& th : threads){
	//	th.join();
	//}

	//cout << "x: " << x << endl;
	
	//thread th(fun);
	//th.join();


	int N = 100;
	mutex mtx;
	condition_variable cv;
	bool flag = true;

	//�߳�1����ӡ����
	thread t1([&](){
		int i = 1;
		while(i < N){
			unique_lock<mutex> lock(mtx);
			cv.wait(lock, [flag]()->bool{return flag; });  //��֤�߳�1�ȴ�ӡ
			cout << i << endl;
			i += 2;
			flag = false;
			//this_thread::sleep_for(chrono::milliseconds(500));
			cv.notify_one(); //������һ���߳�
		}
	});
	//�߳�2����ӡż��
	thread t2([&](){
		int j = 2;
		while(j <= N){
			unique_lock<mutex> lock(mtx);
			cv.wait(lock, [flag]()->bool{return !flag; });
			cout << j << endl;
			j += 2;
			flag = true;
			//this_thread::sleep_for(chrono::milliseconds(500));
			cv.notify_one();
		}
	});

	t1.join();
	t2.join();
	
	system("pause");
	return 0;
}

