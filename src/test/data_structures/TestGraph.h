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
	CPPUNIT_TEST (getBFSVerticeNamesTest);
	CPPUNIT_TEST (getDFSVerticeNamesTest);
	CPPUNIT_TEST (operatorOverloadingTest);
	CPPUNIT_TEST_SUITE_END ();

	public:
		void setUp (void);
		void tearDown (void);

	protected:
		void addVerticeTest (void);	
		void addEdgeTest (void);
		void getBFSVerticeNamesTest (void);
		void getDFSVerticeNamesTest (void);
		void operatorOverloadingTest (void);

	private:
		Graph * graph;
		
		std :: string const TEST_FILE = "./src/test/data/Romania.txt";
		int number_of_edges;
		int number_of_vertices;
		std :: string bfs_test_output;
		std :: string dfs_test_output;
};
#endif
