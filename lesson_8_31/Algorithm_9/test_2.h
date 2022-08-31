#pragma once
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <unordered_set>

using namespace std;

//腐烂的橘子：0表示空格，1表示新鲜橘子，2表示腐烂橘子
//返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数
//如果不可能，返回 -1 

vector<vector<int>> v = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

int orangesRotting(vector<vector<int>>& grid) {
	if (grid.empty()){
		return 0;
	}

	int count = 0;
	int row = grid.size();
	int col = grid[0].size();

	queue<pair<int, int>> qu;

	//找本身就腐烂的橘子
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			if (grid[i][j] == 2){
				qu.push(make_pair(i, j));
				//break;
			}
		}
	}

	pair<int, int> cur;
	while (!qu.empty()){
		int n = qu.size();
		bool flag = false; //判断每一次是否有新的腐烂的橘子

		for (int i = 0; i < n; i++){
			cur = qu.front();
			qu.pop();
			for (auto e : v){
				int newx = cur.first + e[0];
				int newy = cur.second + e[1];

				if (newx < 0 || newx >= row || newy < 0 || newy >= col)
					continue;

				if (grid[newx][newy] == 1){
					flag = true;
					grid[newx][newy] = 2;
					qu.push(make_pair(newx, newy));
				}
			}

		}
		if (flag){
			count++;
		}
		else{
			break;
		}
	}

	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			if (grid[i][j] == 1){
				return -1;
			}
		}
	}
	
	return count;
	
}


void test2_1(){
	vector<vector<int>> grid = { { 2, 1, 1 }, { 1, 1, 0 }, { 0, 1, 1 } };
	//输出：4
	cout << orangesRotting(grid) << endl;
}



//单词接龙
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	unordered_set<string> dict;
	for (auto e : wordList){
		dict.insert(e);
	}

	unordered_set<string> book;
	queue<string> qu;
	qu.push(beginWord);
	book.insert(beginWord);

	int count = 1;

	string cur;
	while (!qu.empty()){
		int n = qu.size();
		for (int i = 0; i < n; i++){
			cur = qu.front();
			qu.pop();

			if (cur == endWord){
				return count;
			}

			for (int i = 0; i < cur.length(); i++){
				string str = cur;
				for (char ch = 'a'; ch <= 'z'; ch++){
					str[i] = ch;
					if (dict.find(str) != dict.end() && book.find(str) == book.end()){
						qu.push(str);
						book.insert(str);
					}
				}
			}
		}
		count++;
	}
	return 0; //不存在这样的转换序列，返回0

}

void test2_2(){
	string beginWord = "hit";
	string endWord = "cog";
	vector<string> wordList = { "hot", "dot", "dog", "lot", "log", "cog" };

	//一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
	//返回它的长度 5
	cout << ladderLength(beginWord, endWord, wordList) << endl;
}



//打开转盘锁
int openLock(vector<string>& deadends, string target) {
	unordered_set<string> deaddict;
	for (auto e : deadends){
		deaddict.insert(e);
	}

	// 起始密码在deadends中
	if (deaddict.find("0000") != deaddict.end()){
		return -1;
	}

	unordered_set<string> book;
	queue<string> qu;
	qu.push("0000");
	book.insert("0000");

	int count = 0;
	string cur;

	while (!qu.empty()){
		int n = qu.size();

		for (int i = 0; i < n; i++){
			cur = qu.front();
			qu.pop();

			if (cur == target)
				return count;

			for (int j = 0; j < 4; j++){
				char ch1 = cur[j];
				char ch2 = cur[j];

				if (cur[j] == '9'){
					ch1 = '0';
				}
				else{
					ch1++;
				}

				if (cur[j] == '0'){
					ch2 = '9';
				}
				else{
					ch2--;
				}

				string cur1 = cur;
				cur1[j] = ch1;
				string cur2 = cur;
				cur2[j] = ch2;

				if (deaddict.find(cur1) == deaddict.end() && book.find(cur1) == book.end()){
					qu.push(cur1);
					book.insert(cur1);
				}
				if (deaddict.find(cur2) == deaddict.end() && book.find(cur2) == book.end()){
					qu.push(cur2);
					book.insert(cur2);
				}

			}
		}

		count++;
	}
	return -1;  //无论如何不能解锁
}

void test2_3(){
	vector<string> deadends = { "0201", "0101", "0102", "1212", "2002" };
	string target = "0202";
	//可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" 
	//-> "1202" -> "0202"
	//输出：6
	cout << openLock(deadends, target) << endl;
}