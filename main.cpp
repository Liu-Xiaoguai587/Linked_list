#include<iostream>
#include"Linked_list.h"
#include"Linked_list.cpp"
#include<vector>
using namespace std;

void printList(list<int>& l) {
	for (int i = 0; i < l.size(); i++) {
		cout << l[i] << " ";
	}
	cout << endl;
}


void test01() {
	list<int>l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	printList(l);

	printList(l);
}


int main() {
	test01();
	//vector<int>v;

	system("pause");
	return 0;
}