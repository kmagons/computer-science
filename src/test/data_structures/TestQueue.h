#ifndef TESTQUEUE_H
#define TESTQUEUE_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../../main/data_structures/Queue.h"

using namespace std;

class testqueue : public CPPUNIT_NS :: TestFixture
{
	CPPUNIT_TEST_SUITE (testqueue);
	CPPUNIT_TEST (enqueueTest);
	CPPUNIT_TEST (dequeueTest);
	CPPUNIT_TEST_SUITE_END ();

	public:
		void setUp (void);
		void tearDown (void);

	protected:
		void enqueueTest (void);
		void dequeueTest (void);		

	private:
		Queue <int> * queue;
		const int INSERTION_ITERATIONS = 10000;
};
#endif
