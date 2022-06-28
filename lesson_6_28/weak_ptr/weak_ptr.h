#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <mutex>
#include <memory>  //c++�е�����ָ����memory����

using namespace std;

namespace GXR{
	template <class T>
	class shared_ptr{
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr),
			_count(new int(1)),
			_pmutex(new mutex){
			cout << "shared_ptr..." << _ptr << endl;
		}

		T& operator*(){
			return *_ptr;
		}

		T* operator->(){
			return _ptr;
		}

		int& get_count(){
			return *_count;
		}

		T* get_ptr(){
			return _ptr;
		}

		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr),
			_count(sp._count),
			_pmutex(sp._pmutex){
			add_ref_count();
			//cout << _count << ": " << *_count << endl;
			//cout << "shared_ptr..." << _ptr << endl;
		}

		shared_ptr<T>& operator=(shared_ptr<T>& sp){
			if (_ptr != sp._ptr){
				release();
	
				_ptr = sp._ptr;
				_count = sp._count;
				_pmutex = sp._pmutex;

				add_ref_count();
			}
			//cout << "operator=..." << _ptr << endl;
			return *this;
		}


		~shared_ptr(){
			release();
		}

	private:
		void add_ref_count(){
			_pmutex->lock();
			++(*_count);
			_pmutex->unlock();
		}

		void release(){  //�ͷ���ǰ����Դ����Ҳ����Դ��ҲҪ�ͷ�
			bool deleteflag = false;

			_pmutex->lock();
			if (--(*_count) == 0){
				cout << "delete..." << _ptr << endl;
				delete _ptr;
				delete _count;
				deleteflag = true;
			}
			_pmutex->unlock();

			if (deleteflag == true){
				delete _pmutex;
				cout << "delete pmutex..." << _pmutex << endl;
			}
		}

	private:
		T* _ptr;
		int* _count;
		mutex* _pmutex;
	};


	//ģ��ʵ��weak_ptr
	template <class T>
	class weak_ptr{
	public:
		//��֧��ԭ��ָ�빹�죬������ָ����ͷ�
		weak_ptr(){
			_ptr = nullptr;
		}

		weak_ptr(const shared_ptr<T>& sp){
			_ptr = sp.get_ptr();
		}

		weak_ptr<T>& operator=(shared_ptr<T>& sp){
			_ptr = sp.get_ptr();
			return *this;
		}

	private:
		T* _ptr;
	};

	struct Node{
		int _data;
		weak_ptr<Node> _prev;
		weak_ptr<Node> _next;
		//shared_ptr<Node> _prev;
		//shared_ptr<Node> _next;

		/*std::weak_ptr<Node> _prev;
		std::weak_ptr<Node> _next;*/
		~Node(){
			cout << "~Node( )" << endl;
		}

	};

	void test_weak_ptr_3(){
		shared_ptr<Node> node1(new Node);
		shared_ptr<Node> node2(new Node);
		cout << node1.get_count() << endl;
		cout << node2.get_count() << endl;
		node1->_next = node2;
		node2->_prev = node1;
		cout << node1.get_count() << endl;
		cout << node2.get_count() << endl;
	}


	void test_weak_ptr_1(){
		shared_ptr<Node> node1(new Node);
		shared_ptr<Node> node2(new Node);

		cout << node1.get_count() << endl;
		cout << node2.get_count() << endl;
		//������shared_ptr��ѭ�����õ����⣬node1��node2���ᱻ�ͷ�
		/*node1->_prev = node2;
		node2->_next = node1;*/
		//Node1��node2�е�count�������2
		cout << node1.get_count() << endl;
		cout << node2.get_count() << endl;
	}

	//ʹ��weak_ptr���shared_ptr�г��ֵ�ѭ�����õ�����
	//��_prev��_next�Ķ������͸�Ϊweak_ptr
	void test_weak_ptr_2(){
		std::shared_ptr<Node> node1(new Node);
		std::shared_ptr<Node> node2(new Node);

		cout << node1.use_count() << endl;
		cout << node2.use_count() << endl;
		/*node1->_prev = node2;
		node2->_next = node1;*/
		cout << node1.use_count() << endl;
		cout << node2.use_count() << endl;
	}

	//���Ʒº���ɾ����
	template <class T>
	struct FreeFunc{
		void operator()(T* ptr){
			cout << "free: " << ptr << endl;
			delete[] ptr;
		}
	};

	void test(){
		//sp1�������һ��Node�͵�����
		std::shared_ptr<Node> sp1(new Node[10], GXR::FreeFunc<Node>());

		//����lambda���ʽɾ����
		std::shared_ptr<FILE> sp2(fopen("test.txt", "w"), [](FILE* ptr){
			cout << "fclose: " << ptr << endl;
			fclose(ptr);
		});
	}

}