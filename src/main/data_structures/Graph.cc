#include "Graph.h"

GraphVertice :: GraphVertice(int id, std :: string name){

	this->adjacency_list = new List<int>();
	this->id = id;
	this->name = name;
};

GraphVertice :: ~GraphVertice(){
	delete this->adjacency_list;
};

std :: string  GraphVertice :: getName(){
	return this->name;
};


ListNode<int> * GraphVertice :: getNeighbors(){
	
	return this->adjacency_list->getHead();

};

void GraphVertice :: addNeighbor(int id){
	
	this->adjacency_list->insertBack( id );

};

Graph :: Graph(int number_of_vertices) {
	
	this->number_of_vertices = number_of_vertices;
	this->adjacency_list = new List<GraphVertice>[number_of_vertices];

}

Graph :: ~Graph() {
	
	delete this->adjacency_list;

};

void Graph :: getVerticeCount(){
	
	return this->number_of_vertices;

};

void Graph :: addVertice(int id, std :: string name) throw (std :: length_error) {

	if(id >= this->getVerticeCount() ){
		throw (std :: length_error());
	}else{

		this->adjacency_list[i] = new GraphVertice(id, name);
	}

};
