#include "TestStack.h"

CPPUNIT_TEST_SUITE_REGISTRATION (teststack);

void teststack :: setUp (void)
{
	this->stack = new Stack<int> ();
}

void teststack :: tearDown (void) 
{
	delete this->stack;
}


void teststack :: pushTest (void)
{

	for(int i = 0; i < this->INSERTION_ITERATIONS; i++){
		this->stack->Push( i );
		CPPUNIT_ASSERT_EQUAL (i + 1, this->stack->getSize());
	}

	CPPUNIT_ASSERT_EQUAL (this->INSERTION_ITERATIONS - 1, this->stack->Pop() );
}


void teststack :: popTest (void)
{
	
	CPPUNIT_ASSERT_THROW(this->stack->Pop(), std :: length_error);
	for(int i = 0; i < this->INSERTION_ITERATIONS; i++){
		this->stack->Push( i );
	}

	for(int i = this->INSERTION_ITERATIONS - 1; i >= 0; i--){
	
		CPPUNIT_ASSERT_EQUAL (i, this->stack->Pop());
	}

	CPPUNIT_ASSERT_EQUAL (0, this->stack->getSize());

}


