#ifndef QUEUE_H
#define QUEUE_H

#include "List.h"
#include <iostream>

template <typename QueueType>

class Queue {

	protected:
	
		List<QueueType> * linked_list;
		const std :: string QUEUE_EMPTY_ERROR = "The queue is empty, nothing to dequeue";

	public:
		
		Queue();
		~Queue();
		int getSize();
		bool isEmpty();
		void Enqueue(QueueType elem);
		QueueType Dequeue() throw ( std::length_error ) ;
};



template <typename QueueType>
Queue<QueueType> :: Queue() {
	
	this->linked_list = new List<QueueType>();

};

template <typename QueueType>
Queue<QueueType> :: ~Queue() {
	
	delete this->linked_list;

};

template <typename QueueType>
int Queue<QueueType> :: getSize() {
	
	return this->linked_list->getSize();

};

template <typename QueueType>
bool Queue<QueueType> :: isEmpty() {
	
	return this->linked_list->isEmpty();

};

template <typename QueueType>
void Queue<QueueType> :: Enqueue(QueueType elem) {

	this->linked_list->insertBack( elem );

};

template <typename QueueType>
QueueType Queue<QueueType> :: Dequeue() throw ( std::length_error )  {
	
	if(this->isEmpty()){
		throw std::length_error( this->QUEUE_EMPTY_ERROR);
	} else {
		return this->linked_list->removeFront();
	}
	
};

#endif


