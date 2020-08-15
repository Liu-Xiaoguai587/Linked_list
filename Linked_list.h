#pragma once
#include<iostream>
using namespace std;

template<class Tlist>
class list;


/******************************************************/


template<class Tlink>
class link {
	
public:
	link();

	Tlink m_Date;
	link* m_Next;
};


/******************************************************/


template<class Tlist>
class list {
public:
	list();
	list(Tlist num);
	list(const Tlist& l);

	void push_back(Tlist num);
	void push_front(Tlist num);
	void pop_back();
	void pop_front();


	int size(void);
	bool empty(void);

	Tlist at(int _atNum);
	Tlist operator[](int _operNum);
	

private:
	unsigned int m_Size;
	link<Tlist>* m_Head;
	link<Tlist>* m_Tail;
};