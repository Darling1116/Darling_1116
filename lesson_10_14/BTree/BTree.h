#include <iostream>
#include <vector>

using namespace std;


//定义B树的结点
template <class K, int M>
struct BTreeNode{
	//关键字的个数比孩子小1
	K _keys[M];  //关键字
	BTreeNode<K, M>* _subs[M + 1];  //孩子结点
	BTreeNode<K, M>* _parent;  //指向其父结点的指针
	size_t _n;  //关键字的有效个数

	//初始化默认构造函数
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


//定义B树模板类
template <class K, int M>
class BTree{
public:
	typedef BTreeNode<K, M> Node;

	//查找：返回key所在结点及其下标
	pair<Node*, int> find(const K& key){
		Node* cur = _root;
		Node* parent = nullptr; //为了方便后续的插入操作，记录当前结点的父结点

		while (cur != nullptr){
			size_t i = 0; 
			while (i < cur->_n){
				if (key < cur->_keys[i]){
					break; //去左孩子里继续查找
				}
				else if (key > cur->_keys[i]){
					i++; //继续向后查找
				}
				else
					return pair<Node*, int>(cur, i);
			}

			parent = cur;  //更新父结点
			cur = cur->_subs[i];  //去左孩子里找
		}
		return pair<Node*, int>(parent, -1);  //没找到，下标返回-1
	}


	//在某一结点中插入关键字和其对应的右孩子
	void insertKey(Node* node, const K& key, Node* child){
		//从右向左找key的待插入位置
		size_t i = node->_n - 1;
		for ( ; i >= 0; i--){
			if (key < node->_keys[i]){
				node->_keys[i + 1] = node->_keys[i];
				//挪动关键字的同时，其对应的右孩子也要挪动
				node->_subs[i + 2] = node->_subs[i + 1];
			}
			else{
				break;  //找到了待插入位置
			}
		}

		//插入key及其对应的右孩子
		node->_keys[i + 1] = key;
		node->_subs[i + 2] = child;
		if (child != nullptr){
			child->_parent = node;
		}
		node->_n++;
	}


	//插入
	bool insert(const K& key){
		if (_root == nullptr){
			_root = new Node;
			_root->_keys[0] = key;
			_root->_n++;
			return true;
		}
		else{
			//1.先判断key是否已经存在
			pair<Node*, int> ret = find(key);
			if (ret.second >= 0){
				return false;  //key已经存在
			}
			else{
				//key不存在，parent为要插入的叶子结点
				Node* parent = ret.first;
				K newkey = key;
				Node* child = nullptr;
				while (1){
					insertKey(parent, newkey, child);

					//2.判断是否满了
					if (parent->_n < M){ //不满，插入成功
						return true;  
					}
					//满了，进行分裂
					size_t mid = M / 2;
					//3.分裂一半[mid+1, M-1]数据给兄弟
					Node* brother = new Node;
					size_t j = 0; 
					size_t i = mid + 1;
					for ( ; i < M; i++){
						//拷贝一半的关键字+对应的左孩子给兄弟
						brother->_keys[j] = parent->_keys[i];
						brother->_subs[j] = parent->_subs[i];
						//清理自己对应的位置
						parent->_keys[i] = K();
						parent->_subs[i] = nullptr;
						j++;
					}
					//拷贝最后一个右孩子给兄弟
					brother->_subs[j] = parent->_subs[i];
					parent->_subs[i] = nullptr;
					//更新自己和兄弟的_n
					parent->_n -= (j+1);
					brother->_n += j;

					//4.连接：往自己的父亲结点中去插入中位数和兄弟孩子
					if (parent->_parent == nullptr){
						//父结点为空，刚刚分裂的是根结点
						_root = new Node;
						_root->_keys[0] = parent->_keys[mid];
						_root->_subs[0] = parent;
						_root->_subs[1] = brother;
						_root->_n++;
						//连接两个孩子结点
						parent->_parent = _root;
						brother->_parent = _root;
						return true;
					}
					else{
						//父结点非空，直接进行插入
						newkey = parent->_keys[mid];
						child = brother;
						parent = parent->_parent;
					}
				}
			}
		}
	}


	//中序遍历
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