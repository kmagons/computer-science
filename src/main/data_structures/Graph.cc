#include "Graph.h"
#include "Queue.h"
#include "Stack.h"

/* GraphVertice implementation */

GraphVertice :: GraphVertice(int id, std :: string name){

	this->adjacency_list = new List<GraphEdge>();
	this->id = id;
	this->name = name;
};

GraphVertice :: ~GraphVertice(){
	delete this->adjacency_list;
};

std :: string  GraphVertice :: getName(){
	return this->name;
};


List<GraphEdge> * GraphVertice :: getNeighbors(){
	
	return this->adjacency_list;

};

void GraphVertice :: addNeighbor(GraphVertice * adj, int cost){
	
	GraphEdge new_graph_edge( this->getId(), adj->getId(), cost);
	//Rework this to use priority queue
	this->adjacency_list->insertBack( new_graph_edge );

};

int GraphVertice :: getId(){
	return this->id;
};

/* GraphEdge implementation */ 

GraphEdge :: GraphEdge(int from, int to, int cost){
	
	this->from = from;
	this->to = to;
	this->cost = cost;
};

GraphEdge :: GraphEdge(){
		//Default consturctor
};

int GraphEdge :: getCost(){
	return this->cost;
};

int GraphEdge :: getFrom(){
	return this->from;
};


int GraphEdge :: getTo(){
	return this->to;
};

/* Graph implementation */

Graph :: Graph(int number_of_vertices) {
	

	this->number_of_vertices = number_of_vertices;
	this->adjacency_list =  new GraphVertice * [number_of_vertices];
	this->number_of_edges = 0;

	for(int i = 0; i < this->number_of_vertices; i++){
	
		this->adjacency_list[i] = NULL;
	}

};



Graph :: ~Graph() {
	
	delete this->adjacency_list;

};

int Graph :: getVerticeCount(){
	
	return this->number_of_vertices;

};

int Graph :: getEdgeCount(){
	
	return this->number_of_edges;

};

void Graph :: addVertice(int v, std :: string name) {

	if(v >= this->getVerticeCount() ){
		throw (std :: invalid_argument("Out of range"));
	}else{

		GraphVertice * new_vertice = new GraphVertice(v, name);
		this->adjacency_list[v] = new_vertice;
	}

};

void Graph :: addEdge(int v, int w, int cost) {

	GraphVertice * a = this->adjacency_list[v];
	GraphVertice * b = this->adjacency_list[w];
	
	if(a == NULL || b == NULL){
		throw (std :: invalid_argument("No valid vertices for the new edge"));
	} else {

		a->addNeighbor(b, cost);
		this->number_of_edges++;
	}
};

std :: string Graph :: getVerticeNamesBFS(int root) {

	GraphVertice * r = this->adjacency_list[root];
	if ( r == NULL){
		throw ( std :: invalid_argument("Root node not found"));
	}

	bool visited[this->getVerticeCount()];
	Graph :: initializeSearchMemory(this->getVerticeCount(), visited, false); 
	Queue<GraphVertice*> frontier;
	frontier.Enqueue(r);
	GraphVertice * current;
	GraphVertice * next;
	List<GraphEdge> * edge_list;
	ListNode<GraphEdge> * current_edge;
	int neighbor_id;
	std :: string levels[this->getVerticeCount()];
	std :: string output;
	levels[root] = "->";

	while(!frontier.isEmpty()){
		
		current = frontier.Dequeue();

		if(!visited[current->getId()]){

			output += levels[current->getId()] + current->getName() + '\n';
		
		}

		visited[current->getId()] = true;
		edge_list = current->getNeighbors();
		current_edge = edge_list->getHead();


		while(current_edge != NULL){
			
			neighbor_id = current_edge->getData().getTo();
			
			if(!visited[ neighbor_id ]){

				frontier.Enqueue( this->adjacency_list[ neighbor_id ]  );
				levels[neighbor_id] = "-" + levels[current->getId()];
			}
			current_edge = current_edge->next();
		}

	}
	
	return output;

};


void Graph :: printDFS(int root) {

	GraphVertice * r = this->adjacency_list[root];
	if ( r == NULL){
		throw ( std :: invalid_argument("Root node not found") );
	}

	//DFS implementation pending
};

void Graph :: initializeSearchMemory(int size, bool * visited, bool value){
	
	for(int i = 0; i < size; i++) {

		visited[i] = value;
	}

};
