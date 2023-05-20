#include "TestGraph.h"

CPPUNIT_TEST_SUITE_REGISTRATION (testgraph);

void testgraph :: setUp (void)
{
	this->graph = new Graph ( this-> VERTICE_COUNT);
}

void testgraph :: tearDown (void) 
{
	delete this->graph;
}


void testgraph :: addVerticeTest (void)
{

}


void testgraph :: addEdgeTest (void)
{

}


