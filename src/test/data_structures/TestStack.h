#ifndef TESTSTACK_H
#define TESTSTACK_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../../main/data_structures/Stack.h"

using namespace std;

class teststack : public CPPUNIT_NS :: TestFixture
{
	CPPUNIT_TEST_SUITE (teststack);
	CPPUNIT_TEST (popTest);
	CPPUNIT_TEST (pushTest);
	CPPUNIT_TEST_SUITE_END ();

	public:
		void setUp (void);
		void tearDown (void);

	protected:
		void popTest (void);
		void pushTest (void);		

	private:
		Stack <int> * stack;
		const int INSERTION_ITERATIONS = 10000;
};
#endif
