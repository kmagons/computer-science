/**
 *	 This program implements a simple generic type data bidirectional linked list data structure and its basic algorithms to support usage in more complex data structures
 *	 Author: Krists Magons
 *	 Date: 20.05.2023
 *	
 */
#ifndef LIST_H
#define LIST_H

#include "ListNode.h"
#include <iostream>

template <typename ListType>

class List {

	private:


		/**
		 * Pointer to the head node of the linked list
		 */
		ListNode<ListType> * head;
		
		/**
 		* Pointer to the last element in the linked list
 		*/
		ListNode<ListType> * tail;

		/**
		 * Stores the current number of elements in the linked list
		 */
		int list_lenght;

		/**
		 * Utility function to create a new node
		 *
		 * 	Time complexity: O(Const)
		 *
		 * @param data to be associated with the new node
		 * @param prev - pointer to the previous node in the list
		 * @param next - pointer to the next node in the list
		 * @returns a pointer to the new node
		 */
		ListNode<ListType> * createListNode(ListType data, ListNode<ListType> * prev, ListNode<ListType> * next);
		
		/**
		 * Utility function to remove an existing node
		 *
		 * 	Time complexity: O(Const)
		 *
		 * @param elem - pointer to the node to be removed from the linked list
		 */
		void removeElem(ListNode<ListType> * elem);


		/**
		 * Utility function to insert a new node after the given existing node
		 *
		 * 	Time complexity: O(Const)
		 *
		 * @param elem - pointer to the existing node after which a new node must be inserted
		 * @param data, data to be associated with the new node
		 */
		
		void insertAfterNode(ListNode<ListType> * prev, ListType data);

	public:

		/**
		 * Default constructor
		 */
		List();

		/**
		 *	Default destructor
		 */
		~List();

		/**
		 *	Time complexity: O(Const)
		 *
		 *	@returns true if the linked list is not empty (the head pointer is not NULL), otherwise false
		 */
		bool isEmpty();

		/**
		 *
		 * Time complexity: O(Const)
		 *	@returns the number of elements in the linked list
		 */
		int getSize();

		/**
		 *	Method creates and inserts a new node of <data> at the end of the linked list and replaces the tail element pointer
		 *
		 *	Time complexity: O(Const)
		 *
		 *	@param data, data to be associated with the new node
		 *
		 */
		void insertBack(ListType data);
		
		/**
		 *	Method creates and inserts a new node of <data> in front of the linked list and replaces the head element pointer
		 *
		 *	Time complexity: O(Const)
		 *
		 *	@param data, data to be associated with the new node
		 *
		 */
		void insertFront(ListType data); 
		
		/**
		 *	Method creates and inserts a new node of <new_data> after the first occurence of an existing node of <data>
		 *
		 *	Time complexity: O(n), n - size of the list
		 *
		 * 	@param data, data of a list element after which the new node should be added
		 *	@param new_data, data to be associated with the new node
		 *
		 */
		void insertAfter(ListType data, ListType new_data);

		/**
		 *	Method deletes the first node matching node which references <data>>
		 *
		 *	Time complexity: O(n), n - size of the list
		 *
		 * 	@param data, data of a list element which should be delete
		 *
		 */
		void deleteElem(ListType data);

		/**
		 *	Method creates and inserts a new node of <data> after the first occurence of an existing node of <data_existing> which compares "smaller" of <data>
		 *	Elements having equal <data> comparisons are sorted accoding to insertion time
		 *
		 *	Worst case time complexity: O(n - 1), n - size of the list (new_data is compared against the first and the last node in constant time)
		 *
		 * 	@param data, data of a list element after which the new node should be added
		 *
		 */
		void insertAccordingToPriority(ListType data);
		
		/**
		 *	Method deletes all the elements in the linked list and sets the head and tail pointers to NULL
		 *
		 *	Time complexity: O(n), n - size of the list
		 */
		void deleteList();
		

		/**
		 *	Methods removes the first element from the linked list, deletes the element and returs the assocated <data>
		 *	Time complexity: O(Const)
		 *	@returns, <data> associated with the removed list element
		 */
		ListType removeFront();
		
		/**
		 *	Methods removes the last element from the linked list, deletes the element and returs the assocated <data>
		 *	Time complexity: O(Const)
		 *	@returns, <data> associated with the removed list element
		 */
		ListType removeBack();

		/**
		 *	Method traverses the linked list from head to tail and copies <data> for each element to the given array <arr> of <size>
		 *
		 *	Time complexity: O(n), where n = size
		 *
		 *	@returns pointer to the array containing the copied <data> values
		 */
		ListType * copyListToArray(ListType * arr, int size);

		/**
		 * Time complexity: O(Const)
		 * @returns pointer to the head element
		 */
		ListNode<ListType> * getHead();
		
		/**
		 * Time complexity: O(Const)
		 * @returns pointer to the tail element
		 */
		ListNode<ListType> * getTail();
};

template <typename ListType>
List<ListType> :: List() {
	this->head = NULL;
	this->tail = NULL;
	this->list_lenght = 0;

};

template <typename ListType>
List<ListType> :: ~List() {
	this->deleteList();
};

template <typename ListType>
bool List<ListType> ::  isEmpty() {
	return this->head == NULL;
};

template <typename ListType>
int  List<ListType> ::  getSize(){
	return this->list_lenght;
};

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
};

template <typename ListType>	
void  List<ListType> ::  insertAfter(ListType data, ListType new_data){

	ListNode<ListType> * current = this->head;
			
	while(current && current.getData() != data){
		current = current->next();
	}

	
	if(current != NULL){
		this->insertAfterNode(current, new_data);
	}else{
		this->insertBack(new_data);
	}

};


template <typename ListType>	
void  List<ListType> ::  deleteElem(ListType data){

	ListNode<ListType> * current = this->head;
			
	while(current && current->getData() != data){
		current = current->next();
	}
	
	if(current != NULL){
		
		this->removeElem(current);

	}

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

	this->head = NULL;
	this->tail = NULL;

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

};

template <typename ListType>	
ListNode<ListType> * List<ListType> :: getHead(){
	return this->head;
};


template <typename ListType>	
ListNode<ListType> * List<ListType> :: getTail(){
	return this->tail;
};

#endif
