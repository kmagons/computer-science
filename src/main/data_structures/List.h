#ifndef LIST_H
#define LIST_H

#include "ListNode.h"
#include <iostream>

template <typename ListType>

class List {

	private:

		ListNode<ListType> * head;
		ListNode<ListType> * tail;
		int list_lenght;
		ListNode<ListType> * createListNode(ListType data, ListNode<ListType> * prev, ListNode<ListType> * next);
		void removeElem(ListNode<ListType> * elem);
		void insertAfterNode(ListNode<ListType> * prev, ListType data);

	public:
		List();
		~List();
		bool isEmpty();
		int getSize();
		void insertBack(ListType data);
		void insertFront(ListType data);
		void insertAfter(ListType data, ListType new_data);
		void insertAccordingToPriority(ListType data);
		void deleteList();
		ListType removeFront();
		ListType removeBack();
		ListType * copyListToArray(ListType * arr, int size);
		ListNode<ListType> * getHead();
		ListNode<ListType> * getTail();
};

template <typename ListType>
List<ListType> :: List() {
	this->head = NULL;
	this->tail = NULL;
	this->list_lenght = 0;

}

template <typename ListType>
List<ListType> :: ~List() {
	this->deleteList();
	this->head = NULL;
	this->tail = NULL;
}

template <typename ListType>
bool List<ListType> ::  isEmpty() {
	return this->head == NULL;
};

template <typename ListType>
int  List<ListType> ::  getSize(){
	return this->list_lenght;
}

template <typename ListType>	
void List<ListType> :: insertFront(ListType data) {
		
	ListNode<ListType> * new_list_node = this->createListNode(data, NULL, this->head);
			
	if(this->isEmpty()){
		this->tail = new_list_node;
				
	} else {

		this->head->setPrev(new_list_node);
	}

	this->head = new_list_node;	

};


template <typename ListType>	
void  List<ListType> ::  insertBack(ListType data) {

	ListNode<ListType> * new_list_node = this->createListNode(data, this->tail,NULL);

	if(this->isEmpty()){
		this->head = new_list_node;
	} else {

		this->tail->setNext(new_list_node);
	}

	this->tail = new_list_node;	
}

template <typename ListType>	
void  List<ListType> ::  insertAfter(ListType data, ListType new_data){

	ListNode<ListType> * current = this->head;
			
	while(current && current.getData() != data){
		current = current->next();
	}

	this->insertAfterNode(current, new_data);
};


template <typename ListType>	
void  List<ListType> ::  insertAccordingToPriority(ListType data){

	if(this->isEmpty() || this->head->getData() < data){
		this->insertFront(data);
		return;
	}
			
	if(this->tail->getData() >= data ){
		this->insertBack(data);
		return;
	}
			
	ListNode<ListType> * current = this->head;
		
	while( current && current->next() && current->next()->getData() > data ){
		current = current->next();
	}

	this->insertAfterNode(current, data);
}; 

template <typename ListType>	
void  List<ListType> ::  deleteList(){
	
	ListNode<ListType> * current = this->head;
	while(current){
		this->removeElem(current);
		current = current->next();
	}

};

template <typename ListType>		
ListType List<ListType> ::  removeFront() {
			
	ListType data;
			
	if(this->head){
		data = this->head->getData();
		this->removeElem(this->head);
	}

	return data;

};

template <typename ListType>	
ListType List<ListType> ::   removeBack(){

	ListType data;
			
	if(this->tail){
		data = this->tail->getData();
		this->removeElem(this->tail);
	}

	return data;
};

template <typename ListType>	
ListType * List<ListType> :: copyListToArray(ListType * arr, int size){
			
	if(size < 1){
		size = this->getSize();
	}

	int pos = 0;
	ListType data;
	ListNode<ListType> * current = this->head;
			
	while(current != NULL && pos < size){
		data = current->getData();
		arr[pos++] = data;
		current = current->next();
	}

	return arr;
};


template <typename ListType>	
ListNode<ListType> * List<ListType> :: createListNode(ListType data, ListNode<ListType> * prev, ListNode<ListType> * next) {
	this->list_lenght++;
	return new ListNode<ListType>(data, prev, next);

};


template <typename ListType>	
void  List<ListType> :: removeElem(ListNode<ListType> * elem) {
			
	if(this->isEmpty() || elem == NULL){

		return;
	}

	ListNode<ListType> * prev = elem->prev();
	ListNode<ListType> * next = elem->next();


	if(this->head == elem){
		this->head = next;
	}

	if(this->tail == elem){
		this->tail = prev;
	}


	if(prev != NULL){
		prev->setNext( next );
	}
			
	if(next != NULL){
		next->setPrev( prev );
	}

			
	this->list_lenght--;

};

template <typename ListType>	
void List<ListType> :: insertAfterNode(ListNode<ListType> * prev, ListType data){

	if(prev == NULL){
		return;
	}

	ListNode<ListType> * new_node = this->createListNode(data, prev, prev->next());
	prev->setNext(new_node );

	if(new_node->next() != NULL){
		new_node->next()->setPrev( new_node );
	}

}

template <typename ListType>	
ListNode<ListType> * List<ListType> :: getHead(){
	return this->head;
}


template <typename ListType>	
ListNode<ListType> * List<ListType> :: getTail(){
	return this->tail;
}

#endif
