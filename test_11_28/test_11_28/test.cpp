#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//�� 1 + 2 + ... + n ��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ���

//1�����õݹ�
int sumNums_1(int n){
	if (n == 0)
		return 0;
	return n + sumNums_1(n - 1);
}

//2.������ľ�̬��Ա�����͹��캯��
class Add{
public:
	Add(){
		ret += count;
		count++;
	}

	static int GetRet(){
		return ret;
	}

	static void Init(){
		count = 1;
		ret = 0;
	}

private:
	static int count;
	static int ret;
};


//��̬��Ա�������������������ⶨ��
int Add::count = 1;
int Add::ret = 0;

int sumNums_2(int n){
	Add::Init();
	for (int i = 0; i < n; i++){
		Add arr;
	}
	return Add::GetRet();
}

int main(){
	cout << sumNums_1(10) << endl;
	cout << sumNums_2(10) << endl;

	system("pause");
	return 0;
}