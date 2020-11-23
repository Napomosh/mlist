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
	class Node {
	private:
		T _value;
		Node* _next;
		Node* _prev;

	public:
		Node(const T& value = *(new T()), Node* next = nullptr, Node* prev = nullptr) :
			_value(value), _next(next), _prev(prev) {}
		~Node() {}

		Node<T>* get_next() {
			return _next;
		}
		void set_next(Node<T>* value) {
			_next = value;
		}
		Node<T>* get_prev() {
			return _prev;
		}
		void set_prev(Node<T>* value) {
			_prev = value;
		}
		T& get_value() {
			return _value;
		}
		void set_value(const T& value) {
			_value = value;
		}
	};

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

		/**
		*	Delete element from the end of the list
		*	@param none
		*	@return none
		*	@exception none
		**/
		void pop_back();

		/**
		*	Delete element from the begin of the list
		*	@param none
		*	@return none
		*	@exception none
		**/
		void pop_front();

	private:
		/*template<class T>
		class Node {
		public:
			T _value;
			Node* _next;
			Node* _prev;

			Node(const T& value = *(new T()), Node* next = nullptr, Node* prev = nullptr) :
				_value(value), _next(next), _prev(prev) {}
			~Node() {}
		};*/

		Node<T>* _head;
		Node<T>* _tail;
		size_t _size;
	};

	template<class T>
	void mlist<T>::print_list() {
		Node<T>* cur = _head;
		while (cur != nullptr) {
			std::cout << cur->get_value() << " ";
			cur = cur->get_next();
		}
	}

	template<class T>
	mlist<T>::mlist() : _size(0), _head(nullptr), _tail(nullptr) {}

	template<class T>
	mlist<T>::mlist(const size_t init_size) : _size(init_size) {
		Node<T>* cur = new Node<T>();
		_head = cur;
		for (size_t i = 1; i < _size; i++) {
			cur->set_next(new Node<T>());
			cur->get_next()->set_next(cur);
			cur = cur->get_next();
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
			while (rhs_cur->get_next() != nullptr) {
				cur->set_value(rhs_cur->get_value());
				cur->set_next(new Node<T>());
				cur = cur->get_next();
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
		while (rhs_cur->get_next() != nullptr) {
			cur->set_value(rhs_cur->get_value());
			cur->set_next(new Node<T>());
			cur->get_next()->set_prev(cur);
			cur = cur->get_next();
			rhs_cur = rhs_cur->get_next();
		}
		cur->set_value(rhs_cur->get_value());
		_tail = cur;

		return *this;
	}

	template<class T>
	mlist<T>::~mlist() {
		Node<T>* cur = this->_head;
		while (cur->get_next() != nullptr) {
			if (cur->get_prev() != nullptr) {
				delete cur->get_prev();
			}
			cur = cur->get_next();
		}
		delete cur;
	}

	template<class T>
	void mlist<T>::push_back(const T& value) {
		Node<T>* tmp = new Node<T>(value, nullptr, _tail);
		_tail->set_next(tmp);
		_tail = tmp;
		_size++;
	}

	template<class T>
	void mlist<T>::push_front(const T& value) {
		Node<T>* tmp = new Node<T>(value, _head, nullptr);
		_head->set_prev(tmp);
		_head = tmp;
		_size++;
	}

	template<class T>
	void mlist<T>::pop_back() {
		Node<T>* tmp = _tail->get_prev();
		tmp->set_next(nullptr);
		delete _tail;
		_tail = tmp;
		_size--;
	}

	template<class T>
	void mlist<T>::pop_front() {
		Node<T>* tmp = _head->get_next();
		tmp->set_prev(nullptr);
		delete _head;
		_head = tmp;
		_size--;
	}
};
#endif // _MLIST_H_