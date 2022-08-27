#pragma once
#include <iostream>
#include <vector>
#include <string.h>
#include <unordered_set>


using namespace std;

//活字印刷
//可能的序列为 "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA"

void DFS(string tiles, unordered_set<string>& set, string curstr, vector<int>& book){
	if (!curstr.empty()){
		set.insert(curstr);
	}

	for (int i = 0; i < (int)tiles.size(); i++){
		if (book[i] == 0){
			book[i] = 1;
			DFS(tiles, set, curstr + tiles[i], book);
			//回溯
			book[i] = 0;
		}
	}
}


int numTilePossibilities(string tiles) {
	if (tiles.empty()){
		return 0;
	}

	unordered_set<string> set;
	vector<int> book(tiles.size(), 0);
	DFS(tiles, set, "", book);

	return set.size();

}


void test3_1(){
	string tiles = "AAB";

	int ret = numTilePossibilities(tiles);
	cout << ret << endl;

	//输出8
}