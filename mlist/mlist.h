#ifndef _MLIST_H_
#define _MLIST_H_

#include <cstdlib>
#include <iostream>

template<class T>
class Node {
private:
	T _value;
	Node* _next;
	Node* _prev;
};

template<class T>
class mlist {
public:
	mlist();
	mlist(const size_t init_size);
	mlist(const mlist& mlist);
	~mlist();

private:
	Node<T>* _head;
	Node<T>* _tail;
	size_t _size;
};


template<class T>
mlist<T>::mlist() : _size(0), _head(NULL) {}

template<class T>
mlist<T>::mlist(const size_t init_size) : _size(init_size) {
	Node* cur = new Node;
	_head = cur;
	for (int i = 0; i < _size; i++) {
		cur->_value = 0;
		cur = cur->_next;
	}
}

template<class T>
mlist<T>::mlist(const mlist& mlist) : _size(mlist._size) {
	if (mlist._head == NULL) {
		std::cerr << "Cannot copying null vector" << std::endl;
		this->_head = NULL;
		this->_tail = NULL;
		this->_size = 0;
	}
	else {
		Node* cur = new Node;
		this->_head = cur;
		Node* rhs_cur = mlist._head;
		while (rhs_cur->_next != NULL) {
			cur->_value = rhs_cur->_value;
			cur->_next = new Node;
			cur = cur->_next;
		}
		this->_tail = cur;
	}
}

template<class T>
mlist<T>::~mlist() {
	Node* cur = this->_head;
	while (cur->_next != NULL) {
		if (cur->_prev != NULL) {
			delete cur->_prev;
		}
		cur = cur->_next;
	}
	delete cur;
}

#endif // _MLIST_H_