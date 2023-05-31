#ifndef GRAPH_FILE_READER_H
#define GRAPH_FILE_READER_H
#include "GraphFileReader.h"

GraphFileReader :: GraphFileReader (std :: string file_name) {

	std :: fstream file;
	int v, w, distance;
	std :: string cityName;
	int cityID;
	std :: string line = "";
	file.open(file_name);

	if(file.is_open()){
		file >> this->number_of_vertices >> this->number_of_edges;
		

		this->graph = new Graph ( this->number_of_vertices );

		
		for(int i = 0; i < this->number_of_vertices; i++){
			file >> cityID >> cityName;
			this->graph->addVertice(cityID, cityName);

		}

		for(int i = 0; i < this->number_of_edges; i++){
				file >> v >> w >> distance;
				this->graph->addEdge(v, w, distance);
				this->graph->addEdge(w, v, distance);
		}

		
		for(int i = 0; i < this->number_of_vertices; i++){
				file >> line;
				this->bfs_output += line + '\n';
		}

		for(int i = 0; i < number_of_vertices; i++){
				file >> line;
				this->dfs_output += line + '\n';
		}
 	

		file.close();
	}

};


Graph * GraphFileReader :: getGraph() {
	return this->graph;
};

std :: string GraphFileReader :: getBFSOutput(){
	return this->bfs_output;
};

std :: string GraphFileReader :: getDFSOutput(){
	return this->dfs_output;
};

GraphFileReader :: ~GraphFileReader(){
	delete this->graph;
};

int GraphFileReader :: getVerticeCount() {
	return this->number_of_vertices;
};

int GraphFileReader :: getEdgeCount() {
	return this->number_of_edges;
};

#endif
