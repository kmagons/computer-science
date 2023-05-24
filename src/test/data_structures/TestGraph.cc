#include "TestGraph.h"
#include <fstream>

CPPUNIT_TEST_SUITE_REGISTRATION (testgraph);

void testgraph :: setUp (void)
{
	fstream file;
	int number_of_vertices;
	int number_of_edges;
	int v, w, distance;
	std :: string cityName;
	int cityID;
	std :: string bfs_output, dfs_output, line = "";

	file.open(this->TEST_FILE);

	if(file.is_open()){
		file >> number_of_vertices >> number_of_edges;

		this->graph = new Graph ( number_of_vertices );


		for(int i = 0; i < number_of_vertices; i++){
			file >> cityID >> cityName;
			this->graph->addVertice(cityID, cityName);

		}

		for(int i = 0; i < number_of_edges; i++){
				file >> v >> w >> distance;
				this->graph->addEdge(v, w, distance);
				this->graph->addEdge(w, v, distance);
		}

		
		for(int i = 0; i < number_of_vertices; i++){
				file >> line;
				bfs_output += line + '\n';
		}

		for(int i = 0; i < number_of_vertices; i++){
				file >> line;
				dfs_output += line + '\n';
		}

		this->number_of_vertices = number_of_vertices;
		this->number_of_edges = number_of_edges; 
		this->bfs_test_output = bfs_output;
		this->dfs_test_output = dfs_output;
		file.close();
	}
}

void testgraph :: tearDown (void) 
{
	delete this->graph;
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
	CPPUNIT_ASSERT_EQUAL(true, c <= b);

}

