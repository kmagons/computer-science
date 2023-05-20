#ifndef LISTNODE_H
#define LISTNODE_H

template <typename ListNodeType>

class ListNode {

	private:

		ListNodeType data;
		ListNode * next_node;
		ListNode * prev_node;

	public:

		ListNode(ListNodeType data, ListNode * prev, ListNode * next);
		ListNode * next();
		ListNode * prev();
		ListNodeType  getData();
		void setNext(ListNode<ListNodeType> * next);
		void setPrev(ListNode<ListNodeType> * prev);
		
};

template <typename ListNodeType>
ListNode<ListNodeType> :: ListNode(ListNodeType data, ListNode * prev, ListNode * next){

	this->data = data;
	this->next_node = next;
	this->prev_node = prev;
	
};

template <typename ListNodeType>
ListNode<ListNodeType> * ListNode<ListNodeType> :: next () {

	return this->next_node;

};

template <typename ListNodeType>
ListNode<ListNodeType> * ListNode<ListNodeType> :: prev () {

	return this->prev_node;

};

template <typename ListNodeType>
ListNodeType ListNode<ListNodeType> :: getData () {

	return this->data;

};

template <typename ListNodeType>
void ListNode<ListNodeType> :: setNext (ListNode<ListNodeType> * next) {

	this->next_node = next;

};

template <typename ListNodeType>
void ListNode<ListNodeType> :: setPrev (ListNode<ListNodeType> * prev) {

	this->prev_node = prev;

};

#endif
