#include "TestList.h"
#include <algorithm>

CPPUNIT_TEST_SUITE_REGISTRATION (testlist);

void testlist :: setUp (void)
{
	this->list = new List<int> ();
}

void testlist :: tearDown (void) 
{
	delete this->list;
}

void testlist :: constructorTest (void)
{
	CPPUNIT_ASSERT_EQUAL (0, list->getSize());
}


void testlist :: insertFrontTest (void)
{

	for(int i = 0; i < this->INSERTION_ITERATIONS; i++){
		this->list->insertFront( i );
		CPPUNIT_ASSERT_EQUAL (i + 1, this->list->getSize());
	}

	CPPUNIT_ASSERT_EQUAL (this->INSERTION_ITERATIONS - 1, this->list->removeFront());

}


void testlist :: insertBackTest (void)
{
	for(int i = 0; i < this->INSERTION_ITERATIONS; i++){
		this->list->insertBack( i );
		CPPUNIT_ASSERT_EQUAL (i + 1, this->list->getSize());
	}

	CPPUNIT_ASSERT_EQUAL (0, this->list->removeFront());
}


void testlist :: removeFrontTest (void)
{

	for(int i = 0; i < this->INSERTION_ITERATIONS; i++){
		this->list->insertFront( i );
	}

	for(int i = this->INSERTION_ITERATIONS - 1; i >= 0; i--){
		CPPUNIT_ASSERT_EQUAL (i, this->list->removeFront());	
		CPPUNIT_ASSERT_EQUAL (i, this->list->getSize());
	}

}


void testlist :: removeBackTest (void)
{
	for(int i = 0; i < this->INSERTION_ITERATIONS; i++){
		this->list->insertBack( i );
	}

	for(int i = this->INSERTION_ITERATIONS - 1; i >= 0; i--){
		CPPUNIT_ASSERT_EQUAL (i, this->list->removeBack());	
		CPPUNIT_ASSERT_EQUAL (i, this->list->getSize());
	}
}

void testlist :: deleteListTest (void)

{
	for(int i = 0; i < this->INSERTION_ITERATIONS; i++){
		
		if(i % 2 == 0){
			this->list->insertBack( i );
		}else{
			
			this->list->insertFront( i );
		}
	}

	list->deleteList();

	CPPUNIT_ASSERT_EQUAL (0, this->list->getSize());	
	CPPUNIT_ASSERT_EQUAL (true, this->list->isEmpty());

}


void testlist :: copyToArrayTest (void)
{

	int test_arr[this->INSERTION_ITERATIONS];
	for(int i = 0; i < this->INSERTION_ITERATIONS; i++){
		
		this->list->insertBack( i );
	}

	this->list->copyListToArray(test_arr, this->INSERTION_ITERATIONS);

	for(int i = this->INSERTION_ITERATIONS - 1; i >= 0; i--){


		CPPUNIT_ASSERT_EQUAL (i, test_arr[i]);
		CPPUNIT_ASSERT_EQUAL (this->list->removeBack(), test_arr[i]);

	}


}


void testlist :: insertAccordingToPriorityTest(void)
{

	int test_arr[this->INSERTION_ITERATIONS];
	int res_arr[this->INSERTION_ITERATIONS];
	
	for(int i = 0; i < this->INSERTION_ITERATIONS; i++){
		test_arr[i] = rand() % this->INSERTION_ITERATIONS;
		this->list->insertAccordingToPriority( test_arr[i] );
	}
	
	 std :: sort(test_arr, test_arr + this->INSERTION_ITERATIONS);
	this->list->copyListToArray(res_arr, this->INSERTION_ITERATIONS);
	
	for(int i = 0; i < this->INSERTION_ITERATIONS; i++){ 
	
		CPPUNIT_ASSERT_EQUAL (test_arr[i], res_arr[this->INSERTION_ITERATIONS - i - 1]);
	
		CPPUNIT_ASSERT_EQUAL (test_arr[i], this->list->removeBack());
	}

}
