#include"Linked_list.h"


//link�޲ι��캯��
template<class Tlink>
link<Tlink>::link() {
	this->m_Next = NULL;
	this->m_Date = 0;
}


/********************************************************/


//list�޲ι��캯��
template<class Tlist>
list<Tlist>::list() {
	m_Size = 0;
	this->m_Head = NULL;
	this->m_Tail = NULL;
}

//list�вι��캯��
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

//list�������캯��
template<class Tlist>
list<Tlist>::list(const Tlist& l) {
	this->m_Size = l.m_Size;
}

//β��
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

//ͷ��
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

//βɾ
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

//ͷɾ
template<class Tlist>
void list<Tlist>::pop_front() {
	link<Tlist>* _tempLink;
	_tempLink = this->m_Head->m_Next;
	delete this->m_Head;
	m_Head = _tempLink;
}



//����������������
template<class Tlist>
int list<Tlist>::size(void) {
	return m_Size;
}

//��������Ƿ�Ϊ��
template<class Tlist>
bool list<Tlist>::empty() {
	if (m_Size) {
		return true;
	}// if end
	else {
		return false;
	}// else end
}

//ͨ��at���������е�����
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

//����[]ʵ��ͨ���±���������е�����
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

//iterator �޲ι��캯��
template<class Tlist>
list<Tlist>::iterator::iterator() {
	this->m_m_it = NULL;
}

//list begin()������
template<class Tlist>
Tlist* list<Tlist>::begin() {
	return &this->m_Head->m_Date;
}

//list end()������
//��Ϊ���������ݲ���ͬһ���ڴ��У�end()��������û��̫����ô���
//��end()��������Ȼָ�����һ�����ݺ�ĵ�һ������
template<class Tlist>
Tlist* list<Tlist>::end() {
	Tlist* _tempTlist;
	_tempTlist = &(this->m_Tail->m_Date);
	_tempTlist += sizeof(Tlist);

	return _tempTlist;
}
