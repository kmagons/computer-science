#ifndef TESTQUEUE_H
#define TESTQUEUE_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../../main/data_structures/MinPriorityQueue.h"

using namespace std;

class testminpriorityqueue : public CPPUNIT_NS :: TestFixture
{
	CPPUNIT_TEST_SUITE (testminpriorityqueue);
	CPPUNIT_TEST (enqueueTest);
	CPPUNIT_TEST_SUITE_END ();

	public:
		void setUp (void);
		void tearDown (void);

	protected:
		void enqueueTest (void);	

	private:
		MinPriorityQueue <int> * queue;
		const int INSERTION_ITERATIONS = 10000;
};
#endif
