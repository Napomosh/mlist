/**
*	@file
*	This is head file of iterator for my double linked list's implementation. 
*	There are all methods declaration and their definitions.
**/

#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include "mlist.h"

namespace ns {
	/**
	*	@date 22.11.2020
	*
	*	Implementation of iterator for STL container double linked list for 
	*	train my skill in C++ programming and writing code documentation.
	**/
	template<class I>
	class iterator {
	private:
		Node<I>* _value;
	public:
		/**
		*	Default constructor. Constructs an empty iterator.
		*	@param none
		**/
		iterator();

		/**
		*	Constructor. Constructs an iterator on Node value.
		*	@param value - element pointed with this iterator.
		**/
		iterator(const Node<I>& value);

		/**
		*	Copy constructor. Constructs a copy of another iterator.
		*	@param it - iterator which copy we are creating.
		**/
		iterator(const iterator& it) = delete;

		/**
		*	Returns the value of the Node pointed with the iterator
		**/
		I& operator*() const;
	};

	template<class I>
	iterator<I>::iterator() {
		_value = new Node<I>();
	}

	template<class I>
	iterator<I>::iterator(const Node<I>& value) {

	}
}

#endif //_ITERATOR_H
