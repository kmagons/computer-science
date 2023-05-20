#include "List.h"

class GraphEdge {

	private:

		int from;
		int to;
		int cost;
	
	public:

		GraphEdge(int from, int to, int cost );
		GraphEdge();
		int getCost();
		int getFrom();
		int getTo();


};


class GraphVertice {
		private:
		
		int id;
		std :: string name;
		List<GraphEdge> * adjacency_list;		

	public:

		GraphVertice(int id, std :: string name);
		~GraphVertice();
		std :: string getName();
		List<GraphEdge> * getNeighbors();
		void addNeighbor(GraphVertice * adj, int cost);
		int getId();
};

class Graph {

	private:

		int number_of_vertices;
		GraphVertice ** adjacency_list;

	public:
		
		Graph(int number_of_vertices);
		~Graph();
		void addEdge(int v, int w, int cost);
		void addVertice(int v, std :: string name);
		void printBFS(int root);
		void printDFS(int root);
		int getVerticeCount();
};
