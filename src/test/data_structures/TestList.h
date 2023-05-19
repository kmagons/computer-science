#ifndef TESTLIST_H
#define TESTLIST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../../main/data_structures/List.h"

using namespace std;

class testlist : public CPPUNIT_NS :: TestFixture
{
	CPPUNIT_TEST_SUITE (testlist);
	CPPUNIT_TEST (constructorTest);	
	CPPUNIT_TEST (insertFrontTest);
	CPPUNIT_TEST (insertBackTest);
	CPPUNIT_TEST (removeFrontTest);
	CPPUNIT_TEST (removeBackTest);
	CPPUNIT_TEST (deleteListTest);
	CPPUNIT_TEST (copyToArrayTest);
	CPPUNIT_TEST (insertAccordingToPriorityTest);
	CPPUNIT_TEST_SUITE_END ();

	public:
		void setUp (void);
		void tearDown (void);

	protected:
		void constructorTest (void);
		void insertFrontTest (void);
		void insertBackTest (void);
		void removeFrontTest (void);
		void removeBackTest( void );
		void deleteListTest( void );
		void copyToArrayTest( void );
		void insertAccordingToPriorityTest( void );
		

	private:
		List <int> * list;
		const int INSERTION_ITERATIONS = 10000;
};
#endif
