#define _CRT_SECURE_NO_WARNINGS

#include "List.h"
using namespace GXR;
using std::cout;
using std::endl;

	void ListTest()
	{
		List<int> l1;
		//l1.PopFront();
		//l1.PushFront(6);
		l1.PushBack(1);
		l1.PushBack(2);
		//l1.PushBack(3);
		//l1.PushBack(4);
		//l1.PopBack();
		//l1.PushFront(5);
		//l1.PushFront(6);
		//l1.PopFront();
		List<int>::iterator pos = l1.begin();
		pos++;
		l1.Insert(pos, 9);
		l1.Erase(pos);
		List<int> l2;
		
		List<int>::iterator it1 = l1.begin();
		while (it1 != l1.end())
		{
			cout << *it1 << " ";
			it1++;
		}
		cout << endl;
        
		cout << l1.Size() << endl;
		cout << l1.Empty() << endl;

		//List<int>::iterator it2 = l2.begin();
		//while (it2 != l2.end())
		//{
		//	cout << *it2 << " ";
		//	it2++;
		//}
		//cout << endl;
	}




int main()
{
	ListTest();

	system("pause");
	return 0;
	
}