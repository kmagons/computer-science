#include "TestQueue.h"
#include <algorithm>

CPPUNIT_TEST_SUITE_REGISTRATION (testqueue);

void testqueue :: setUp (void)
{
	this->queue = new Queue<int> ();
}

void testqueue :: tearDown (void) 
{
	delete this->queue;
}


void testqueue :: enqueueTest (void)
{

	for(int i = 0; i < this->INSERTION_ITERATIONS; i++){
		this->queue->Enqueue( i );
		CPPUNIT_ASSERT_EQUAL (i + 1, this->queue->getSize());
	}

	CPPUNIT_ASSERT_EQUAL (0, this->queue->Dequeue());
}


void testqueue :: dequeueTest (void)
{
	
	CPPUNIT_ASSERT_THROW(this->queue->Dequeue(), std :: length_error);
	for(int i = 0; i < this->INSERTION_ITERATIONS; i++){
		this->queue->Enqueue( i );
	}

	for(int i = 0; i < this->INSERTION_ITERATIONS; i++){
	
		CPPUNIT_ASSERT_EQUAL (i, this->queue->Dequeue());
	}

	CPPUNIT_ASSERT_EQUAL (0, this->queue->getSize());

}


