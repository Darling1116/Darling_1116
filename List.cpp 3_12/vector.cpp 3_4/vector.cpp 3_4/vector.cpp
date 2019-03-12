#include "vector.h"

namespace GXR
{
	template <class T>
	class Vector
	{
	public:
		typedef T* iterator;

		Vector() = default;


		Vector(size_t n, const T& value = T())
		{
					Reverse(n);
					while (n--)
					{

						PushBack(value);

						//错误的
						/**(_finish) = value;
						_finish--;*/
						
					}
				
		}
		
		~Vector()
		{
			if (_start)
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}

		//v2(v1)

		Vector(Vector <T>& v)
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			Reserve(v.Capacity());
				iterator it = begin();
				iterator vit = v.begin();
				size_t size = v.Size();
				while (vit != v.end())
				{
					*it = *vit;
					it++;
					vit++;
				}


		//Vector(Vector <T>& v)

		//{
		//	_start = new T[v.Capacity()];
		//	//不能用Reverse，原因是_start原来没有空间

		//	iterator it = _start;
		//	iterator vit = v.begin();
		//	size_t size = v.Size();
		//	for (size_t i = 0; i < size; i++)
		//	{
		//		*it = *vit;
		//		it++;
		//		vit++;
		//	}
			
	
			_finish = _start + v.Size();
			_end_of_storage = _start + v.Capacity();
		}

		//v2=v
		Vector<T>& operator = (Vector<T> v)
		{
			//swap(v);
			//return *this;
			_start = new T[v.Capacity()];
			iterator it = _start;
			iterator vit = v.begin();
			for (size_t i = 0; i < v.Size(); i++)
			{
				*it = *vit;
				it++;
				vit++;
			}
			_finish = _start + v.Size();
			_end_of_storage = _start + v.Capacity();
		}


		size_t Size()
		{
			return _finish - _start;
		}

		size_t Capacity()
		{
			return _end_of_storage - _start;
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const iterator cbegin() const
		{
			return _start;
		}

		const iterator cend() const
		{
			return _finish;
		}

		void Reserve(size_t n)
		{
			if (n > Capacity())
			{
				size_t size = Size();
				T*tmp = new T [n];

				for (size_t i = 0; i < size; i++)
				{
					tmp[i] = _start[i];
				}
				//if (_start)
				//{

				//	memcpy(tmp, _start, sizeof(T)*size);
				//	delete[]_start;
				//}

				_start = tmp;
				_finish = _start + size;
				_end_of_storage = _start + n;
			}
		}

		void Resize(size_t n, const T& value = T())
		{
			if (n <= Size())
			{
				_finish = _start + n;
				
			}
			else
			{
				Reserve(n);
				//while (_finish != _start + n)
				//{
				//	*_finish = value;
				//	_finish++;
				//}
				while (n-Size())
				{
					PushBack(value);
					n--;
				}
			
			}
		
		}


	void PushBack(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				size_t newcapacity = Capacity() == 0 ? 1 : Capacity() * 2;
				Reserve(newcapacity);
			}
			*_finish = x;
			_finish++;
		}

	iterator Insert(iterator pos, const T& x)
	{
		assert(pos <= _finish);
		if (_finish == _end_of_storage)
		{
			size_t n = pos - _start;
			
			size_t newcapacity = Capacity() == 0 ? 1 : Capacity() * 2;
			Reserve(newcapacity);
			pos = _start + n;
		}

		iterator end = _finish - 1;
		while (end >= pos)
		{
			*(end + 1) = *end;
			end--;
		}

		//这是错误的，改变了_finish的位置
		//while (_finish > pos)
		//{
		//	*_finish = *(_finish - 1);
		//	_finish--;
		//}

		*pos = x;
		_finish++;
		return pos;
	
	}

	iterator Erase(iterator pos)
	{
		assert(pos <= _finish);
		if (pos == _finish)
		{
			_finish--;
			return pos;
		}
		else
		{
			iterator begin = pos;
			while (begin <= _finish)
			{
				*begin = *(begin +1);
				begin++;
			}
			_finish--;
			return pos;
		}
	}



	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;


	};
}

int main()
{
	using namespace GXR;
	Vector <int> v1;
	v1.PushBack(1);
	v1.PushBack(2);
	v1.PushBack(3);
	v1.PushBack(4);

	/*Vector<int>v2 (v1);*/

	//Vector<int>::iterator it = v1.begin();
	//while (it != v1.end())
	//{
	//	cout << *it << " ";
	//	it++;
	//}
	//cout << endl;


	/*v1.Resize(10, 7);*/
	//Vector<int>::iterator pos1 = find(v1.begin(), v1.end(), 3);
	//v1.Insert(pos1, 10);
	//Vector<int>::iterator pos2 = find(v1.begin(), v1.end(), 3);
	//v1.Erase(pos2);

	//Vector<int> v2(6, 1);

	Vector<int> v2 = v1;
	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}