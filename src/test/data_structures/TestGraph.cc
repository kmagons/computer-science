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
	std :: string bfs_output, bfs_line = "";

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
				file >> bfs_line;
				bfs_output += bfs_line + '\n';
		}

	this->number_of_vertices = number_of_vertices;
	this->number_of_edges = number_of_edges; 
	this->bfs_test_output = bfs_output;

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
