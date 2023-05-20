#ifndef TESTGRAPH_H
#define TESTGRAPH_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../../main/data_structures/Graph.h"

using namespace std;

class testgraph : public CPPUNIT_NS :: TestFixture
{
	CPPUNIT_TEST_SUITE (testgraph);
	CPPUNIT_TEST (addVerticeTest);
	CPPUNIT_TEST (addEdgeTest);
	CPPUNIT_TEST_SUITE_END ();

	public:
		void setUp (void);
		void tearDown (void);

	protected:
		void addVerticeTest (void);	
		void addEdgeTest (void);

	private:
		Graph * graph;
		const int VERTICE_COUNT = 10;
};
#endif
