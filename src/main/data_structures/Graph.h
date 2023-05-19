#include "List.h"
#include "ListNode.h"

class GraphVertice {
	
	private:
		
		int id;
		std :: string name;
		List<int> * adjacency_list;		

	public:

		GraphVertice(int id, std :: string name);
		~GraphVertice();
		std :: string getName();
		ListNode<int> * getNeighbors();
		void addNeighbor(int id);
};

class GraphEdge {

	private:

		GraphVertice * from;
		GraphVertice * to;
		int cost;
	
	public:

		GraphEdge(GraphVertice * from, GraphVertice * to, int cost );
		int getCost();
		GraphVertice * getFrom();
		GraphVertice * getTo();


};

class Graph {

	private:

		int number_of_vertices;
		List<GraphVertice> * adjacency_list;

	public:
		
		Graph(int number_of_vertices);
		~Graph();
		void addEdge(int v, int w, int cost);
		void addVertice(int v, std :: string name) throw (std :: length_error);
		void printBFS(int root);
		void printDFS(int root);
		int getVerticeCount();
};
