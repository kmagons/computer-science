#include "Queue.h"

template <typename QueueType>
class MinPriorityQueue: public Queue<QueueType> {

	public: 
		void Enqueue(QueueType elem);
		QueueType Dequeue();
};

template <typename QueueType>
void MinPriorityQueue<QueueType> :: Enqueue(QueueType elem) {

	this->linked_list->insertAccordingToPriority( elem );

};

template <typename QueueType>
QueueType MinPriorityQueue<QueueType> :: Dequeue() {

	return this->linked_list->removeBack();

};

