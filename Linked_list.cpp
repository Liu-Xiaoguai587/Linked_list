#include"Linked_list.h"


//link无参构造函数
template<class Tlink>
link<Tlink>::link() {
	this->m_Next = NULL;
	this->m_Date = 0;
}


/********************************************************/


//list无参构造函数
template<class Tlist>
list<Tlist>::list() {
	m_Size = 0;
	this->m_Head = NULL;
	this->m_Tail = NULL;
}

//list有参构造函数
template<class Tlist>
list<Tlist>::list(Tlist num) {
	link<Tlist>* _tempLink;
	_tempLink = new link<Tlist>;
	_tempLink->m_Date = num;
	this->m_Head = _tempLink;
	this->m_Tail = _tempLink;

	//link<Tlist>* _tempLink;
	//_tempLink = new link<Tlist>;
	//_tempLink->m_Date = num;
	//_tempLink->m_Next = NULL;
	//this->m_Tail->m_Next = _tempLink;
	//this->m_Tail = _tempLink;

	m_Size = 1;
}

//list拷贝构造函数
template<class Tlist>
list<Tlist>::list(const Tlist& l) {
	this->m_Size = l.m_Size;
}

//尾插
template<class Tlist>
void list<Tlist>::push_back(Tlist num) {
	if (m_Size) {
		link<Tlist>* _tempLink;
		_tempLink = new link<Tlist>;
		_tempLink->m_Date = num;
		_tempLink->m_Next = NULL;
		this->m_Tail->m_Next = _tempLink;
		this->m_Tail = _tempLink;

		m_Size++;
	}// if end
	else {
		link<Tlist>* _tempLink;
		_tempLink = new link<Tlist>;
		_tempLink->m_Date = num;
		this->m_Head = _tempLink;
		this->m_Tail = _tempLink;

		m_Size = 1;
	}// elde end
}

//头插
template<class Tlist>
void list<Tlist>::push_front(Tlist num) {
	if (m_Size) {
		link<Tlist>* _tempLink;
		_tempLink = new link<Tlist>;
		_tempLink->m_Next = this->m_Head;
		_tempLink->m_Date = num;
		this->m_Head = _tempLink;

		m_Size++;

	}// if end
	else {
		link<Tlist>* _tempList;
		_tempList->m_Date = num;
		this->m_Head = _tempList;
		this->m_Tail = _tempList;

		m_Size = 1;
	}// else end
}

//尾删
template<class Tlist>
void list<Tlist>::pop_back() {
	delete this->m_Tail;
	this->m_Tail = NULL;
	link<Tlist>* _tempLink;
	_tempLink = this->m_Head;
	for (int i = 0; i < (m_Size - 1); i++) {
		_tempLink = _tempLink->m_Next;
	}
	this->m_Tail = _tempLink;

	m_Size--;
}

//头删
template<class Tlist>
void list<Tlist>::pop_front() {
	link<Tlist>* _tempLink;
	_tempLink = this->m_Head->m_Next;
	delete this->m_Head;
	m_Head = _tempLink;
}



//返回链表数据数量
template<class Tlist>
int list<Tlist>::size(void) {
	return m_Size;
}

//检查链表是否为空
template<class Tlist>
bool list<Tlist>::empty() {
	if (m_Size) {
		return true;
	}// if end
	else {
		return false;
	}// else end
}

//通过at访问链表中的数据
template<class Tlist>
Tlist list<Tlist>::at(int _atNum) {
	if (m_Size) {
		link<Tlist>* _tempLink;
		_tempLink = this->m_Head;
		for (int i = 0; i < _atNum; i++) {
			_tempLink = _tempLink->m_Next;
		}

		return _tempLink->m_Date;
	}// if end
	else {
		return false;
	}// else end
}

//重载[]实现通过下标访问链表中的数据
template<class Tlist>
Tlist list<Tlist>::operator[](int _operNum) {
	if (m_Size) {
		link<Tlist>* _tempLink;
		_tempLink = this->m_Head;
		for (int i = 0; i < _operNum; i++) {
			_tempLink = _tempLink->m_Next;
		}

		return _tempLink->m_Date;
	}// if end
	else {
		return false;
	}// else end
}



/*******************************v0.1********************************/

//iterator 无参构造函数
template<class Tlist>
list<Tlist>::iterator::iterator() {
	this->m_m_it = NULL;
}

//list begin()迭代器
template<class Tlist>
Tlist* list<Tlist>::begin() {
	return &this->m_Head->m_Date;
}

//list end()迭代器
//因为链表中数据不在同一段内存中，end()迭代器并没有太大的用处。
//此end()迭代器依然指向最后一个数据后的第一个数据
template<class Tlist>
Tlist* list<Tlist>::end() {
	Tlist* _tempTlist;
	_tempTlist = &(this->m_Tail->m_Date);
	_tempTlist += sizeof(Tlist);

	return _tempTlist;
}
