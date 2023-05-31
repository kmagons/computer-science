#include "TestGraph.h"

CPPUNIT_TEST_SUITE_REGISTRATION (testgraph);

void testgraph :: setUp (void)
{

	this->graph_file = new GraphFileReader(this->TEST_FILE);
	this->graph = graph_file->getGraph();
	this->number_of_vertices = graph_file->getVerticeCount();
	this->number_of_edges = graph_file->getEdgeCount(); 
	this->bfs_test_output = graph_file->getBFSOutput();
	this->dfs_test_output = graph_file->getDFSOutput();
	
}

void testgraph :: tearDown (void) 
{
	delete this->graph_file;
	this->graph = NULL;
}


void testgraph :: addVerticeTest (void)

{
	CPPUNIT_ASSERT_EQUAL (this->number_of_vertices, this->graph->getVerticeCount());
}


void testgraph :: addEdgeTest (void)
{
	
	//This is a directed graph, each edge is added to both directions
	CPPUNIT_ASSERT_EQUAL (this->number_of_edges * 2, this->graph->getEdgeCount());
}

void testgraph :: getBFSVerticeNamesTest (void)
{	
	std :: string output = this->graph->getVerticeNamesBFS( 0 );
	CPPUNIT_ASSERT_EQUAL (this->bfs_test_output, output );
}

void testgraph :: getDFSVerticeNamesTest (void)
{	
	std :: string output = this->graph->getVerticeNamesDFS( 0 );
    CPPUNIT_ASSERT_EQUAL (this->dfs_test_output, output );

}


void testgraph :: operatorOverloadingTest (void)
{	
	
	GraphEdge a(0, 1, 0);
	GraphEdge b(0, 1, 1);
	GraphEdge c(0, 1, 2);
	GraphEdge d(2, 3, 2);

	//Edges are compared to each other according to their path cost value
	CPPUNIT_ASSERT_EQUAL(true, a == a);
	CPPUNIT_ASSERT_EQUAL(false, a == b);
	CPPUNIT_ASSERT_EQUAL(true, c == d);
	CPPUNIT_ASSERT_EQUAL(true, a != b);
	CPPUNIT_ASSERT_EQUAL(true, c > b);
	CPPUNIT_ASSERT_EQUAL(true, c >= d);
	CPPUNIT_ASSERT_EQUAL(true, a < b);
	CPPUNIT_ASSERT_EQUAL(true, d > b);
	CPPUNIT_ASSERT_EQUAL(true, b <= c);

}

void testgraph :: getCostTest (void)
{	
	
	CPPUNIT_ASSERT_EQUAL(151, this->graph->getCost(0, 7));
	CPPUNIT_ASSERT_EQUAL(211, this->graph->getCost(10, 12));
	CPPUNIT_ASSERT_EQUAL(211, this->graph->getCost(12, 10));
	CPPUNIT_ASSERT_EQUAL(90, this->graph->getCost(12, 13));
	CPPUNIT_ASSERT_EQUAL(87, this->graph->getCost(14, 15));
	CPPUNIT_ASSERT_EQUAL(80, this->graph->getCost(8, 7));
	CPPUNIT_ASSERT_EQUAL(111, this->graph->getCost(3, 4));

}
