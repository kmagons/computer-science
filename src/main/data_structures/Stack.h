#ifndef STACK_H
#define STACK_H

#include "List.h"

template <typename StackType>

class Stack {

	protected:
	
		List<StackType> * linked_list;
		const std :: string STACK_EMPTY_ERROR = "The stack is empty, nothing to pop";

	public:
		
		Stack();
		~Stack();
		int getSize();
		bool isEmpty();
		void Push(StackType elem);
		StackType Pop();
};

template <typename StackType>
Stack<StackType> :: Stack() {
	
	this->linked_list = new List<StackType>();

};

template <typename StackType>
Stack<StackType> :: ~Stack() {
	
	delete this->linked_list;

};

template <typename StackType>
int Stack<StackType> :: getSize() {
	
	return this->linked_list->getSize();

};

template <typename StackType>
bool Stack<StackType> :: isEmpty() {
	
	return this->linked_list->isEmpty();

};

template <typename StackType>
void Stack<StackType> :: Push(StackType elem) {

	this->linked_list->insertFront( elem );

};

template <typename StackType>
StackType Stack<StackType> :: Pop() {
	
	if(this->isEmpty()){
		throw std::length_error( this->STACK_EMPTY_ERROR);
	} else {
		return this->linked_list->removeFront();
	}
};

#endif


