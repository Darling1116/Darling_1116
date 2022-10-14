#include <iostream>
#include <vector>

using namespace std;


//����B���Ľ��
template <class K, int M>
struct BTreeNode{
	//�ؼ��ֵĸ����Ⱥ���С1
	K _keys[M];  //�ؼ���
	BTreeNode<K, M>* _subs[M + 1];  //���ӽ��
	BTreeNode<K, M>* _parent;  //ָ���丸����ָ��
	size_t _n;  //�ؼ��ֵ���Ч����

	//��ʼ��Ĭ�Ϲ��캯��
	BTreeNode()
		:_parent(nullptr),
		_n(0)
	{
		for (size_t i = 0; i < M; i++){
			_keys[i] = K();
			_subs[i] = nullptr;
		}
	}
};


//����B��ģ����
template <class K, int M>
class BTree{
public:
	typedef BTreeNode<K, M> Node;

	//���ң�����key���ڽ�㼰���±�
	pair<Node*, int> find(const K& key){
		Node* cur = _root;
		Node* parent = nullptr; //Ϊ�˷�������Ĳ����������¼��ǰ���ĸ����

		while (cur != nullptr){
			size_t i = 0; 
			while (i < cur->_n){
				if (key < cur->_keys[i]){
					break; //ȥ�������������
				}
				else if (key > cur->_keys[i]){
					i++; //����������
				}
				else
					return pair<Node*, int>(cur, i);
			}

			parent = cur;  //���¸����
			cur = cur->_subs[i];  //ȥ��������
		}
		return pair<Node*, int>(parent, -1);  //û�ҵ����±귵��-1
	}


	//��ĳһ����в���ؼ��ֺ����Ӧ���Һ���
	void insertKey(Node* node, const K& key, Node* child){
		//����������key�Ĵ�����λ��
		size_t i = node->_n - 1;
		for ( ; i >= 0; i--){
			if (key < node->_keys[i]){
				node->_keys[i + 1] = node->_keys[i];
				//Ų���ؼ��ֵ�ͬʱ�����Ӧ���Һ���ҲҪŲ��
				node->_subs[i + 2] = node->_subs[i + 1];
			}
			else{
				break;  //�ҵ��˴�����λ��
			}
		}

		//����key�����Ӧ���Һ���
		node->_keys[i + 1] = key;
		node->_subs[i + 2] = child;
		if (child != nullptr){
			child->_parent = node;
		}
		node->_n++;
	}


	//����
	bool insert(const K& key){
		if (_root == nullptr){
			_root = new Node;
			_root->_keys[0] = key;
			_root->_n++;
			return true;
		}
		else{
			//1.���ж�key�Ƿ��Ѿ�����
			pair<Node*, int> ret = find(key);
			if (ret.second >= 0){
				return false;  //key�Ѿ�����
			}
			else{
				//key�����ڣ�parentΪҪ�����Ҷ�ӽ��
				Node* parent = ret.first;
				K newkey = key;
				Node* child = nullptr;
				while (1){
					insertKey(parent, newkey, child);

					//2.�ж��Ƿ�����
					if (parent->_n < M){ //����������ɹ�
						return true;  
					}
					//���ˣ����з���
					size_t mid = M / 2;
					//3.����һ��[mid+1, M-1]���ݸ��ֵ�
					Node* brother = new Node;
					size_t j = 0; 
					size_t i = mid + 1;
					for ( ; i < M; i++){
						//����һ��Ĺؼ���+��Ӧ�����Ӹ��ֵ�
						brother->_keys[j] = parent->_keys[i];
						brother->_subs[j] = parent->_subs[i];
						//�����Լ���Ӧ��λ��
						parent->_keys[i] = K();
						parent->_subs[i] = nullptr;
						j++;
					}
					//�������һ���Һ��Ӹ��ֵ�
					brother->_subs[j] = parent->_subs[i];
					parent->_subs[i] = nullptr;
					//�����Լ����ֵܵ�_n
					parent->_n -= (j+1);
					brother->_n += j;

					//4.���ӣ����Լ��ĸ��׽����ȥ������λ�����ֵܺ���
					if (parent->_parent == nullptr){
						//�����Ϊ�գ��ոշ��ѵ��Ǹ����
						_root = new Node;
						_root->_keys[0] = parent->_keys[mid];
						_root->_subs[0] = parent;
						_root->_subs[1] = brother;
						_root->_n++;
						//�����������ӽ��
						parent->_parent = _root;
						brother->_parent = _root;
						return true;
					}
					else{
						//�����ǿգ�ֱ�ӽ��в���
						newkey = parent->_keys[mid];
						child = brother;
						parent = parent->_parent;
					}
				}
			}
		}
	}


	//�������
	void _inorder(Node* root){
		if (root == nullptr)
			return;
		for (size_t i = 0; i < root->_n; i++){
			_inorder(root->_subs[i]);
			cout << root->_keys[i] << " ";
		}
		_inorder(root->_subs[root->_n]);
	}

	void inorder(){
		_inorder(_root);
		cout << endl;
	}



private:
	Node* _root = nullptr;  
};


void test_BTree(){
	int arr[] = { 53, 139, 75, 49, 145, 36, 101 };
	BTree<int, 3> bt;
	for (auto e : arr){
		bt.insert(e);
	}
	bt.inorder();
	bt.insert(100);
	bt.inorder();
}