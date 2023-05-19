#include "TestMinPriorityQueue.h"
#include <algorithm>

CPPUNIT_TEST_SUITE_REGISTRATION (testminpriorityqueue);

void testminpriorityqueue :: setUp (void)
{
	this->queue = new MinPriorityQueue<int> ();
}

void testminpriorityqueue :: tearDown (void) 
{
	delete this->queue;
}


void testminpriorityqueue :: enqueueTest (void)
{

	int test_arr[this->INSERTION_ITERATIONS];

	for(int i = 0; i < this->INSERTION_ITERATIONS; i++){
		test_arr[i] = rand() % this->INSERTION_ITERATIONS;
		this->queue->Enqueue( test_arr[i] );
	}

	std :: sort(test_arr, test_arr + this->INSERTION_ITERATIONS);

	for(int i = 0; i < this->INSERTION_ITERATIONS; i++){ 
	
		CPPUNIT_ASSERT_EQUAL (test_arr[i], this->queue->Dequeue());
	}
}



