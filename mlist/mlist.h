/**
*	@file
*	This is head file of my double linked list's implementation. There are all methods 
*	declaration and their definitions.
**/


#ifndef _MLIST_H_
#define _MLIST_H_

#include <cstdlib>
#include <iostream>

namespace ns {
	/**
	*	@date 19.11.2020
	*
	*	Implementation of STL container double linked list for train my skill in
	*	C++ programming and writing code documentation.
	**/
	template<class T>
	class mlist {
	public:
		/**
		*	Default constructor. Constructs an empty container with 0 size. Tail and head
		*	is nullptr.
		*	@param none
		**/
		mlist();

		/**
		*	Constructor. Constructs an empty container with init_size size. Each node has value
		*   as T object which created with default constructor.
		*	@param init_size - Initial list size
		**/
		mlist(const size_t init_size);

		/**
		*	Copy constructor. Constructs a copy of another list.
		*	@param mlist - list which copy we are creating
		**/
		mlist(const mlist& mlist);

		/**
		*	Copy assignment operator. Replaces the contents with a copy
		*	of the contents of another. Pointers will be not copy but will be create new.
		*	@param rhs - another container to use as data source
		**/
		mlist& operator=(const mlist<T>& rhs);

		/**
		*	Destructor. It destroyslist.
		*	@param none
		**/
		~mlist();


		/**
		*	It prints the list that called it
		*	@param none
		**/
		void print_list();

		/**
		*	Insert the element after tail of the list.
		*	@param value - value for insert
		*	@return none
		*	@exception none
		**/
		void push_back(const T& value);

		/**
		*	Insert the element before head of the list.
		*	@param value - value for insert
		*	@return none
		*	@exception none
		**/
		void push_front(const T& value);

		//friend std::ostream& operator<<(std::ostream& out, const mlist& list) {
		//	auto cur = list._head;
		//	while (cur->_next != nullptr) {
		//		out << cur->_value << " ";
		//		cur = cur->_next;
		//	}
		//	return out;
		//}

	private:
		template<class T>
		class Node {
		public:
			T _value;
			Node* _next;
			Node* _prev;

			Node(const T& value = *(new T()), Node* next = nullptr, Node* prev = nullptr) :
				_value(value), _next(next), _prev(prev) {}
		};

		Node<T>* _head;
		Node<T>* _tail;
		size_t _size;
	};

	template<class T>
	void mlist<T>::print_list() {
		Node<T>* cur = _head;
		while (cur != nullptr) {
			std::cout << cur->_value << " ";
			cur = cur->_next;
		}
	}

	template<class T>
	mlist<T>::mlist() : _size(0), _head(nullptr), _tail(nullptr) {}

	template<class T>
	mlist<T>::mlist(const size_t init_size) : _size(init_size) {
		Node<T>* cur = new Node<T>();
		_head = cur;
		for (size_t i = 1; i < _size; i++) {
			cur->_next = new Node<T>();
			cur->_next->_prev = cur;
			cur = cur->_next;
		}
		_tail = cur;
	}

	template<class T>
	mlist<T>::mlist(const mlist& mlist) : _size(mlist._size) {
		if (mlist._head == nullptr) {
			std::cerr << "Cannot copying null vector" << std::endl;
			this->_head = nullptr;
			this->_tail = nullptr;
			this->_size = 0;
		}
		else {
			Node<T>* cur = new Node<T>();
			this->_head = cur;
			Node<T>* rhs_cur = mlist._head;
			while (rhs_cur->_next != nullptr) {
				cur->_value = rhs_cur->_value;
				cur->_next = new Node<T>();
				cur = cur->_next;
			}
			this->_tail = cur;
		}
	}

	template<class T>
	mlist<T>& mlist<T>::operator=(const mlist<T>& rhs) {
		_size = rhs._size;
		Node<T>* rhs_cur = rhs._head;
		Node<T>* cur = new Node<T>();
		_head = cur;
		while (rhs_cur != nullptr) {
			cur->_value = rhs_cur->_value;
			cur->_next = new Node<T>();
			cur->_prev = cur;
			cur = cur->_next;
			rhs_cur = rhs_cur->_next;
		}

		_tail = cur;

		return *this;
	}

	template<class T>
	mlist<T>::~mlist() {
		Node<T>* cur = this->_head;
		while (cur->_next != nullptr) {
			if (cur->_prev != nullptr) {
				delete cur->_prev;
			}
			cur = cur->_next;
		}
		delete cur;
	}

	template<class T>
	void mlist<T>::push_back(const T& value) {
		Node<T>* tmp = new Node<T>(value, nullptr, _tail);
		_tail->_next = tmp;
		_tail = tmp;
		_size++;
	}

	template<class T>
	void mlist<T>::push_front(const T& value) {
		Node<T>* tmp = new Node<T>(value, _head, nullptr);
		_head->_prev = tmp;
		_head = tmp;
		_size++;
	}
};
#endif // _MLIST_H_