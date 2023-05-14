#include <iostream>
using namespace std;

template <typename T>

class List {

	private:
		
		struct ListNode {
			T data;
			ListNode * next_node;
			ListNode * prev_node;
			
			ListNode(T data, ListNode * prev, ListNode * next){
				this->data = data;
				this->next_node = next;
				this->prev_node = prev;
			}

		};

		ListNode * head;
		ListNode * tail;
		int list_lenght;
		
		ListNode * createListNode(T data, ListNode * prev = NULL, ListNode * next = NULL) {
			this->list_lenght++;

			return new ListNode(data, prev, next);
	
		};

		void removeElem(ListNode * elem) {
			
			if(this->isEmpty() || elem == NULL){
				//Nothing to delete;
				return;
			}

			ListNode * prev = elem->prev_node;
			ListNode * next = elem->next_node;
			
			if(prev != NULL){
				prev->next_node = elem->next_node;
			}
			
			if(next != NULL){
				next->prev_node = elem->prev_node;
			}

			delete elem;
			
			this->list_lenght--;

		};

		void insertAfterNode(ListNode * prev, T data){

			if(prev == NULL){
				return;
			}

			ListNode * new_node = this->createListNode(data);
			new_node->next_node = prev->next_node;
			new_node->prev_node = prev;
			prev->next_node = new_node;

			if(new_node->next_node != NULL){
				new_node->next_node->prev_node = new_node;
			}

		}

	public:

		List() {
			this->head = NULL;
			this->tail = NULL;
			this->list_lenght = 0;
		};
		
		~List() {
			this->deleteList();
		};

		bool isEmpty() {
			return this->head == NULL;
		};

		int getSize(){
			return this->list_lenght;
		}
		
		void insertFront(T data) {
		
			ListNode * new_list_node = this->createListNode(data, this->head, NULL);
			
			if(this->isEmpty()){
				this->tail = new_list_node;
				
			}else{

				this->head->prev_node = new_list_node;
			}

			this->head = new_list_node;	

		};

		void insertBack(T data) {

			ListNode * new_list_node = this->createListNode(data, NULL, this->tail);

			if(this->isEmpty()){
				this->head = new_list_node;
			} else {

				this->tail->next_node = new_list_node;
			}

			this->tail = new_list_node;	
		};




		void insertAfter(T data, T new_data){

			ListNode * current = this->head;
			
			while(current && current->data != data){
				current = current->next_node;
			}

			this->insertAfterNode(current, new_data);
		};

		void insertAccordingPriority(T data){

			if(this->isEmpty() || this->head->data < data){
				this->insertFront(data);
				return;
			}
			
			if(this->tail->data >= data ){
				this->insertBack(data);
				return;
			}
			
			ListNode * current = this->head;
		
			while( current && current->next_node && current->next_node->data > data ){
				current = current->next_node;
			}


			this->insertAfterNode(current, data);
		}; 


		void deleteList(){
	
			ListNode * current = this->head;
			while(current){
				this->removeElem(current);
				current = current->next_node;
			}

		};
		
 		T removeFront() {
			
			T data;
			
			if(this->head){
				data = this->head->data;
				this->removeElem(this->head);
			}

			return data;

		};

		T removeBack(){

			T data;
			
			if(this->tail){
				data = this->tail->data;
				this->removeElem(this->tail);
			}

			return data;
		};

		T * copyListToArray(T * arr, int size = 0){
			
			if(size < 1){
				size = this->getSize();
			}

			int pos = 0;
			T data;
			ListNode * current = this->head;
			
			while(current != NULL && pos < size){
				data = current->data;
				arr[pos++] = data;
				current = current->next_node;
			}

			return arr;
		}
};

